import subprocess
import sys
import os
import tempfile

DATA = [
    # Sample from statement
    ("7 12 5 2\n3 8 4 0\n", "164\n"),
    # All moduli = 1 ⇒ x ≡ 0 mod 1 always; remainders must be zero
    ("1 1 1 1\n0 0 0 0\n", "0\n"),
    # Simple two congruences folded into four
    ("3 5 7 11\n2 3 4 5\n", "53\n"),
    # Identical moduli
    ("6 6 6 6\n1 2 3 4\n", "??\n"),  # impossible in general, but guarantee says solution exists; this won't be used
    # Another random test
    ("4 9 25 7\n1 4 16 3\n", "841\n"),
]

def run_solution(input_data):
    proc = subprocess.Popen([sys.executable, "solution.py"],
                             stdin = subprocess.PIPE,
                             stdout = subprocess.PIPE,
                             stderr = subprocess.PIPE,
                             text = True)
    out, err = proc.communicate(input_data)
    if proc.returncode != 0:
        raise RuntimeError(f"Non-zero exit code: {err}")
    return out

def test_all():
    for inp, expected in DATA:
        if expected.strip() == "??":
            continue
        out = run_solution(inp)
        assert out == expected