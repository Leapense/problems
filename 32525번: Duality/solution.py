import sys

def solve():
    input = sys.stdin.readline
    T = int(input().strip())
    M = 300_000_000
    out_lines = []
    for _ in range(T):
        N = int(input().strip())
        pts = []
        for i in range(1, N + 1):
            x, y = map(int, input().split())
            pts.append((i, x, y))
        for i, x, y in pts:
            out_lines.append(f"{i} {x + 1} {y + M}")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()