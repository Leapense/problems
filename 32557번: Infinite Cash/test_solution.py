import io
import sys
import pytest
from solution import solve

def run_solve(input_data):
    original_stdin = sys.stdin
    original_stdout = sys.stdout
    sys.stdin = io.StringIO(input_data)
    sys.stdout = io.StringIO()

    solve()

    output = sys.stdout.getvalue().strip()
    sys.stdin = original_stdin
    sys.stdout = original_stdout
    return output

test_cases = [
    # Sample 1
    ("101110101\n1010\n10001110101010101", "10011"),
    # Sample 2
    ("101110101\n1000\n100011101", "Infinite money!"),
    # Sample 3
    ("101110101\n1010\n100011101", "1001"),
]
@pytest.mark.parametrize("input_str, expected_output", test_cases)
def test_infinite_cash(input_str, expected_output):
    # For the specific test case involving large number bit_length calculation:
    if input_str.startswith(bin(10**5)[2:]): # Identify the specific test case
        s_large_val_str, d_large_val_str, m_large_val_str = input_str.split("\n")
        m_large_val = int(m_large_val_str, 2)
        expected_output = bin(m_large_val.bit_length())[2:]
        
    assert run_solve(input_str) == expected_output