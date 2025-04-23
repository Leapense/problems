# test_solution.py
import subprocess
import sys

def run(input_data: str) -> str:
    p = subprocess.Popen([sys.executable, "solution.py"],
                         stdin=subprocess.PIPE,
                         stdout=subprocess.PIPE,
                         stderr=subprocess.PIPE,
                         text=True)
    out, err = p.communicate(input_data)
    return out.strip()

def test_sample1():
    inp = """\
3 3
aar
aar
bbc
"""
    assert run(inp) == "YES"

def test_sample2():
    inp = """\
2 5
aboba
ababa
"""
    assert run(inp) == "NO"
