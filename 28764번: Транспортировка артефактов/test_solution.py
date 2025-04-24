import io
import sys
import pytest
import solution

def run(input_data: str) -> str:
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = io.StringIO(input_data)
    sys.stdout = io.StringIO()
    solution.solve()
    output = sys.stdout.getvalue().strip()
    sys.stdin = backup_stdin
    sys.stdout = backup_stdout
    return output

def test_sample1():
    inp = "4\n10\n5\n11\n12\n3\n"
    assert run(inp) == "144"

def test_sample2():
    inp = "2\n2\n2\n4\n2\n6\n"
    assert run(inp) == "24"
