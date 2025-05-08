import pytest
from solution import main_logic
import io
import sys

class Capturing(list):
    def __enter__(self):
        self._stdout = sys.stdout
        sys.stdout = self._stringio = io.StringIO()
        return self
    def __exit__(self, *args):
        self.extend(self._stringio.getvalue().splitlines())
        del self._stringio
        sys.stdout = self._stdout

test_cases = [
    ("3\n110", "1"),
    ("2\n10", "0"),
    ("2\n11", "1"),
    ("3\n111", "1"),
    ("4\n1000", "0"),
    ("5\n10101", "3"),
    ("10\n" + "1" * 10, "1"),
    ("20\n" + "1" * 20, "1"),
    ("20\n" + "1" + "0" * 19, "0"),
]

@pytest.mark.parametrize("input_data, expected_output", test_cases)
def test_main_logic(input_data, expected_output, monkeypatch):
    monkeypatch.setattr('sys.stdin', io.StringIO(input_data))
    with Capturing() as output:
        main_logic()

    assert len(output) == 1, f"Expected 1 line of output, got {len(output)}"
    assert output[0] == expected_output, f"Input: {input_data}, Expected: {expected_output}, Got: {output[0]}"