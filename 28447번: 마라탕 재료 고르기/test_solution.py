import pytest
from solution import max_taste

def test_sample1():
    n, k = 4, 3
    C = [
        [0, 1, 2, 3],
        [1, 0, -2, 6],
        [2, -2, 0, 5],
        [3, 6, 5, 0]
    ]
    assert max_taste(n, k, C) == 10

def test_sample2():
    n, k = 4, 1
    C = [
        [0, 1, 2, 3],
        [1, 0, -2, 6],
        [2, -2, 0, 5],
        [3, 6, 5, 0]
    ]
    assert max_taste(n, k, C) == 0

def test_single():
    assert max_taste(1, 1, [[0]]) == 0

def test_negative():
    n, k = 3, 2
    C = [
        [0, -5, -1],
        [-5, 0, -2],
        [-1, -2, 0]
    ]
    assert max_taste(n, k, C) == -1
