import pytest
from Main import max_pair_sum

@pytest.mark.parametrize("prices, x, expected", [
    # Sample from statement
    ([5, 3, 10, 2, 4, 9], 18, 15),
    # two smallest
    ([1, 2], 3, 3),
    # exact budget match
    ([8, 1, 2, 9, 7], 16, 16),  # 9+7
    # skip too‑expensive items
    ([100, 1, 1, 2], 3, 3),      # 1+2
    # duplicates allowed but must pick distinct indices
    ([5, 5, 5], 10, 10),
    # large budget
    ([1, 2, 3, 4, 5], 100, 9),   # 4+5
    # only one valid under budget
    ([10, 20, 30, 5], 15, 15),    # 10+5
])
def test_max_pair_sum(prices, x, expected):
    assert max_pair_sum(prices, x) == expected