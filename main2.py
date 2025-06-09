#!/usr/bin/env python3
# 이 실행파일은 main.py에 있는 코드를 참조하여 CLI 기반으로 만든 것입니다.

from __future__ import annotations

import argparse
import os
import platform
import re
import resource
import shlex
import subprocess
import sys
import tempfile
import textwrap
import time
from difflib import unified_diff
from itertools import zip_longest
from pathlib import Path
from typing import Optional

import psutil

def detect_lang(src: str) -> Optional[str]:
    return {
        '.c': 'c',
        '.cpp': 'cpp',
        '.cc': 'cpp',
        '.cxx': 'cpp',
        '.java': 'java',
        '.py': 'python',
    }.get(Path(src).suffix.lower())

def compile_source(src: str) -> tuple[str, str, str]:
    lang = detect_lang(src)
    if not lang:
        raise RuntimeError(f"Unsupported source extension: {src}")

    workdir = str(Path(src).resolve().parent)
    if lang in ('c', 'cpp'):
        exe = tempfile.mktemp(prefix='prog_', dir=workdir)
        cmd = [
            'gcc' if lang == 'c' else 'g++',
            src,
            '-O2',
            '-std=c23' if lang == 'c' else '-std=c++26',
            '-Wall',
            '-pipe',
            '-o',
            exe,
        ]
        res = subprocess.run(cmd, capture_output=True, text=True)
        if res.returncode:
            raise RuntimeError(f"Compilation failed:\n{res.stderr.strip()}")
        return lang, exe, workdir

    if lang == 'java':
        res = subprocess.run(['javac', src], capture_output=True, text=True)
        if res.returncode:
            raise RuntimeError(f"javac error:\n{res.stderr.strip()}")
        cls = Path(src).stem
        return lang, cls, workdir

    return lang, src, workdir

def _linux_vmhwm(pid: int) -> int:
    try:
        with open(f"/proc/{pid}/status") as f:
            for line in f:
                if line.startswith('VmHWM:'):
                    kb = int(line.split()[1])
                    return kb * 1024
    except FileNotFoundError:
        pass
    return 0

