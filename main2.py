#!/usr/bin/env python3
# multi_run_mem_cli.py — CLI runner with auto-detect .in/.out, batch mode,
#                        runtime metrics, optional lizard analysis, and
#                        “copy SOLUTION source to clipboard” support.

from __future__ import annotations

import argparse
import platform
import re
import resource
import shutil
import subprocess
import sys
import tempfile
import textwrap
import time
from contextlib import contextmanager
from difflib import unified_diff
from itertools import zip_longest
from pathlib import Path
from typing import Generator, List, Optional

import psutil

# ─── Auto-detect extensions ─────────────────────────────────────────
IN_EXTS  = ['.in']
EXP_EXTS = ['.out', '.exp', '.expected', '.ans']


def auto_pick_files(stem: Path) -> tuple[Optional[str], Optional[str]]:
    """
    Given Path('/…/foo'), look for foo.in, foo.out/exp/expected/ans, etc.
    This logic is best for single-file mode.
    """
    in_file  = next((str(stem.with_suffix(ext)) for ext in IN_EXTS
                     if stem.with_suffix(ext).exists()), None)
    exp_file = next((str(stem.with_suffix(ext)) for ext in EXP_EXTS
                     if stem.with_suffix(ext).exists()), None)

    # Fallback logic for single-file mode
    if not in_file:
        ins = list(stem.parent.glob(f'*{IN_EXTS[0]}'))
        if len(ins) == 1:
            in_file = str(ins[0])

    if not exp_file:
        cands: List[Path] = []
        for ext in EXP_EXTS:
            cands.extend(stem.parent.glob(f'*{ext}'))
        if len(cands) == 1:
            exp_file = str(cands[0])

    return in_file, exp_file


def find_expected_for_input(in_path: Path) -> Optional[str]:
    """Given an input file path, find its corresponding output file."""
    stem = in_path.with_suffix('')

    # 1. First, try the exact same stem (e.g., test1.in -> test1.out)
    exact_match = next((str(stem.with_suffix(ext)) for ext in EXP_EXTS
                        if stem.with_suffix(ext).exists()), None)
    if exact_match:
        return exact_match

    # 2. If not found, try common patterns like replacing "input" with "output"
    # (e.g., input1.in -> output1.out)
    if 'input' in stem.name.lower():
        try:
            # Handle names like "input1", "input_1", "input.1"
            base_name = re.sub(r'^input', 'output', stem.name, count=1, flags=re.IGNORECASE)
            out_stem = stem.with_name(base_name)
            input_output_match = next((str(out_stem.with_suffix(ext)) for ext in EXP_EXTS
                                       if out_stem.with_suffix(ext).exists()), None)
            if input_output_match:
                return input_output_match
        except re.error: # In case of invalid regex in name
            pass

    return None


# ─── Language detection & compilation ──────────────────────────────
def detect_lang(src: str) -> Optional[str]:
    return {
        '.c':   'c',
        '.cpp': 'cpp', '.cc': 'cpp', '.cxx': 'cpp',
        '.java': 'java',
        '.py':  'python',
    }.get(Path(src).suffix.lower())


@contextmanager
def compile_source(src: str) -> Generator[tuple[str, str, str], None, None]:
    lang = detect_lang(src)
    if not lang:
        raise RuntimeError(f"Unsupported source extension: {src}")

    workdir = str(Path(src).resolve().parent)
    exe_to_cleanup = None
    try:
        if lang in ('c', 'cpp'):
            # Use a secure method for creating a temporary executable file
            with tempfile.NamedTemporaryFile(prefix='prog_', dir=workdir, delete=False) as tmp_exe:
                exe = tmp_exe.name
            exe_to_cleanup = Path(exe)

            cmd = [
                'gcc' if lang == 'c' else 'g++',
                src, '-O2',
                # Use more common standards for better compatibility
                '-std=c23' if lang == 'c' else '-std=c++26',
                '-Wall', '-Wextra', '-pipe', '-o', exe,
            ]
            res = subprocess.run(cmd, capture_output=True, text=True, check=False)
            if res.returncode:
                raise RuntimeError(f"Compilation failed:\n{res.stderr.strip()}")
            yield lang, exe, workdir

        elif lang == 'java':
            # Run javac from the source file's directory
            res = subprocess.run(['javac', Path(src).absolute()], cwd=workdir, capture_output=True, text=True, check=False)
            if res.returncode:
                raise RuntimeError(f"javac error:\n{res.stderr.strip()}")
            yield lang, Path(src).stem, workdir

        else:  # python – no compilation
            yield lang, Path(src).absolute(), workdir

    finally:
        if exe_to_cleanup and exe_to_cleanup.exists():
            exe_to_cleanup.unlink()


