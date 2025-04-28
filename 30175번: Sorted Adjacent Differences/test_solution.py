import io, importlib, sys

def check(seq):
    return all(abs(seq[i] - seq[i + 1]) <= abs(seq[i + 1] - seq[i + 2]) for i in range(len(seq) - 2))

def run_case(inp: str):
    import solution
    importlib.reload(solution)
    sys.stdin = io.StringIO(inp)
    captured = io.StringIO()
    sys.stdout = captured
    solution.solve()
    sys.stdout = sys.__stdout__
    return captured.getvalue().strip().splitlines()

def test_sample():
    lines = run_case('''2
                     6
                     5 -2 4 8 6 5
                     4
                     8 1 4 2
                     ''')
    assert len(lines) == 2
    
    arr = list(map(int, lines[0].split()))
    assert check(arr)
    arr = list(map(int, lines[1].split()))
    assert check(arr)