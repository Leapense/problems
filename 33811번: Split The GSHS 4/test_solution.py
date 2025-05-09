import subprocess, sys, textwrap, random, string

def run_io(inp: str) -> str:
    return subprocess.check_output(
        [sys.executable, "solution.py"],
        input=inp.encode(),
        timeout=2
    ).decode().strip()

def test_sample1():
    inp = "10\nGSHSSHSSHS\n"
    assert run_io(inp) == "2"

def test_sample2():
    inp = "3\nGHS\n"
    assert run_io(inp) == "0"

def test_no_pattern():
    inp = "6\nGGGGGG\n"
    assert run_io(inp) == "0"

def test_all_negative():
    inp = "4\nGSHS\n"
    assert run_io(inp) == "0"

def brute_force(s):
    def cnt(sub, pat):
        c = 0
        for i in range(len(sub) - 3):
            if sub[i:i+4] == pat:
                c += 1
        return c
    best = 0
    n = len(s)
    for l in range(n):
        for r in range(l, n):
            diff = cnt(s[l:r+1], "SSHS") - cnt(s[l:r+1], "GSHS")
            best = max(best, diff)
    return best

def test_random_small():
    for _ in range(100):
        n = random.randint(4, 30)
        s = "".join(random.choice("GSH") for _ in range(n))
        inp = f"{n}\n{s}\n"
        assert int(run_io(inp)) == brute_force(s)

def test_large():
    n = 500000
    s = "S" * n
    inp = f"{n}\n{s}\n"
    assert run_io(inp) == "0"