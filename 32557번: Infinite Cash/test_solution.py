import subprocess
import sys
import pytest

EXEC = [sys.executable, "solution.py"]

@pytest.mark.parametrize("inp, outp", [
    (
        "101110101\n1010\n10001110101010101\n",
        "10011\n"
    ),
    (
        "101110101\n1000\n100011101\n",
        "Infinite money!\n"
    ),
    (
        "101110101\n1010\n100011101\n",
        "1001\n"
    ),
])
def test_samples(inp, outp):
    p = subprocess.Popen(EXEC, stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
    out, _ = p.communicate(inp)
    assert out == outp