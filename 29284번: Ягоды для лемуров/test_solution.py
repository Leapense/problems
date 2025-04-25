from io import StringIO
import sys, importlib.util

def run_io(input_s: str) -> str:
    spec = importlib.util.spec_from_file_location("solution", "solution.py")
    sol = importlib.util.module_from_spec(spec)
    old_stdin, old_stdout = sys.stdin, sys.stdout
    try:
        sys.stdin, sys.stdout = StringIO(input_s), StringIO()
        spec.loader.exec_module(sol)
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = old_stdin, old_stdout

def test_sample():
    inp = "4\n4 2 2 4\n"
    assert run_io(inp) == "14"

def test_all_zero():
    inp = "5\n0 0 0 0 0\n"
    assert run_io(inp) == "0"

def test_increasing():
    inp = "5\n1 2 3 4 5\n"
    assert run_io(inp) == "17"