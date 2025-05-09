import subprocess, textwrap, os, sys, importlib.util, importlib.machinery

loader = importlib.machinery.SourceFileLoader("solution", "solution.py")
spec = importlib.util.spec_from_loader(loader.name, loader)
solution = importlib.util.module_from_spec(spec)
loader.exec_module(solution)

def run_io(inp: str) -> str:
    return subprocess.check_output(
        [sys.executable, "solution.py"],
        input=inp.encode(),
        timeout=1
    ).decode().strip()

def test_sample1():
    inp = textwrap.dedent("""\
        3 4 2 5
        2 1
        3 3
    """)
    out = run_io(inp)
    assert len(out) == 5
    assert out.count('D') - out.count('U') == 2
    assert out.count('R') - out.count('L') == 3

def test_sample2():
    inp = textwrap.dedent("""\
        5 4 3 6
        2 4
        3 2
        5 1
    """)
    assert run_io(inp) == "-1"

def test_zero_extra():
    inp = "2 2 0 2\n"
    assert run_io(inp) in {"DR", "RD"}

def test_single_cell_ok():
    inp = "1 1 0 0\n"
    assert run_io(inp) == ""

def test_single_cell_fail():
    inp = "1 1 0 2\n"
    assert run_io(inp) == "-1"

def test_large_even_extra():
    inp = "2 3 0 9\n"   # D=3, E=6
    out = run_io(inp)
    assert len(out) == 9
    assert out.count('D') - out.count('U') == 1
    assert out.count('R') - out.count('L') == 2