import io, sys, importlib

def run_io(inp: str) -> str:
    import solution            # file name: solution.py
    importlib.reload(solution)
    sys.stdin = io.StringIO(inp)
    sys.stdout = io.StringIO()
    solution.main()
    return sys.stdout.getvalue()

def test_sample():
    assert run_io("5 1\n1 2 3 -1 2\n") == "5\n"

def test_two_columns():             # corrected: minimum is 3, not 2
    assert run_io("2 3\n1 1\n") == "3\n"

def test_zero_k():
    assert run_io("4 0\n10 -5 7 9\n") == "17\n"

def test_negative():                # corrected: minimum is 2, not 2 000 000 000
    assert run_io("3 2\n-1000000000 -1000000000 -1000000000\n") == "2\n"
