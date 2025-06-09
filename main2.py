#!/usr/bin/env python3
# multi_run_mem_cli.py  —  CLI runner with auto-detect .in/.out, batch mode, metrics, and lizard support

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

# ─── Auto-detect extensions ─────────────────────────────────────────
IN_EXTS  = ['.in']
EXP_EXTS = ['.out', '.exp', '.expected', '.ans']

def auto_pick_files(stem: Path) -> tuple[Optional[str], Optional[str]]:
    """
    Given a stem Path('/…/foo'), tries:
      1) foo.in / foo.out/.exp/.expected/.ans
      2) fallback: if only one *.in in that dir → use it
      3) fallback: among all *.out/.exp/.expected/.ans,
         if one → use it; if many → pick one with matching stem first
    """
    in_file = next((str(stem.with_suffix(ext)) for ext in IN_EXTS if stem.with_suffix(ext).exists()), None)
    exp_file = next((str(stem.with_suffix(ext)) for ext in EXP_EXTS if stem.with_suffix(ext).exists()), None)

    # fallback for input
    if not in_file:
        ins = list(stem.parent.glob('*.in'))
        if len(ins) == 1:
            in_file = str(ins[0])

    # fallback for expected
    if not exp_file:
        cands = []
        for ext in EXP_EXTS:
            cands += list(stem.parent.glob(f'*{ext}'))
        if len(cands) == 1:
            exp_file = str(cands[0])
        elif len(cands) > 1:
            # prefer same-stem files
            best = min(cands, key=lambda p: (p.stem != stem.stem, p.name))
            exp_file = str(best)

    return in_file, exp_file

# ─── Language detection & compilation ───────────────────────────────
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
            '-Wall', '-pipe',
            '-o', exe,
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

    # python
    return lang, src, workdir

# ─── Peak VmHWM fallback on Linux ────────────────────────────────────
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

# ─── Run & measure ─────────────────────────────────────────────────
def run_with_metrics(cmd: list[str],
                     stdin_data: str,
                     cwd: Optional[str],
                     timeout: int,
                     mem_limit_bytes: int = 0):
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
        peak_rss = max(
            peak_rss,
            resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss * 1024,
            _linux_vmhwm(proc.pid),
        )

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

# ─── Output comparison helpers ───────────────────────────────────────
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

# ─── Static analysis (lizard) ────────────────────────────────────────
def do_analysis(src: str):
    try:
        import lizard  # noqa: F401
    except ImportError:
        print('[analysis] lizard not found —> pip install lizard', file=sys.stderr)
        return
    html = Path(src).with_suffix('.lizard.html')
    cmd = ['lizard', '--html', src]
    with html.open('w', encoding='utf-8') as fp:
        res = subprocess.run(cmd, stdout=fp, stderr=subprocess.PIPE, text=True)
    if res.returncode:
        print('[analysis] lizard failed:', res.stderr.strip(), file=sys.stderr)
    else:
        print(f'[analysis] HTML report written to: {html}')

# ─── CLI argument parsing ────────────────────────────────────────────
def parse_args():
    p = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=textwrap.dedent("""\
            Compile & run a source file with metrics, auto I/O detection, batch mode, and static analysis.

            Expected‐output supports:
              • lines starting `re:` for raw regex
              • `{alt1|alt2}` for alternations
            """),
    )
    p.add_argument('source', help='C/C++/Java/Python source file')
    grp = p.add_mutually_exclusive_group()
    grp.add_argument('-i', '--input', help='File to feed to stdin')
    grp.add_argument('--stdin', help='Literal string to feed to stdin')
    p.add_argument('-e', '--expected', help='Expected output file')
    p.add_argument('-t', '--timeout', type=int, default=10, help='Timeout seconds (default 10)')
    p.add_argument('--mem-limit', type=int, default=0, help='Memory limit in MB (0 = no limit)')
    p.add_argument('--analysis', action='store_true', help='Run lizard static analysis afterwards')
    p.add_argument('-v', '--verbose', action='store_true', help='Always show stderr')
    p.add_argument('--batch', '-d', metavar='DIR', help='Run all *.in in DIR as batch tests')
    return p.parse_args()

# ─── Main ───────────────────────────────────────────────────────────
def main():
    args = parse_args()
    src_path = Path(args.source)

    # auto-detect files if not provided
    if not args.input or not args.expected:
        auto_in, auto_exp = auto_pick_files(src_path.with_suffix(''))
        args.input    = args.input    or auto_in
        args.expected = args.expected or auto_exp

    # prepare stdin data
    stdin_data = ''
    if args.stdin is not None:
        stdin_data = args.stdin
    elif args.input:
        stdin_data = Path(args.input).read_text(encoding='utf-8')

    # compile once
    lang, exe, cwd = compile_source(args.source)
    cmd = {
        'c':     [exe],
        'cpp':   [exe],
        'java':  ['java', exe],
        'python':['python3', exe],
    }[lang]

    tests = []
    if args.batch:
        d = Path(args.batch)
        for inp in sorted(d.glob('*.in')):
            tests.append((str(inp), None))  # expected picked per test
    else:
        tests = [(args.input, args.expected)]

    ok_cnt = 0
    total  = len(tests)
    for inp, exp in tests:
        print(f"\n=== {Path(inp).name} ===")
        data = Path(inp).read_text(encoding='utf-8')
        res  = run_with_metrics(cmd, data, cwd, args.timeout, args.mem_limit * 1024**2)
        peak_mb = res['peak_rss'] / 1024**2
        print(f"exit : {res['exit_code']} | elapsed: {res['elapsed']*1000:.2f} ms | peak rss: {peak_mb:.2f} MB | cpu avg: {res['cpu_avg_pct']:.1f}%")
        if res['stderr'].strip() or args.verbose:
            print("-- stderr --")
            print(res['stderr'].rstrip())
        actual = res['stdout'].rstrip('\n').split('\n')

        # pick expected if batch
        expected = exp
        if args.batch:
            stem = Path(inp).with_suffix('')
            _, auto_exp = auto_pick_files(stem)
            expected = auto_exp

        if expected:
            ok, msg = compare_outputs(expected, actual)
            print("===== Comparison result =====")
            if ok:
                print(f"\033[92m✅ PASS — {msg}\033[0m")
                ok_cnt += 1
            else:
                print(f"\033[91m❌ FAIL — {msg}\033[0m")
        else:
            print("-- stdout --")
            print(res['stdout'].rstrip())

        if args.mem_limit and peak_mb > args.mem_limit:
            print(f"\033[93m⚠ Memory limit exceeded: {peak_mb:.2f} MB > {args.mem_limit} MB\033[0m")

    if args.batch:
        print(f"\nBatch result: {ok_cnt} / {total} passed")
        print(f"{ok_cnt}/{total} passed")
        sys.exit(0 if ok_cnt == total else 1)

    # analysis after single run
    if args.analysis:
        do_analysis(args.source)

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('\n[Interrupted]', file=sys.stderr)
        sys.exit(130)
