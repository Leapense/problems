import subprocess, textwrap, sys
from solution import min_energy

def run_io(inp: str) -> str:
    res = subprocess.run([sys.executable, "solution.py"], input = inp.encode(), stdout = subprocess.PIPE)
    return res.stdout.decode().strip()

def test_single():
    assert min_energy(1, [10]) == 0

def test_two():
    assert min_energy(2, [4, 5]) == 4

def test_alternating():
    assert min_energy(4, [1, 100, 1, 100]) == 2

def test_sample():
    assert min_energy(5, [2, 5, 4, 1, 3]) == 6

def test_sample_io(tmp_path):
    inp = textwrap.dedent("""
        5
        2 5 4 1 3
    """)
    assert run_io(inp) == "6"