# ─── Peak VmHWM fallback on Linux ───────────────────────────────────
def _linux_vmhwm(pid: int) -> int:
    try:
        with open(f"/proc/{pid}/status") as f:
            for line in f:
                if line.startswith('VmHWM:'):
                    kb = int(line.split()[1])
                    return kb * 1024
    except (FileNotFoundError, IndexError, ValueError):
        pass
    return 0


# ─── Run & measure ─────────────────────────────────────────────────
def run_with_metrics(cmd: List[str],
                     stdin_data: str,
                     cwd: Optional[str],
                     timeout: float,
                     mem_limit_bytes: int = 0):
    start_wall = time.perf_counter()
    peak_rss = 0
    try:
        proc = subprocess.Popen(cmd, cwd=cwd, text=True,
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
    except FileNotFoundError:
        return dict(exit_code=-1, stdout='', stderr=f"Command not found: {cmd[0]}",
                    elapsed=0, peak_rss=0, cpu_avg_pct=0)

    try:
        ps_proc = psutil.Process(proc.pid)
    except psutil.NoSuchProcess:
         # Process finished extremely fast, psutil might not find it
        out, err = proc.communicate()
        elapsed = time.perf_counter() - start_wall
        return dict(exit_code=proc.returncode, stdout=out, stderr=err,
                    elapsed=elapsed, peak_rss=0, cpu_avg_pct=0)

    def monitor():
        nonlocal peak_rss
        try:
            while proc.poll() is None:
                rss = ps_proc.memory_info().rss
                for ch in ps_proc.children(recursive=True):
                    try:
                        rss += ch.memory_info().rss
                    except psutil.NoSuchProcess:
                        continue # Child process may have finished
                peak_rss = max(peak_rss, rss)
                if mem_limit_bytes and rss > mem_limit_bytes:
                    proc.kill()
                time.sleep(0.05)
        except psutil.Error:
            pass

    import threading
    mon_thread = threading.Thread(target=monitor, daemon=True)
    mon_thread.start()

    try:
        out, err = proc.communicate(stdin_data, timeout=timeout)
    except subprocess.TimeoutExpired:
        proc.kill()
        out, err = proc.communicate()
        err += f"\n--- TIMEOUT of {timeout}s EXPIRED ---"

    mon_thread.join(0.1) # Give monitor a moment to finish
    elapsed = time.perf_counter() - start_wall

    if platform.system() == 'Linux':
        try:
            # getrusage is for children that have already exited
            rusage_mem = resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss * 1024
            # VmHWM is from the proc filesystem, may not exist after process exit
            procfs_mem = _linux_vmhwm(proc.pid)
            peak_rss = max(peak_rss, rusage_mem, procfs_mem)
        except Exception:
            pass # Best effort

    try:
        t = ps_proc.cpu_times()
        cpu_time = t.user + t.system
        cpu_avg_pct = (cpu_time / elapsed * 100) if elapsed else 0.0
    except psutil.Error:
        cpu_time = 0.0
        cpu_avg_pct = 0.0

    return dict(
        exit_code=proc.returncode,
        stdout=out,
        stderr=err,
        elapsed=elapsed,
        peak_rss=peak_rss,
        cpu_avg_pct=cpu_avg_pct,
    )


# ─── Output comparison helpers ─────────────────────────────────────
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


def compare_outputs(expected_path: str, actual: List[str]) -> tuple[bool, str]:
    with open(expected_path, encoding='utf-8') as f:
        expected = [ln.rstrip('\n\r') for ln in f]

    if not expected and not actual:
        return True, "Outputs are both empty."

    for idx, (e, a) in enumerate(zip_longest(expected, actual), 1):
        if e is None:
            return False, f'Extra output on line {idx}: {a}'
        if a is None:
            return False, f'Missing output on line {idx} (expected: {e})'
        if not _line_to_regex(_normalize(e)).fullmatch(_normalize(a)):
            diff = '\n'.join(unified_diff(expected, actual,
                                          fromfile='expected', tofile='actual',
                                          lineterm=''))
            return False, f'Line {idx} mismatch:\n{diff}'
    return True, 'All lines match.'


# ─── Static analysis (lizard) ───────────────────────────────────────
def do_analysis(src: str):
    try:
        import lizard  # noqa: F401
    except ImportError:
        print('[analysis] lizard not found —> pip install lizard', file=sys.stderr)
        return
    html = Path(src).with_suffix('.lizard.html')
    cmd = ['lizard', '--html', src]
    try:
        with html.open('w', encoding='utf-8') as fp:
            res = subprocess.run(cmd, stdout=fp, stderr=subprocess.PIPE, text=True, check=False)
        if res.returncode:
            print('[analysis] lizard failed:', res.stderr.strip(), file=sys.stderr)
        else:
            print(f'[analysis] HTML report written to: {html}')
    except Exception as e:
        print(f"[analysis] failed to run lizard: {e}", file=sys.stderr)


# ─── Clipboard helpers ─────────────────────────────────────────────
def copy_to_clipboard(text: str) -> str:
    # Using pyperclip is preferred as it handles more edge cases.
    try:
        import pyperclip
        pyperclip.copy(text)
        return "[info] Copied to clipboard via pyperclip."
    except (ImportError, pyperclip.PyperclipException):
        # Fallback to command-line tools
        for cmd_args in (('wl-copy',),
                         ('xclip', '-selection', 'clipboard'),
                         ('xsel', '--clipboard', '--input')):
            if shutil.which(cmd_args[0]):
                try:
                    subprocess.run(cmd_args, input=text.encode(),
                                   capture_output=True, check=True)
                    return f"[info] Copied via {cmd_args[0]}."
                except (subprocess.CalledProcessError, FileNotFoundError):
                    continue
    return "[warning] Clipboard copy failed (no backend found)."


# ─── CLI argument parsing ──────────────────────────────────────────
def parse_args():
    p = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=textwrap.dedent("""\
            Compile & run a source file with metrics, auto I/O detection,
            batch mode, and optional static analysis.

            Expected-output syntax:
              • lines starting `re:`   → raw regex
              • `{alt1|alt2}`          → alternations
            """),
    )
    p.add_argument('source', help='C/C++/Java/Python source file')
    grp = p.add_mutually_exclusive_group()
    grp.add_argument('-i', '--input', help='File to feed to stdin')
    grp.add_argument('--stdin', help='Literal string to feed to stdin')
    p.add_argument('-e', '--expected', help='Expected output file')
    p.add_argument('-t', '--timeout', type=float, default=10,
                   help='Timeout seconds (default 10)')
    p.add_argument('--mem-limit', type=int, default=0,
                   help='Memory limit in MB (0 = no limit)')
    p.add_argument('--analysis', action='store_true',
                   help='Run lizard static analysis afterwards')
    p.add_argument('-v', '--verbose', action='store_true',
                   help='Always show stderr, even if empty')
    p.add_argument('--batch', '-d', metavar='DIR',
                   help='Run all *.in in DIR as batch tests')
    return p.parse_args()


