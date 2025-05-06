import subprocess
import sys
import pytest

EXEC = [sys.executable, "solution.py"]

@pytest.mark.parametrize("input_s, expected", [
    ("4\n2 5 7 10\n20 4 16 11\n", "23\n"),
    ("3\n1 2 3\n3 2 1\n", "6\n"),
])
def test_samples(input_s, expected):
    p = subprocess.Popen(EXEC, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    out, err = p.communicate(input_s)
    assert err == ""
    assert out == expected
