import pytest
from solution import solve_shortcuts
import io
import sys

def run_solve_with_input(monkeypatch, capsys, input_str):
    monkeypatch.setattr('sys.stdin', io.StringIO(input_str))
    solve_shortcuts()
    captured = capsys.readouterr()
    return captured.out.strip()

def test_sample_1(monkeypatch, capsys):
    input_data = """5 150
0 50 10
0 50 20
50 100 10
100 151 10
110 140 90"""
    expected_output = "70"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_sample_2(monkeypatch, capsys):
    input_data = """2 100
10 60 40
50 90 20"""

    expected_output = "80"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_sample_3(monkeypatch, capsys):
    input_data = """8 900
0 10 9
20 60 45
80 190 100
50 70 15
160 180 14
140 160 14
420 901 5
450 900 0"""
    expected_output = "432"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_no_shortcuts(monkeypatch, capsys):
    input_data = """0 100"""
    expected_output = "100"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_one_shortcut_not_useful(monkeypatch, capsys):
    input_data = """1 100
0 50 60"""
    expected_output = "100"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_one_shortcut_very_useful(monkeypatch, capsys):
    input_data = """1 100
0 100 10"""
    expected_output = "10"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_shortcut_beyond_D_is_ignored(monkeypatch, capsys):
    input_data = """1 100
0 110 10"""
    expected_output = "100"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_overlapping_shortcuts(monkeypatch, capsys):
    input_data = """2 100
0 60 10
30 90 10"""
    expected_output = "50"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output

def test_chaining_shortcuts(monkeypatch, capsys):
    input_data = """2 100
0 50 10
50 100 10"""
    expected_output = "20"
    assert run_solve_with_input(monkeypatch, capsys, input_data) == expected_output