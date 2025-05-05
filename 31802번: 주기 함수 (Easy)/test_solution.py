import subprocess
import sys
import os
import pytest

SOLUTION = os.path.join(os.path.dirname(__file__), "solution.py")

def run_io(input_s: str) -> str:
    proc = subprocess.Popen(
        [sys.executable, SOLUTION],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    out, err = proc.communicate(input_s)
    if proc.returncode != 0:
        raise RuntimeError(f"Process exited with {proc.returncode}, stderr:\n{err}")
    return out.strip()

@pytest.mark.parametrize("p, array, a, b, expected", [
    # Sample 1
    (10, [1,2,3,1,2,3,1,2,3,1], 2, 5, 6),
    # Sample 2: zero-length interval
    (5, [1,2,3,4,5], 9, 9, 0),
    # Sample 3: negative a
    (4, [1,2,4,8], -5, -3, 9),
    # Additional tests
    (3, [5,5,5], 0, 6, 30),    # two full periods
    (3, [5,5,5], 1, 4, 15),    # wrap around
    (1, [100], -1000000000, 1000000000, 2000000000 * 100),
])
def test_samples(p, array, a, b, expected):
    arr_str = " ".join(map(str, array))
    inp = f"{p}\n{arr_str}\n{a} {b}\n"
    out = run_io(inp)
    assert out == str(expected)