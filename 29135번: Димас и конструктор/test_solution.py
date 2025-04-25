from io import StringIO
import sys, importlib.util

def run_io(input_data: str) -> str:
    spec = importlib.util.spec_from_file_location("solution", "solution.py")
    sol = importlib.util.module_from_spec(spec)
    old_in, old_out = sys.stdin, sys.stdout

    try:
        sys.stdin, sys.stdout = StringIO(input_data), StringIO()
        spec.loader.exec_module(sol)
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = old_in, old_out

def test_sample1():
    inp = "3 3\n1 2 3\n"
    out = "3"
    assert run_io(inp) == out

def test_sample2():
    inp = "4 6\n1 2 2 1\n"
    out = "3"
    assert run_io(inp) == out