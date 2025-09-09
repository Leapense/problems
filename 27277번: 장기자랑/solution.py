import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    N = int(input_data[0])
    A = list(map(int, input_data[1:]))
    A.sort()
    M = A[-1]
    rest = A[:-1]
    m = (N - 1) // 2

    lows = rest[:m]
    highs = rest[-m:] if m > 0 else []

    ans = M + sum(highs) - sum(lows)
    print(ans)

if __name__ == "__main__":
    solve()