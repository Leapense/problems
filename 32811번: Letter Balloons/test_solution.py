import sys
import io
import pytest
from solution import max_teams, solve

def test_sample1():
    p = 23
    teams = ["WMU", "SI", "MI", "TTT", "XT"]
    assert max_teams(p, teams) == 2

def test_sample2():
    p = 6
    teams = ["ABC", "BDE", "ABE", "BF", "BF", "CEF"]
    assert max_teams(p, teams) == 1

def test_all_invalid():
    p = 3
    teams = ["AAA", "DDD", "ABA", "ABCD"]
    assert max_teams(p, teams) == 0

def test_simple_disjoint():
    p = 5
    teams = ["AB", "CD", "E", "B", "ACE"]
    assert max_teams(p, teams) == 3

def test_duplicates_conflict():
    p = 4
    teams = ["AB", "AB", "BC", "CD"]
    assert max_teams(p, teams) == 2

def run_solve_io(input_str: str) -> str:
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    try:
        sys.stdin = io.StringIO(input_str)
        sys.stdout = io.StringIO()
        solve()
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

def test_solve_sample1_io():
    input_data = """\
23 5
WMU
SI
MI
TTT
XT
"""
    assert run_solve_io(input_data) == "2"

def test_solve_sample2_io():
    input_data = """\
6 6
ABC
BDE
ABE
BF
BF
CEF
"""
    assert run_solve_io(input_data) == "1"