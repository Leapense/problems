import pytest
from solution import tight_word_percent

@pytest.mark.parametrize("k, n, expected", [
    (4, 1, 100.00000),
    (2, 5, 40.74074),
    (3, 5, 17.38281),
    (8, 7, 0.10130),
    (0, 1, 100.00000),
    (1, 2, 100.00000),
    (2, 2, 77.77778),
])
def test_tight_word_percent(k, n, expected):
    result = tight_word_percent(k, n)
    assert abs(result - expected) < 1e-4