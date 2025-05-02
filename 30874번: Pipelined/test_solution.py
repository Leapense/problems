import sys
import io
import pytest

from solution import solve

def run_io(input_s: str) -> str:
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = io.StringIO(input_s)
    sys.stdout = io.StringIO()
    try:
        solve()
        return sys.stdout.getvalue()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

def test_sample():
    input_data = """
4
5 7 8 11
"""
    output = run_io(input_data)
    assert output.strip() == "14"

def test_single():
    for s in [1, 10, 200000]:
        input_data = f"1\n{s}\n"
        assert run_io(input_data).strip() == str(s)

def test_all_equal():
    input_data = "5\n7 7 7 7 7\n"
    assert run_io(input_data).strip() == "11"

def test_strictly_increasing():
    input_data = "5\n1 2 3 4 5\n"
    assert run_io(input_data).strip() == "9"

def test_strictly_decreasing():
    input_data = "5\n5 4 3 2 1\n"
    assert run_io(input_data).strip() == "9"

def test_large():
    import random
    random.seed(0)
    arr = [random.randint(1, 1000) for _ in range(10)]
    N = len(arr)
    input_data = "10\n" + " ".join(map(str, arr)) + "\n"
    s_sorted = sorted(arr)
    expected = max(si + i for i, si in enumerate(s_sorted))
    assert run_io(input_data).strip() == str(expected)