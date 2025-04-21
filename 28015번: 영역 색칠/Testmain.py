import sys
from io import StringIO
import pytest

def solve():
    import sys
    input = sys.stdin.readline
    N, M = map(int, input().split())
    ans = 0
    for _ in range(N):
        prev = 0
        for x in map(int, input().split()):
            if x != 0 and x != prev:
                ans += 1
            prev = x
    print(ans)

def run(inp):
    backup_i, backup_o = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = StringIO(inp), StringIO()
    try:
        solve()
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = backup_i, backup_o

def test_sample1():
    inp = "2 2\n2 1\n0 0\n"
    assert run(inp) == "2"

def test_sample2():
    inp = (
        "4 4\n"
        "1 0 0 1\n"
        "1 1 2 2\n"
        "0 0 1 2\n"
        "0 1 1 1\n"
    )
    assert run(inp) == "7"