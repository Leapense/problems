import subprocess
import sys
import pytest

EXEC = [sys.executable, "solution.py"]

@pytest.mark.parametrize("inp, expected", [
    # Sample 1
    (
        "6\n"
        "19 364\n"
        "21 1023\n"
        "19 66\n"
        "19 242\n"
        "21 807\n"
        "19 675\n",
        "2.9704451880078357\n"
    ),
    # Sample 2
    (
        "4\n"
        "33 10\n"
        "33 27\n"
        "44 10\n"
        "44 27\n",
        "1.9865035460205664\n"
    ),
])
def test_samples(inp, expected):
    p = subprocess.Popen(EXEC, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    out, err = p.communicate(inp)
    assert err == ""
    assert abs(float(out) - float(expected)) < 1e-9