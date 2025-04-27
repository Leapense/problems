import sys
import io
import pytest

from solution import solve

def run_io(input_str):
    backup_in, backup_out = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = io.StringIO(input_str), io.StringIO()
    solve()
    output = sys.stdout.getvalue()
    sys.stdin, sys.stdout = backup_in, backup_out
    return output

@pytest.mark.parametrize("input_str,expected", [
    (
        "5 2 3\n"
        "2\n"
        "4\n"
        "1 2\n"
        "2 4\n"
        "5 1\n",
        "4\n"
    ),
    (
        "3 1 0\n"
        "2\n",
        "1\n"
    ),
    (
        "4 2 1\n"
        "1\n"
        "4\n"
        "2 3\n",
        "2\n"
    ),
    (
        "4 2 2\n"
        "1\n"
        "3\n"
        "1 2\n"
        "3 4\n",
        "4\n"
    )
])

def test_solution(input_str, expected):
    assert run_io(input_str) == expected