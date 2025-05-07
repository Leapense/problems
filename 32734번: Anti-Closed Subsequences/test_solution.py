import pytest
from solution import solve
from io import StringIO
import sys

def is_anti_closed(subsequence: list[int]) -> bool:
    if not subsequence:
        return True
    
    s_set = set(subsequence)

    for i in range(len(subsequence)):
        for j in range(len(subsequence)):
            x = subsequence[i]
            y = subsequence[j]
            target_sum = x + y
            if target_sum in s_set:
                return False
    return True

def run_test_case(input_data, capsys):
    original_stdin = sys.stdin
    sys.stdin = StringIO(input_data)

    solve()
    
    sys.stdin = original_stdin
    captured_output = capsys.readouterr().out.strip()

    lines = input_data.strip().split('\n')
    n = int(lines[0])
    a_str = lines[1].split()
    a = [int(x) for x in a_str]

    b_str = captured_output.split()
    assert len(b_str) == n, "Output length mismatch"
    b = [int(x) for x in b_str]

    groups = {}
    for i in range(n):
        val_a = a[i]
        group_idx = b[i]

        assert 1 <= group_idx <= 60, f"Group index {group_idx} out of bounds [1, 60]"

        if group_idx not in groups:
            groups[group_idx] = []
        groups[group_idx].append(val_a)
    for group_idx, subsequence in groups.items():
        assert is_anti_closed(subsequence), f"Subsequence for group {group_idx} is not anti-closed: {subsequence}"

@pytest.mark.parametrize("input_data", [
    (
        "15\n"
        "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"
    ),
    (
        "3\n"
        "250000000000000000 500000000000000000 1000000000000000000"
    ),
    (
        "1\n"
        "100"
    ),
    (
        "5\n"
        "1 10 100 1000 10000"
    ),
    (
        "4\n"
        "7 8 10 13"
    ),
    (
        "10\n"
        " ".join(str(2**50 + i) for i in range(10))
    ),
    (
        "5\n"
        "1 2 4 8 16"
    )
])
def test_solution_logic(input_data, capsys):
    n_val = int(input_data.strip().split('\n')[0])
    if n_val > 200 and len(input_data.strip().split('\n')[1].split()) > 200:
        pytest.skip("Skipping full anti-closed check for large N in pytest environment due to potential slowness.")
    run_test_case(input_data, capsys)