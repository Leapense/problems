import pytest
from solution import solve
import io
import sys

@pytest.mark.parametrize("k_input, expected_output", [
    ("37\n", "1 3\n"),
    ("25\n", "Impossible\n"),
    ("999\n", "9 3\n"),
    ("1\n", "1 1\n"),
    ("7\n", "7 1\n"),
    ("13\n", "1 6\n"),
    ("49\n", "7 6\n"),
    ("101\n", "4 4\n"),
    ("23\n", "1 22\n"),
    ("6\n", "6 1\n"),
])
def test_calculator_game(k_input, expected_output, monkeypatch):
    monkeypatch.setattr('sys.stdin', io.StringIO(k_input))
    captured_output = io.StringIO()
    monkeypatch.setattr('sys.stdout', captured_output)

    solve()
    assert captured_output.getvalue() == expected_output