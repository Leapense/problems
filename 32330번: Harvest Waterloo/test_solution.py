import subprocess
import sys
import pytest

EXEC = [sys.executable, "solution.py"]

@pytest.mark.parametrize("inp, outp", [
    (
        # Sample 1
        "6\n"
        "6\n"
        "**LMLS\n"
        "S*LMMS\n"
        "S*SMSM\n"
        "******\n"
        "LLM*MS\n"
        "SSL*SS\n"
        "5\n"
        "1\n",
        "37\n"
    ),
    (
        # Sample 2
        "6\n"
        "6\n"
        "**LMLS\n"
        "S*LMMS\n"
        "S*SMSM\n"
        "***SLL\n"
        "LLM*MS\n"
        "SSL*SS\n"
        "2\n"
        "4\n",
        "88\n"
    ),
])
def test_samples(inp, outp):
    proc = subprocess.Popen(EXEC, stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
    out, _ = proc.communicate(inp)
    assert out == outp