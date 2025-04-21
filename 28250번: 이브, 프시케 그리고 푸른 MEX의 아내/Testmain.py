import subprocess
import sys
import tempfile

def run(input_s: str) -> str:
    p = subprocess.run([sys.executable, "main.py"], 
                       input=input_s.encode(),
                       stdout=subprocess.PIPE)
    return p.stdout.decode()

def test_sample1():
    inp = "8\n0 2 0 1 3 2 1 0\n"
    out = run(inp)
    assert out.strip() == "24"

def test_all_positive():
    inp = "5\n2 3 5 2 4\n"
    assert run(inp).strip() == "0"

def test_only_zeros_and_ones():
    inp = "3\n0 1 0\n"
    assert run(inp).strip() == "5"
