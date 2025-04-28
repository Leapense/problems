import os
import subprocess
import textwrap
import pytest

def run_io(test_input: str) -> str:
    cwd = os.path.dirname(__file__)
    proc = subprocess.run(
        ["python3", os.path.join(cwd, "solution.py")],
        input=test_input.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=True,
    )
    return proc.stdout.decode().strip()

@pytest.mark.parametrize(
    ("inp", "expected"),
    [
        (
            textwrap.dedent(
                """\
                4
                3 1
                0 2
                2 3
                1 0
                """
            ),
            "1 1",
        ),
        (
            textwrap.dedent(
                """\
                2
                0 0
                2 2
                """
            ),
            "0 0",
        ),
    ],
)
def test_sample(inp, expected):
    assert run_io(inp) == expected