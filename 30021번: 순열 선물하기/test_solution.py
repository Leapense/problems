import pytest
from solution import main

from io import StringIO
import sys

def run_io(input_s: str):
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = StringIO(input_s)
    sys.stdout = StringIO()
    try:
        main()
        return sys.stdout.getvalue()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

@pytest.mark.parametrize("inp,expected", [
    ("5\n", "YES\n1 3 2 4 5\n"),
    ("2\n", "NO\n"),
    ("1\n", "YES\n1\n"),
    ("3\n", "YES\n1 3 2\n"),
    ("8\n", "YES\n1 3 2 4 5 6 7 8\n"),
])
def test_samples(inp, expected):
    out = run_io(inp)
    assert out == expected