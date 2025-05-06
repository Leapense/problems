import io
import sys
import pytest
from solution import main

def run_io(input_str: str) -> str:
    backup_stdin, backup_stdout = sys.stdin, sys.stdout
    sys.stdin = io.StringIO(input_str)
    sys.stdout = io.StringIO()

    try:
        main()
        return sys.stdout.getvalue()
    finally:
        sys.stdin, sys.stdout = backup_stdin, backup_stdout

def test_sample1():
    inp = """
3
1 0 1
0 0 0
0 1 0
"""
    out = run_io(inp)
    assert out.strip() == "20"

def test_sample2():
    inp = """
2
1 0
0 1
"""
    assert run_io(inp).strip() == "5"

def test_sample3():
    inp = """
5
1 0 0 0 1
0 0 1 0 0
0 1 0 0 0
0 0 0 0 0
1 0 0 0 1
"""
    assert run_io(inp).strip() == "289"

def test_all_ones_2x2():
    inp = """
2
1 1
1 1
"""
    assert run_io(inp).strip() == "7"


if __name__ == "__main__":
    pytest.main()
