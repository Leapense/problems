from __future__ import annotations

import os, sys, subprocess, tempfile, time, shlex, re, platform
from pathlib import Path
from typing import Optional, Callable, Sequence, Tuple, List, Dict

import psutil  # make sure the environment has it (pip install psutil)

__all__ = [
    "detect_lang",
    "compile_source",
    "get_run_cmd",
    "run_with_memory",
    "PluginBase",
    "MemoryLimitPlugin",
    "CpuUsagePlugin",
]

# ──────────────────────────────────
# 1. Language detection & compile
# ──────────────────────────────────

def detect_lang(path: str | Path) -> Optional[str]:
    """Return canonical language id based on file extension."""
    ext = Path(path).suffix.lower()
    return {
        ".c": "c",
        ".cpp": "cpp",
        ".cc": "cpp",
        ".cxx": "cpp",
        ".java": "java",
        ".py": "python",
    }.get(ext)


def compile_source(src: str | Path) -> Tuple[str, str, str]:
    """Compile *src* if needed.

    Returns `(lang, run_target, workdir)` where:
      • *lang*        – one of 'c', 'cpp', 'java', 'python'
      • *run_target*  – executable file path, python script path, or java MainClass
      • *workdir*     – directory from which the run command must be executed
    """
    src = str(src)
    lang = detect_lang(src)
    if lang is None:
        raise RuntimeError(f"Unsupported source type: {Path(src).suffix}")

    workdir = str(Path(src).absolute().parent)

    if lang in ("c", "cpp"):
        exe = tempfile.mktemp(prefix="prog_", dir=workdir)
        cmd = [
            "gcc" if lang == "c" else "g++",
            src,
            "-O2",
            "-std=c23" if lang == "c" else "-std=c++26",
            "-Wall",
            "-lm",
            "-pipe",
            "-o",
            exe,
        ]
        res = subprocess.run(cmd, capture_output=True, text=True)
        if res.returncode != 0:
            raise RuntimeError(
                "gcc/g++ compile error\n\n$ "
                + " ".join(map(shlex.quote, cmd))
                + "\n"
                + res.stderr.strip()
            )
        return lang, exe, workdir

    if lang == "java":
        res = subprocess.run(["javac", "-d", workdir, src], capture_output=True, text=True)
        if res.returncode != 0:
            raise RuntimeError(f"javac error\n\n{res.stderr.strip()}")
        main_class = Path(src).stem  # assuming single‑file Main
        return lang, main_class, workdir

    # python — no compilation
    return lang, src, workdir


def get_run_cmd(lang: str, run_target: str) -> List[str]:
    """Return the shell command list to execute *run_target* based on *lang*."""
    if lang == "python":
        return [sys.executable, run_target]
    if lang in ("c", "cpp"):
        return [run_target]
    if lang == "java":
        return ["java", run_target]
    raise RuntimeError(f"Unknown lang '{lang}'")


# ──────────────────────────────────
# 2. Resource‑aware runner
# ──────────────────────────────────

def _linux_vmhwm(pid: int) -> Optional[int]:
    if os.name != "posix":
        return None
    try:
        with open(f"/proc/{pid}/status") as f:
            for line in f:
                if line.startswith("VmHWM:"):
                    kb = int(line.split()[1])
                    return kb * 1024
    except FileNotFoundError:
        pass
    return None


