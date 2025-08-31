import sys

def v2(t: int) -> int:
    return (t & -t).bit_length() - 1

def solve() -> None:
    data = sys.stdin.read().strip().split()
    N, x, y = map(int, data)
    vx, vy = v2(x), v2(y)
    if vx != vy:
        print(-1)
        return
    print(N - vx - 1)

if __name__ == "__main__":
    solve()