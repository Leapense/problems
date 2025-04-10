import sys
import io
from collections import deque
import pytest # Required for running tests

# --- Solution Logic ---

# Function to read input faster (used by solve)
_input = sys.stdin.readline

def solve():
    """Reads input, solves the problem, and prints the output."""
    try:
        # Read n and k
        line1 = _input().split()
        if len(line1) != 2: return # Basic input check
        n, k = map(int, line1)

        # Basic constraint check based on problem statement
        if not (2 <= n <= 100000): return # n constraint
        if not (0 <= k < n): # k constraint check based on problem statement
             print("-1") # k is out of the specified range [0, n-1]
             # Need to consume remaining input lines if returning early
             # Or adjust logic if k out of range means "not found" -> -1
             # Assuming k outside [0, n-1] implies an issue or "not found"
             for _ in range(n - 1): _input()
             _input()
             return

        # Initialize adjacency list (storing children for each parent)
        adj = [[] for _ in range(n)]

        # Read edges and build adjacency list
        for _ in range(n - 1):
            line = _input().split()
            if len(line) != 2: return # Basic input check
            p, c = map(int, line)
            # Basic bounds check for nodes
            if 0 <= p < n and 0 <= c < n and p != c:
                 adj[p].append(c)
            else: return # Invalid edge

        # Read node values
        values_line = _input().split()
        if len(values_line) != n: return # Mismatch check
        values = list(map(int, values_line))

        # Build value_map: value -> node_index
        value_to_node_map = [-1] * n # Initialize with -1
        assigned_values = set() # To check uniqueness if needed (problem guarantees it)
        for i in range(n):
            node_value = values[i]
            # Check if value is in the expected range [0, n-1]
            if 0 <= node_value < n:
                 # Check for duplicate assignment (problem guarantees no duplicates)
                 # if node_value in assigned_values: return # Error: duplicate value
                 if value_to_node_map[node_value] != -1: return # Error: value assigned twice
                 value_to_node_map[node_value] = i
                 assigned_values.add(node_value)
            else:
                 # Value out of range [0, n-1], violates problem statement
                 # Handle as error or ignore based on interpretation
                 return # Treat as invalid input based on constraints

        # Find the target node index corresponding to value k
        # k is already checked to be in [0, n-1] range
        target_node = value_to_node_map[k]

        # If k was a possible value but wasn't assigned to any node
        # (Should not happen with unique values 0..n-1 constraint)
        if target_node == -1:
            print("-1") # Indicate value k not found in the assignments
            return

        # --- Calculate depth using BFS ---
        depths = [-1] * n
        queue = deque()
        result_depth = -1 # Initialize result depth

        # Start BFS from root 0
        if n > 0: # Root node 0 exists
            depths[0] = 0
            queue.append(0)
        else: # n=0 case (not possible by constraints n>=2)
             print("-1") # Or handle appropriately
             return

        while queue:
            current_node = queue.popleft()

            if current_node == target_node:
                result_depth = depths[current_node]
                break # Optimization: Found the target

            for child in adj[current_node]:
                # Check child validity and if visited
                if 0 <= child < n and depths[child] == -1:
                    depths[child] = depths[current_node] + 1
                    queue.append(child)

        # Print the calculated depth of the target node
        print(result_depth)

    except Exception as e:
        # Catch potential errors during input processing or execution
        # In competitive programming, often let it crash or print -1
        print("-1")


# --- Pytest Test Cases (Corrected to match constraints) ---

# Helper function to simulate stdin and capture stdout for tests
def run_solve_with_input(input_data):
    """Runs the solve function with mocked stdin and captures stdout."""
    original_stdin = sys.stdin
    original_stdout = sys.stdout
    global _input
    _input = io.StringIO(input_data).readline
    sys.stdout = io.StringIO()

    try:
        solve()
        output = sys.stdout.getvalue()
    finally:
        sys.stdin = original_stdin
        sys.stdout = original_stdout
        _input = sys.stdin.readline # Restore original input function
    return output.strip()

# Test Case 1: Sample Input 1 (Constraint-Compliant)
def test_sample_1():
    input_data = """8 5
0 1
0 2
1 3
1 4
2 5
2 6
6 7
0 1 2 3 4 5 6 7
"""
    expected_output = "2"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 2: Target is the Root Node (Corrected)
def test_root_node():
    input_data = """5 3
0 1
0 2
1 3
1 4
3 1 0 2 4
"""
    # k=3 is assigned to node 0. Depth = 0.
    expected_output = "0"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 3: Target is a Leaf Node (Corrected)
def test_leaf_node():
    input_data = """6 4
0 1
0 2
1 3
2 4
2 5
0 1 2 3 5 4
"""
    # k=4 is assigned to node 5. Path: 0 -> 2 -> 5. Depth = 2.
    expected_output = "2"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 4: Target Value k = 0 (Constraint-Compliant)
def test_target_value_zero():
    input_data = """7 0
0 1
0 2
1 3
1 4
2 5
2 6
5 1 2 3 4 0 6
"""
    # k=0 is assigned to node 5. Path: 0 -> 2 -> 5. Depth = 2.
    expected_output = "2"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 5: Linear Tree (Chain) (Corrected)
def test_linear_tree():
    input_data = """5 2
0 1
1 2
2 3
3 4
0 1 4 2 3
"""
    # k=2 is assigned to node 3. Path: 0 -> 1 -> 2 -> 3. Depth = 3.
    expected_output = "3"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 6: Slightly Larger/Deeper Tree (Corrected)
def test_larger_tree():
    input_data = """10 8
0 1
0 2
1 3
1 4
2 5
2 6
3 7
6 8
8 9
1 2 3 4 5 6 7 8 9 0
"""
    # k=8 is assigned to node 7. Path: 0 -> 1 -> 3 -> 7. Depth = 3.
    expected_output = "3"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 7: Minimum size n=2 (Constraint-Compliant)
def test_min_size():
    input_data = """2 1
0 1
0 1
"""
    # k=1 is assigned to node 1. Path: 0 -> 1. Depth = 1.
    expected_output = "1"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 8: Value k is assigned to root (n=2 case) (Constraint-Compliant)
def test_min_size_root_target():
    input_data = """2 0
0 1
0 1
"""
    # k=0 is assigned to node 0. Path: 0. Depth = 0.
    expected_output = "0"
    assert run_solve_with_input(input_data) == expected_output

# Test Case 9: Deep Node (Linear Tree) (Constraint-Compliant)
def test_deep_node():
    input_data = """10 9
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
0 1 2 3 4 5 6 7 8 9
"""
    # k=9 is assigned to node 9. Path: 0 -> ... -> 9. Depth = 9.
    expected_output = "9"
    assert run_solve_with_input(input_data) == expected_output


# --- Main Execution Block ---

if __name__ == "__main__":
    pytest.main()

# To run the tests:
# 1. Save this code as a Python file (e.g., combined_solution.py).
# 2. Make sure pytest is installed (`pip install pytest`).
# 3. Run `pytest combined_solution.py` in your terminal.