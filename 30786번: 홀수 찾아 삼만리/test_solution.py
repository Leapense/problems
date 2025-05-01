import sys
from io import StringIO
import pytest
import solution

def run_input(input_data: str) -> str:
    backup_stdin, backup_stdout = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = StringIO(input_data), StringIO()

    try:
        solution.solve()
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = backup_stdin, backup_stdout

def manhattan_total(parity_list, order, coords):
    total = 0
    for i in range(len(order) - 1):
        x1, y1 = coords[order[i] - 1]
        x2, y2 = coords[order[i + 1] - 1]
        total += abs(x1 - x2) + abs(y1 - y2)
    return total

def test_sample1():
    inp = """
3
1 2
2 4
3 1
"""

    out = run_input(inp).splitlines()
    assert out[0] == "YES"
    perm = list(map(int, out[1].split()))
    assert sorted(perm) == [1,2,3]
    coords = [(1,2),(2,4),(3,1)]
    total = manhattan_total(None, perm, coords)
    assert total % 2 == 1


def test_sample2():
    inp = """
2
4 4
1 1
"""
    out = run_input(inp).strip()
    assert out == "NO"

@pytest.mark.parametrize("coords", [
    [(0,0),(1,0)],
    [(0,0),(2,2),(4,4)],
    [(1,1),(2,3),(4,5),(6,7),(8,2)],
])
def test_various(coords):
    n = len(coords)
    inp = str(n) + "\n" + "\n".join(f"{x} {y}" for x, y in coords) + "\n"
    out = run_input(inp).splitlines()
    _check_output(coords, out)

def _check_output(coords, out):
    parities = [(x+y)&1 for x,y in coords]
    n = len(coords)
    if all(p == parities[0] for p in parities):
        assert out[0] == "NO"
    else:
        assert out[0] == "YES"
        perm = list(map(int, out[1].split()))
        assert sorted(perm) == list(range(1, n+1))
        total = manhattan_total(None, perm, coords)
        assert total % 2 == 1
