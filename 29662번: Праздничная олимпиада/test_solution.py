import io, sys, importlib

def run_io(inp: str) -> str:
    backup_stdin, backup_stdout = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = io.StringIO(inp), io.StringIO()
    importlib.reload(__import__("solution"))
    out = sys.stdout.getvalue()
    sys.stdin, sys.stdout = backup_stdin, backup_stdout
    return out.strip()

def test_sample1():
    inp = "3 2\n10 15 5\n"
    assert run_io(inp) == "35"

def test_sample2():
    inp = "2 3\n23 30\n"
    assert run_io(inp) == "53"

def test_no_task():
    inp = "0 5\n\n"
    assert run_io(inp) == "0"

def test_many_teams():
    inp = "4 10\n5 5 5 5\n"
    assert run_io(inp) == str(5 + 5 + 5 + 5)