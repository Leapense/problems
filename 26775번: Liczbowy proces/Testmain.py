import io, sys
from main import main

def run_io(inp : str) -> str:
    old_stdin = sys.stdin
    old_stdout = sys.stdout
    sys.stdin = io.TextIOWrapper(io.BytesIO(inp.encode()))
    out_bytes = io.BytesIO()
    sys.stdout = io.TextIOWrapper(out_bytes)
    try:
        main()
        sys.stdout.flush()
        return out_bytes.getvalue().decode()
    finally:
        sys.stdin = old_stdin
        sys.stdout = old_stdout

def test_sample1():
    inp = '''6
2
1
30
42
2
731
'''
    exp = '''TAK
TAK
NIE
TAK
TAK
NIE
'''
    assert run_io(inp) == exp

def test_sample2():
    inp='''3
78
1806
4997888322
'''
    exp='''TAK
NIE
TAK
'''
    assert run_io(inp)==exp
