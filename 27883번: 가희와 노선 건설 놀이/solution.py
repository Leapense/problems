import sys

def solve():
    input = sys.stdin.readline
    n, m = map(int, input().split())
    rs = [int(input().strip()) for _ in range(m)]

    Q = 1 + 2 * m
    out = []
    out.append(str(Q))
    out.append("U 1 -1")
    for i, r in enumerate(rs, start=1):
        x = 1 + r
        out.append(f"U {x} {i}")
        out.append("P")
    print("\n".join(out))

if __name__ == "__main__":
    solve()