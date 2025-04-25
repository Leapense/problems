from io import StringIO
import sys, importlib.util

def run_io(input_s: str) -> str:
    spec = importlib.util.spec_from_file_location("sol", "solution.py")
    module = importlib.util.module_from_spec(spec)
    old_stdin, old_stdout = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = StringIO(input_s), StringIO()
    try:
        spec.loader.exec_module(module)
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = old_stdin, old_stdout

def test_samples():
    inp = "3\n2 6\n1 5\n4 4\n"
    out = run_io(inp)
    lines = out.splitlines()
    assert lines == ["YES", "NO", "YES"]

def test_additional():
    data = "5\n1 3\n2 10\n3 9\n5 11\n7 7\n"
    # (1,3)->YES, (2,10)->NO, (3,9)->YES, (5,11)->YES, (7,7)->YES
    expected = ["YES","NO","YES","YES","YES"]
    out = run_io(data)
    assert out.splitlines() == expected