import sys

def solve():
    n = int(sys.stdin.readline())
    if n == 1:
        print("-1 1")
        return
    result = []
    for _ in range(n - 1):
        result.extend([1, -1])
    result.extend([-1, 1])

    print(*result)

solve()