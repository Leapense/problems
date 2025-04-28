# test_solution.py

import subprocess
import sys
import pytest

# Helper to run our solution on given input and capture output
def run_io(input_data: str) -> str:
    proc = subprocess.run(
        [sys.executable, "solution.py"],
        input=input_data.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=True
    )
    return proc.stdout.decode().strip()

@pytest.mark.parametrize("inp, expected", [
    (  # Sample Input 1
        """\
6
hotel
weary
heart
blast
pilot
vague
3
X!XX!
*!XX!
*****
""",
        """\
1
1
1"""
    ),
    (  # Sample Input 2
        """\
3
scale
table
maple
5
X!X**
X!X**
X!X**
X!X**
X!X**
""",
        """\
2
2
2
2
2"""
    ),
    (  # Sample Input 3
        """\
4
scale
table
maple
smile
4
X!X**
*XX**
X!X**
*****
""",
        """\
2
1
2
1"""
    ),
])
def test_samples(inp, expected):
    out = run_io(inp)
    assert out == expected

def test_trivial_single_word():
    # With only the secret word in the dict, every feedback must match exactly one (the secret itself).
    inp = "1\nabcde\n3\nXXXXX\n*****\nXX*XX\n"
    # Since secret == "abcde", compute_feedback("abcde","abcde")="*****"; 
    # but feedbacks "XXXXX" or "XX*XX" cannot come from any dict word except maybe if secret has no repeats.
    # Actually compute_feedback("abcde","abcde") is "*****", so only the third line matches count=1, others 0.
    expected = "0\n1\n0"
    assert run_io(inp) == expected