# ─── Main ──────────────────────────────────────────────────────────
def main():
    args = parse_args()
    src_path = Path(args.source).absolute()
    overall_success = True

    # Prepare stdin data for single-run mode
    stdin_data = ''
    if args.stdin is not None:
        stdin_data = args.stdin
    elif args.input:
        try:
            stdin_data = Path(args.input).read_text(encoding='utf-8')
        except FileNotFoundError:
            print(f"[error] Input file not found: {args.input}", file=sys.stderr)
            sys.exit(1)

    # Auto-detect stdin/expected when omitted in single-run mode
    if not args.batch and (not args.input or not args.expected):
        auto_in, auto_exp = auto_pick_files(src_path.with_suffix(''))
        if not args.input and auto_in:
            args.input = auto_in
            print(f"[info] Auto-detected input: {Path(auto_in).name}")
            stdin_data = Path(args.input).read_text(encoding='utf-8')
        if not args.expected and auto_exp:
            args.expected = auto_exp
            print(f"[info] Auto-detected expected output: {Path(auto_exp).name}")

    # Set up test cases
    tests: List[tuple[str, Optional[str]]] = []
    if args.batch:
        batch_dir = Path(args.batch).absolute()
        if not batch_dir.is_dir():
            print(f"[error] Batch directory not found: {batch_dir}", file=sys.stderr)
            sys.exit(1)
        for in_file in sorted(batch_dir.glob('*.in')):
            exp_file = find_expected_for_input(in_file)
            tests.append((str(in_file), exp_file))
    else:
        tests = [(args.input, args.expected)]

    ok_cnt = 0
    total = len(tests)

    try:
        with compile_source(args.source) as (lang, exe, cwd):
            cmd = {
                'c':      [exe],
                'cpp':    [exe],
                'java':   ['java', exe], # Simplified and corrected Java command
                'python': [sys.executable, exe], # Use sys.executable for venv safety
            }[lang]

            for inp_path_str, exp_path_str in tests:
                # In single mode, inp_path_str might be None if using --stdin
                current_input_name = Path(inp_path_str).name if inp_path_str else "stdin"
                print(f"\n=== Running on: {current_input_name} ===")

                current_stdin = stdin_data
                if args.batch and inp_path_str: # For batch, load each file
                    current_stdin = Path(inp_path_str).read_text(encoding='utf-8')

                res = run_with_metrics(cmd, current_stdin, cwd, args.timeout,
                                       args.mem_limit * 1024**2 if args.mem_limit else 0)

                peak_mb = res['peak_rss'] / 1024**2
                print(f"exit: {res['exit_code']:<3} | "
                      f"elapsed: {res['elapsed']*1000:7.2f} ms | "
                      f"peak rss: {peak_mb:6.2f} MB | "
                      f"cpu avg: {res['cpu_avg_pct']:5.1f}%")

                if res['stderr'].strip() or (args.verbose and res['stderr'] is not None):
                    print("-- stderr --")
                    print(res['stderr'].rstrip())

                # Handle empty stdout correctly
                output_str = res['stdout'].rstrip('\n\r')
                actual = output_str.split('\n') if output_str else []

                if exp_path_str:
                    ok, msg = compare_outputs(exp_path_str, actual)
                    print("===== Comparison Result =====")
                    if ok:
                        print(f"\033[92m✅ PASS — {msg}\033[0m")
                        ok_cnt += 1
                    else:
                        print(f"\033[91m❌ FAIL — {msg}\033[0m")
                        overall_success = False
                else:
                    if not args.batch:
                        print("-- stdout --")
                        print(res['stdout'].rstrip('\n\r'))
                    else: # In batch mode, missing .out is a kind of failure
                        print("\033[93m- WARN — No expected output file found.\033[0m")
                        overall_success = False

                if args.mem_limit and peak_mb > args.mem_limit:
                    print(f"\033[93m⚠ MEMORY LIMIT EXCEEDED: "
                          f"{peak_mb:.2f} MB > {args.mem_limit} MB\033[0m")
                    overall_success = False

    except RuntimeError as e:
        print(f"[error] {e}", file=sys.stderr)
        sys.exit(1)

    if args.batch:
        print(f"\nBatch result: {ok_cnt} / {total} passed")
        if ok_cnt == total and sys.stdin.isatty():
            try:
                response = input(
                    f"Looks like you passed all tests! "
                    f"Copy {src_path.name} to clipboard? (Y/n) "
                ).strip().lower()
            except EOFError:
                response = 'n'

            if response in ('', 'y', 'yes'):
                code_text = src_path.read_text(encoding='utf-8')
                print(copy_to_clipboard(code_text))

    if args.analysis:
        do_analysis(args.source)

    # Correctly set exit code for both single and batch mode
    sys.exit(0 if overall_success and ok_cnt == total else 1)


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('\n[Interrupted]', file=sys.stderr)
        sys.exit(130)
