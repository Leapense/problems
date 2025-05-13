import subprocess, sys, os, textwrap
from solution import minimum_ships

def run_io(inp: str) -> str:
    """helper – run the program exactly like the judge does"""
    proc = subprocess.run(
        [sys.executable, os.path.join(os.path.dirname(__file__), "solution.py")],
        input=inp.encode(),
        stdout=subprocess.PIPE,
        check=True,
    )
    return proc.stdout.decode().strip()

def test_samples():
    sample1_in = "3\n1\n3\n4\n"
    assert run_io(sample1_in) == "2"

    sample2_in = "5\n1\n7\n10\n13\n19\n"
    assert run_io(sample2_in) == "2"

    sample3_in = "3\n1\n500000000\n999999999\n"
    assert run_io(sample3_in) == "1"
    
def test_single_large_gap():
    # one ship, gigantic period
    lst = [1, 1_000_000_000]
    n = len(lst)
    inp = "2\n" + "\n".join(map(str, lst)) + "\n"
    assert run_io(inp) == "1"
    
def brute_force(days):
    """Slow check for tiny inputs – for internal tests only"""
    from itertools import combinations, chain

    T = days[-1]
    dset = set(days)

    # produce every possible period (up to T)
    periods = []
    for p in range(1, T):
        if all((1 + k * p) in dset for k in range(1, (T - 1) // p + 1)):
            periods.append(p)

    best = T  # large
    for r in range(1, len(periods) + 1):
        for sel in combinations(periods, r):
            s = set()
            for p in sel:
                k = 0
                while True:
                    v = 1 + k * p
                    if v > T:
                        break
                    s.add(v)
                    k += 1
            if s == dset:
                best = r
                break
        if best != T:
            break
    return best

def test_random_small():
    import random

    random.seed(0)
    for _ in range(200):
        # build a random instance with very small T ( ≤ 45 )
        T = random.randint(4, 45)
        # pick some periods
        periods = random.sample(range(2, T), random.randint(1, 3))
        days = sorted(
            {1} | {1 + k * p for p in periods for k in range(1, (T - 1) // p + 1)}
        )
        res_fast = minimum_ships(days)
        res_slow = brute_force(days)
        assert res_fast == res_slow