def run_with_memory(
    cmd: Sequence[str],
    stdin_data: str = "",
    *,
    cwd: str | None = None,
    timeout: int = 10,
    plugins: Optional[List["PluginBase"]] = None,
) -> Tuple[int, str, str, float, Dict[str, str]]:
    """Run *cmd* with optional stdin, enforcing *timeout*, sampling plugins.

    Returns `(exit_code, stdout, stderr, elapsed_sec, plugin_result_dict)`.
    """
    plugins = plugins or []
    start_ts = time.time()
    proc: Optional[subprocess.Popen[str]] = None

    try:
        proc = subprocess.Popen(
            list(cmd),
            cwd=cwd,
            text=True,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        ps_proc = psutil.Process(proc.pid)
        for p in plugins:
            p.on_start(ps_proc)

        def sampler():
            try:
                while proc and proc.poll() is None:
                    for p in plugins:
                        p.on_sample()
                    time.sleep(0.05)
            except psutil.Error:
                pass

        import threading

        threading.Thread(target=sampler, daemon=True).start()
        out, err = proc.communicate(stdin_data, timeout=timeout)
    except subprocess.TimeoutExpired:
        if proc:
            proc.kill()
            out, err = proc.communicate()
        err += f"\n\n--- Timeout ({timeout}s) Expired ---"
    except Exception as e:
        return -1, "", str(e), time.time() - start_ts, {}

    elapsed = time.time() - start_ts

    metrics: Dict[str, str] = {}
    for p in plugins:
        metrics.update(p.on_finish())

    return proc.returncode if proc else -1, out, err, elapsed, metrics


# ──────────────────────────────────
# 3. Plugin system
# ──────────────────────────────────
class PluginBase:
    """Interface for run‑time sampling plugins."""

    def on_start(self, proc: psutil.Process):
        pass

    def on_sample(self):
        pass

    def on_finish(self) -> Dict[str, str]:
        return {}


class MemoryLimitPlugin(PluginBase):
    """Kill the process if peak RSS or VmHWM exceeds *limit_bytes*.

    Also reports "Peak RSS" and (on Linux) "Peak VmHWM".
    """

    def __init__(self, limit_bytes: int):
        self.limit = limit_bytes
        self.proc: Optional[psutil.Process] = None
        self.peak_rss = 0
        self.peak_vmhwm = 0
        self._is_linux = os.name == "posix"

    def on_start(self, proc: psutil.Process):
        self.proc = proc
        self.peak_rss = proc.memory_info().rss
        if self._is_linux:
            vm = _linux_vmhwm(proc.pid)
            if vm:
                self.peak_vmhwm = vm

    def on_sample(self):
        if not self.proc or not self.proc.is_running():
            return
        try:
            rss = self.proc.memory_info().rss
            self.peak_rss = max(self.peak_rss, rss)
            vmhwm = _linux_vmhwm(self.proc.pid)
            if vmhwm:
                self.peak_vmhwm = max(self.peak_vmhwm, vmhwm)
            current_peak = self.peak_vmhwm or self.peak_rss
            if self.limit and current_peak > self.limit:
                self.proc.kill()
        except psutil.Error:
            pass

    def on_finish(self):
        if self.proc and self.proc.is_running():
            try:
                rss = self.proc.memory_info().rss
                self.peak_rss = max(self.peak_rss, rss)
                vmhwm = _linux_vmhwm(self.proc.pid)
                if vmhwm:
                    self.peak_vmhwm = max(self.peak_vmhwm, vmhwm)
            except psutil.Error:
                pass
        d = {"Peak RSS": f"{self.peak_rss / 1024 ** 2:.2f} MB"}
        if self._is_linux and self.peak_vmhwm:
            d["Peak VmHWM"] = f"{self.peak_vmhwm / 1024 ** 2:.2f} MB"
        return d


class CpuUsagePlugin(PluginBase):
    """Report average & max CPU usage percentage."""

    def __init__(self):
        self.proc: Optional[psutil.Process] = None
        self.max_pct = 0.0
        self.start_cpu = 0.0
        self.start_wall = 0.0

    def on_start(self, proc: psutil.Process):
        self.proc = proc
        try:
            t = proc.cpu_times()
            self.start_cpu = t.user + t.system
            self.start_wall = time.time()
            proc.cpu_percent(interval=None)  # prime
        except psutil.Error:
            self.proc = None

    def on_sample(self):
        if not self.proc or not self.proc.is_running():
            return
        try:
            pct = self.proc.cpu_percent(interval=None)
            if pct > self.max_pct:
                self.max_pct = pct
        except psutil.Error:
            pass

    def on_finish(self):
        if not self.proc:
            return {}
        end_wall = time.time()
        elapsed = end_wall - self.start_wall
        try:
            t = self.proc.cpu_times()
            total_cpu = (t.user + t.system) - self.start_cpu
            avg_pct = (total_cpu / elapsed * 100) if elapsed > 0 else 0.0
        except psutil.Error:
            avg_pct = 0.0
        return {
            "CPU Avg": f"{avg_pct:.1f}%",
            "CPU Max": f"{self.max_pct:.1f}%",
        }