from pathlib import Path
import subprocess
import sys
import pytest

@pytest.mark.parametrize("input_s,expected", [
    ("3 5\n1 3 5\n", "21"),
    ("1 10\n7\n", "1"),
    ("2 3\n2 3\n", "8"),
    ("4 2\n1 2 4 8\n", "6"),
])

def test_stamps(input_s, expected, tmp_path):
    script = tmp_path / "Main.py"
    script.write_text(Path(__file__).parent.joinpath("Main.py").read_text())
    p = subprocess.run([sys.executable, str(script)], input=input_s, text=True, capture_output=True)
    assert p.stdout.strip() == expected