import sys, os
from io import StringIO
import solution as sol

def run_io(inp: str) -> str:
    backup_in, backup_out = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = StringIO(inp), StringIO()
    try:
        sol.main()
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = backup_in, backup_out


def test_sample1():
    inp = "9\n1 9 4 3 5 7 6 8 2\n"
    assert run_io(inp) == "1"

def test_sample2():
    inp = "3\n1 1 1\n"
    assert run_io(inp) == "1"

def test_sample3():
    inp = "4\n1 3 2 4\n"
    assert run_io(inp) == "0"

def test_all_equal_large():
    n = 10000
    arr = " ".join(["5"] * n)
    assert run_io(f"{n}\n{arr}\n") == "1"

def test_small_fail():
    assert run_io("2\n1 2\n") == "0"

def test_valid_l2():
    inp = "6\n1 6 2 5 3 4\n"
    assert run_io(inp) == "1"