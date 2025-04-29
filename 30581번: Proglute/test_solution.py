import subprocess
import sys
import pytest

def run_input(input_data: str) -> str:
    p = subprocess.Popen(
        [sys.executable, "solution.py"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    out, err = p.communicate(input_data)
    if err:
        raise RuntimeError(f"Error from solution.py:\n{err}")
    return out.strip()

@pytest.mark.parametrize("n, expected", [
    # Sample tests from problem statement
    (5, "20"),
    (666, "61847156"),
    # Edge and small cases
    (2, "1"),      # the two-peg trivial path
    (3, "3"),      # 3 * 2^0 = 3
    (4, "8"),      # 4 * 2^1 = 8
    (10, str(10 * pow(2, 7, 10**9+7) % (10**9+7))),
    (1000, str(1000 * pow(2, 997, 10**9+7) % (10**9+7))),
])
def test_paths(n, expected):
    inp = f"{n}\n"
    assert run_input(inp) == expected