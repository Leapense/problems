import pytest
import io
import sys
import runpy

from balance_solver import find_balance_point, main, MAX_WEIGHT

@pytest.mark.parametrize("m, weights, expected_t", [
    (7, [6, 1, 1, 1, 1, 1, 1], 2),
    (1, [5], 5),
    (3, [3,  3, 3], 3),
    (4, [1, 2, 3, 6], 4),
    (5, [1, 2, 3, 4, 5], None),
    (2, [1, MAX_WEIGHT], None),
    (0, [], 1),
    (3, [1000, 2000, 1000], 1001),
])

def test_find_balance_point_parametrized(m, weights, expected_t):
    assert find_balance_point(m, weights) == expected_t

@pytest.mark.parametrize("input_str, expected_output", [
    ("7 6 1 1 1 1 1 1", "2"),
    ("1 5", "5"),
    ("3 3 3 3", "3"),
    ("4 1 2 3 6", "4"),
    ("5 1 2 3 4 5", ""),
    (f"2 1 {MAX_WEIGHT}", ""),
    ("0", "1"),
    ("3 1000 2000 1000", "1001"),
    ("", ""),
])
def test_main_script_io(monkeypatch, capsys, input_str, expected_output):
    monkeypatch.setattr('sys.stdin', io.StringIO(input_str))
    main()
    captured = capsys.readouterr()
    assert captured.out == expected_output