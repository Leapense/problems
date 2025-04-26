from subprocess import run, PIPE

code = r"""
3 4
1 2 3
2 7 5 4
"""

expected = "JAH\nEI\nJAH\nEI"

def test_sample():
    proc = run(["python3", "solution.py"], input = code.encode(), stdout = PIPE)
    assert proc.stdout.decode() == expected