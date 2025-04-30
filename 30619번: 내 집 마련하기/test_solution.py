import io
import sys
import pytest
import solution

def run_io(input_data: str) -> str:
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = io.StringIO(input_data)
    sys.stdout = io.StringIO()
    try:
        solution.main()
        return sys.stdout.getvalue()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

def test_sample():
    input_data = """
5
1 3 4 2 5
3
2 3
3 5
1 5
"""
    expected = """
1 2 4 3 5
1 3 4 2 5
1 2 3 4 5
"""
    assert run_io(input_data) == expected

def test_minimal():
    input_data = """
1
1
1
1 1
"""
    expected = "1\n"
    assert run_io(input_data) == expected

def test_random_small():
    input_data = """
4
4 1 3 2
1
1 4
"""
    expected = "1 2 3 4\n"
    assert run_io(input_data) == expected