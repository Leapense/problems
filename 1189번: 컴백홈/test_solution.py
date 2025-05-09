import pytest
from solution import solve
import io
import sys

def run_solve_with_input(monkeypatch, capsys, input_str):
    monkeypatch.setattr('sys.stdin', io.StringIO(input_str))
    solve()
    captured = capsys.readouterr()
    return captured.out.strip()

def test_sample_1(monkeypatch, capsys):
    input_data = """3 4 6
....
.T..
...."""
    expected_output = "4"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_no_path_possible_obstacle_at_start(monkeypatch, capsys):
    input_data = """1 1 1
T"""
    expected_output = "0"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_1x1_grid_k1(monkeypatch, capsys):
    input_data = """1 1 1
."""
    expected_output = "1"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_1x1_grid_k_too_large(monkeypatch, capsys):
    input_data = """1 1 2
."""
    expected_output = "0"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_straight_path_1x5_k5(monkeypatch, capsys):
    input_data = """1 5 5
....."""
    expected_output = "1"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_straight_path_k_mismatch(monkeypatch, capsys):
    input_data = """1 5 4
....."""
    expected_output = "0"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_meandering_path(monkeypatch, capsys):
    input_data = """2 2 4
..
.."""
    expected_output = "1"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_no_path_k_too_small_2x2_k2(monkeypatch, capsys):
    input_data = """2 2 2
..
.."""
    expected_output = "0"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_all_T_grid(monkeypatch, capsys):
    input_data = """3 3 5
TTT
TTT
TTT"""
    expected_output = "0" # Start (2,0) is 'T'
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_target_is_T(monkeypatch, capsys):
    # Start (1,0), Target (0,1) which is 'T'
    input_data = """2 2 3
.T
.."""
    expected_output = "0"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_complex_case_from_description_style(monkeypatch, capsys):
    # Based on one of the image examples (modified for this problem's start/end)
    # Map:
    # ..gh  (0,C-1) is (0,3)
    # .Tfe
    # abcd  (R-1,0) is (2,0)
    # K = 8
    # A path: (2,0)a -> (2,1)b -> (2,2)c -> (1,2)f -> (1,1)T X (cannot go)
    # (2,0)a -> (1,0)X (not in example)
    # (2,0)a -> (2,1)b -> (2,2)c -> (2,3)d -> (1,3)e -> (0,3)h -> (0,2)g -> (0,1)f (len 8)
    # This is a path: (2,0)->(2,1)->(2,2)->(2,3)->(1,3)->(0,3)->(0,2)->(0,1)
    # Let's try a simpler one that should have a result.
    # Consider a 3x3 grid, K=5
    # ... (0,0) (0,1) (0,2)E
    # .T.
    # S.. (2,0) (2,1) (2,2)
    # Path: (2,0)->(2,1)->(1,1)X
    # Path: (2,0)->(1,0)->(0,0)->(0,1)->(0,2) len 5. (1 path)
    # Path: (2,0)->(2,1)->(2,2)->(1,2)->(0,2) len 5. (1 path)
    input_data = """3 3 5
...
.T.
..."""
    expected_output = "2"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_no_path_due_to_T_blocking_all_routes(monkeypatch, capsys):
    input_data = """3 3 5
..E
.T.
S.."""
    # Grid:
    # ..E
    # .T.
    # S..
    # Start (2,0), End (0,2)
    # Path (2,0)->(1,0)->(0,0)->(0,1)->(0,2) length 5.
    # Path (2,0)->(2,1)->(2,2)X (dead end or must go up)
    # Path (2,0)->(2,1) -> up to (1,1) is T.
    # So only one path.
    input_data_actual = """3 3 5
...
.T.
...""" # Same as above, just to be clear.
    expected_output = "2"
    assert run_solve_with_input(monkeypatch, capsys, input_data_actual) == expected_output