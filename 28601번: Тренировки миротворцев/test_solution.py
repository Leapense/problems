import subprocess
import sys
import os
import pytest

def run_input(input_data: str) -> str:
    p = subprocess.Popen(
        [sys.executable, os.path.join(os.path.dirname(__file__), "solution.py")],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
        text=True
    )
    out, err = p.communicate(input_data)
    assert err == ""
    return out.strip()

@pytest.mark.parametrize("inp,expected", [
    ("1\n", "2"),   # sample 1
    ("3\n", "4"),   # sample 2
    ("0\n", "0"),   # zero‑area needs no moves
    ("2\n", "3"),   # minimal k+y: 1+2=3
    ("4\n", "4"),   # 2×2=4 → sum=4
    ("5\n", "5"),   # best: 2×3=6>=5 → sum=5
    ("6\n", "5"),   # 2×3=6≥6 → sum=5
    ("7\n", "6"),   # 2×4 or 3×3 → sum=6
])

def test_small(inp, expected):
    assert run_input(inp) == expected

def brute(s: int) -> int:
    best = 10 ** 9
    for k in range(1, s + 1):
        y = (s + k - 1) // k
        best = min(best, k + y)
    return best if s > 0 else 0

@pytest.mark.parametrize("s", list(range(0,1000,37)))
def test_brute(s):
    inp = f"{s}\n"
    assert run_input(inp) == str(brute(s))