import io, sys, importlib

def run_io(inp: str) -> str:
    import main
    importlib.reload(main)

    backup_stdin, backup_stdout = sys.stdin, sys.stdout
    # BytesIO → TextIOWrapper 로 감싸기
    sys.stdin  = io.TextIOWrapper(io.BytesIO(inp.encode()), encoding="utf-8")
    sys.stdout = io.StringIO()
    try:
        main.main()
        return sys.stdout.getvalue()
    finally:
        sys.stdin, sys.stdout = backup_stdin, backup_stdout

def test_sample1():
    inp = '''3 14
4 7 3
'''
    exp = '3\n'
    assert run_io(inp) == exp

def test_sample2():
    inp = '''4 36
11 5 7 14
'''
    exp = '3\n'
    assert run_io(inp) == exp

def test_sample3():
    inp = '''9 18
1 5 3 4 6 2 1 2 4
'''
    exp = '6\n'
    assert run_io(inp) == exp
