import subprocess
import sys

def run(inp: str) -> str:
    proc = subprocess.run(
        [sys.executable, "main.py"],
        input = inp, text = True,
        capture_output = True
    )
    return proc.stdout.strip()

def test_sample1():
    inp = """2
4
3 1 1
8 2 1
8 4 2
8 3 1
7
8 7 1
8 7 2
8 7 3
8 7 4
8 7 5
8 7 6
8 7 7
"""
    expected = """4
1 2 3 4 5 6"""
    assert run(inp) == expected
