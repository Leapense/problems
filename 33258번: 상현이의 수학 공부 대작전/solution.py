import sys
from bisect import bisect_right

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    N = next(it)
    A = [next(it) for _ in range(N)]
    L = next(it)

    A.sort()
    P = [0] * (N + 1)
    for i, v in enumerate(A, 1):
        P[i] = P[i - 1] + v

    def S(x: int) -> int:
        idx = bisect_right(A, x)
        c = N - idx
        sum_tail = P[N] - P[idx]
        return (N + c) * x - 2 * sum_tail

    maxA = A[-1]
    hi = max(maxA, (L + N - 1) // N)
    lo = -1

    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if S(mid) >= L:
            hi = mid
        else:
            lo = mid

    print(hi)

if __name__ == "__main__":
    main()