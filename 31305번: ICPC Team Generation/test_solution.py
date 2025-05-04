import pytest
from solution import max_teams

# Sample from the prompt
def test_sample1():
    n = 6
    a = [1, 1, 2, 2, 2, 5]
    b = [2, 2, 5, 6, 6, 6]
    assert max_teams(n, a, b) == 1

# All intervals full [1..n] → floor(n/3)
@pytest.mark.parametrize("n", [3, 4, 5, 6, 7, 50])
def test_full_range(n):
    a = [1]*n
    b = [n]*n
    assert max_teams(n, a, b) == n//3

# No possible triple
def test_none():
    n = 5
    # Very restrictive: each only allows itself
    a = list(range(1,6))
    b = list(range(1,6))
    assert max_teams(n, a, b) == 0

# Only one sparse triple possible
def test_single_sparse():
    n = 5
    # Allow only triple (1,3,5)
    a = [1, 3, 1, 5, 1]
    b = [5, 3, 5, 5, 5]
    # (i,k) = (1,3) also ok, but needs j=2; check implicitly
    # The only fully valid is (1,3,5), so answer=1
    assert max_teams(n, a, b) == 1

# Largest n with random but trivial structure
def test_chain():
    n = 9
    a = [1,1,1,1,1,1,1,1,1]
    b = [3,4,5,6,7,8,9,9,9]
    # possible triples: any i≤6,k≤b[i], so many—but maximum is floor(9/3)=3
    assert max_teams(n, a, b) == 3