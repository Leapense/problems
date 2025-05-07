import subprocess
import os
import sys
import textwrap
import importlib

sys.path.append(os.path.dirname(__file__))

import solution

def run_io(inp: str) -> str:
    from io import StringIO
    import contextlib

    backup_stdin = sys.stdin
    backup_stdout = sys.stdout

    sys.stdin = StringIO(inp)
    sys.stdout = StringIO()

    try:
        solution.main()
        return sys.stdout.getvalue()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

def test_sample_1():
    assert run_io("773\n").strip() == "3"

def test_sample_2():
    assert run_io("300007\n").strip() == "2"

def test_sample_3():
    assert run_io("11\n").strip() == "1"

def test_non_prime_start():
    assert run_io("100\n").strip() == "0"

def test_single_digit_primes():
    assert run_io("7\n").strip() == "1"