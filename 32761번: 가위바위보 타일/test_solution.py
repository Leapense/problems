import subprocess, sys, textwrap, os
from solution import solve

def run_io(inp: str) -> str:
    n, s = inp.strip().split('\n')
    return solve(int(n), s) + '\n'

def test_sample1():
    inp = "7\nPRSPRSP\n"
    assert run_io(inp) == "1\n"

def test_sample2():
    inp = "3\nRSP\n"
    assert run_io(inp) == "0\n"

def test_sample3():
    inp = "13\nSRPSRPRSPRSRP\n"
    assert run_io(inp) == "4\n"

def test_all_same():
    inp = "9\nRRRRRRRRR\n"
    assert run_io(inp) == "9\n"

def test_large_random():
    import random
    random.seed(1)
    n = 100000
    s = ''.join(random.choice("RSP") for _ in range(n))
    out = solve(n, s)
    assert 0 <= int(out) <= n