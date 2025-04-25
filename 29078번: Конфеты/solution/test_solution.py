from io import StringIO
import importlib.util
import sys

def run_io(input_data: str) -> str:
    spec = importlib.util.spec_from_file_location("solution","solution.py")
    mod = importlib.util.module_from_spec(spec)
    old_in, old_out = sys.stdin, sys.stdout
    try:
        sys.stdin, sys.stdout = StringIO(input_data), StringIO()
        spec.loader.exec_module(mod)
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = old_in, old_out

def test_sample1():
    assert run_io("6\n3 3 1 2 2 1\n") == "4"

def test_sample2():
    assert run_io("2\n1 1\n") == "0"
