# test_solution.py
import subprocess
import textwrap
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent

def run_solution(inp: str) -> str:
    """Helper: run solution.py with `inp` on stdin, return stdout."""
    proc = subprocess.run(
        ["python3", str(PROJECT_ROOT / "solution.py")],
        input=inp.encode(),
        stdout=subprocess.PIPE,
        check=True,
    )
    return proc.stdout.decode().strip()


def test_sample():
    sample_in = textwrap.dedent(
        """\
        0 0 5 0 0 5 3 2 7 2 0 4
        1.3 2.6 12.1 4.5 8.1 13.7 2.2 0.1 9.8 6.6 1.9 6.7
        0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0
        """
    )
    expected_out = textwrap.dedent(
        """\
        5.000 0.800 0.000 0.800
        13.756 7.204 2.956 5.304
        """
    ).strip()

    assert run_solution(sample_in) == expected_out