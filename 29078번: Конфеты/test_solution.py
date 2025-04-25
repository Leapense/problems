import sys
from io import StringIO
import solution

def run_io_fun(input_s,  func):
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    sys.stdin = StringIO(input_s)
    sys.stdout = StringIO()
    func()
    output = sys.stdout.getvalue()
    sys.stdin = backup_stdin
    sys.stdout = backup_stdout
    return output

def test_sample1():
    assert run_io_fun("6\n3 3 1 2 2 1\n", solution.main) == "4\n"

def test_sample2():
    assert run_io_fun("2\n1 1\n", solution.main) == "0\n"