def run_with_metrics(cmd: list[str],
                     stdin_data: str,
                     cwd: str | None,
                     timeout: int,
                     mem_limit_bytes: int = 0):
    """Execute *cmd* and return measured results as a dict."""

    start_wall = time.perf_counter()
    proc = subprocess.Popen(
        cmd,
        cwd=cwd,
        text=True,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    ps_proc = psutil.Process(proc.pid)

    peak_rss = ps_proc.memory_info().rss

    def monitor():
        nonlocal peak_rss
        try:
            while proc.poll() is None:
                rss = ps_proc.memory_info().rss
                for ch in ps_proc.children(recursive=True):
                    rss += ch.memory_info().rss
                peak_rss = max(peak_rss, rss)

                if mem_limit_bytes and rss > mem_limit_bytes:
                    proc.kill()
                time.sleep(0.05)
        except psutil.Error:
            pass

    import threading

    threading.Thread(target=monitor, daemon=True).start()

    try:
        out, err = proc.communicate(stdin_data, timeout=timeout)
    except subprocess.TimeoutExpired:
        proc.kill()
        out, err = proc.communicate()

    elapsed = time.perf_counter() - start_wall

    if platform.system() == 'Linux':
        peak_rss = max(peak_rss,
                       _linux_vmhwm(proc.pid),
                       resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss * 1024)

    # CPU averages
    try:
        t = ps_proc.cpu_times()
        cpu_time = t.user + t.system
        cpu_avg_pct = (cpu_time / elapsed * 100) if elapsed else 0.0
    except psutil.Error:
        cpu_avg_pct = 0.0

    return {
        'exit_code': proc.returncode,
        'stdout': out,
        'stderr': err,
        'elapsed': elapsed,
        'peak_rss': peak_rss,
        'cpu_avg_pct': cpu_avg_pct,
    }

_TOKEN_RE = re.compile(r'\{([^{}]+?)\}')


def _line_to_regex(exp: str) -> re.Pattern:
    if exp.startswith('re:'):
        return re.compile(exp[3:])
    parts, pos = [], 0
    for m in _TOKEN_RE.finditer(exp):
        parts.append(re.escape(exp[pos:m.start()]))
        alts = [re.escape(s) for s in m.group(1).split('|')]
        parts.append(f'(?:{"|".join(alts)})')
        pos = m.end()
    parts.append(re.escape(exp[pos:]))
    return re.compile('^' + ''.join(parts) + '$')


def _normalize(s: str) -> str:
    return re.sub(r'\s+', ' ', s.rstrip())


def compare_outputs(expected_path: str, actual: list[str]) -> tuple[bool, str]:
    with open(expected_path, encoding='utf-8') as f:
        expected = [ln.rstrip('\n\r') for ln in f]

    for idx, (e, a) in enumerate(zip_longest(expected, actual), start=1):
        if e is None:
            return False, f'Extra line {idx}: {a}'
        if a is None:
            return False, f'Missing line {idx} (expected: {e})'
        if not _line_to_regex(_normalize(e)).fullmatch(_normalize(a)):
            diff = '\n'.join(
                unified_diff(expected, actual, fromfile='expected', tofile='actual', lineterm='')
            )
            return False, f'Line {idx} mismatch:\n{diff}'
    return True, 'All lines match.'


# ───────────────────────── Static‑analysis helper ──────────────────────────
def do_analysis(src: str):
    """Run *lizard* HTML report right next to the source file."""
    try:
        import lizard  # noqa: F401 — just to check availability
    except ImportError:
        print('[analysis] lizard not found ‑‑› pip install lizard', file=sys.stderr)
        return

    html = Path(src).with_suffix('.lizard.html')
    cmd = ['lizard', '--html', src]
    with html.open('w', encoding='utf-8') as fp:
        res = subprocess.run(cmd, stdout=fp, stderr=subprocess.PIPE, text=True)

    if res.returncode:
        print('[analysis] lizard failed:', res.stderr.strip(), file=sys.stderr)
    else:
        print(f'[analysis] HTML report written to: {html}')


# ────────────────────────────────── CLI ────────────────────────────────────
def parse_args():
    p = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=textwrap.dedent(
            """\
            Compile and run a single source file while collecting runtime metrics.

            The *expected* output file supports:
              • lines beginning with `re:` — raw regular expression
              • `{alt1|alt2}` tokens within a line  —  alternation
            """
        ),
    )
    p.add_argument('source', help='C/C++/Java/Python source file')
    input_grp = p.add_mutually_exclusive_group()
    input_grp.add_argument('-i', '--input', help='File to feed to stdin')
    input_grp.add_argument('--stdin', help='Literal string to feed to stdin')
    p.add_argument('-e', '--expected', help='Expected output file')
    p.add_argument('-t', '--timeout', type=int, default=10, help='Timeout seconds (default 10)')
    p.add_argument('--mem-limit', type=int, default=0, help='Memory limit in MB (0 = no limit)')
    p.add_argument('--analysis', action='store_true', help='Run lizard static analysis afterwards')
    p.add_argument('-v', '--verbose', action='store_true', help='Always show stderr')
    return p.parse_args()


def main():
    args = parse_args()

    # Prepare stdin
    stdin_data = ''
    if args.stdin is not None:
        stdin_data = args.stdin
    elif args.input:
        stdin_data = Path(args.input).read_text(encoding='utf-8')

    # Compile
    lang, exe, cwd = compile_source(args.source)
    cmd = {
        'c': [exe],
        'cpp': [exe],
        'java': ['java', exe],
        'python': ['python3', exe],
    }[lang]

    # Execute & measure
    result = run_with_metrics(
        cmd,
        stdin_data,
        cwd=cwd,
        timeout=args.timeout,
        mem_limit_bytes=args.mem_limit * 1024 ** 2,
    )

    # Basic report
    peak_mb = result['peak_rss'] / 1024 ** 2
    print('===== Runtime summary =====')
    print(f'Exit code : {result["exit_code"]}')
    print(f'Elapsed   : {result["elapsed"] * 1000:.2f} ms')
    print(f'Peak RSS  : {peak_mb:.2f} MB')
    print(f'CPU avg   : {result["cpu_avg_pct"]:.1f} %')

    # Show stderr if non‑empty or verbose
    if result['stderr'].strip() or args.verbose:
        print('----- stderr -----')
        print(result['stderr'].rstrip())

    # Output & optional comparison
    actual_lines = result['stdout'].rstrip('\n').split('\n')
    if args.expected:
        ok, msg = compare_outputs(args.expected, actual_lines)
        print('===== Comparison result =====')
        if ok:
            print('✅ PASS —', msg)
        else:
            print('❌ FAIL —', msg)
    else:
        print('----- stdout -----')
        print(result['stdout'].rstrip())

    if args.mem_limit and peak_mb > args.mem_limit:
        print(f'⚠ Memory limit exceeded: {peak_mb:.2f} MB > {args.mem_limit} MB')

    # Optional static analysis
    if args.analysis:
        do_analysis(args.source)


# ────────────────────────────────────────────────────────────────────────────
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('\n[Interrupted]', file=sys.stderr)
        sys.exit(130)