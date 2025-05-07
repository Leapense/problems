import sys
from math import isqrt

def divisors(n: int):
    small, large = [], []
    for d in range(1, isqrt(n) + 1):
        if n % d == 0:
            if n > 1:
                small.append(d)
            partner = n // d
            if partner != d and d != 1:
                large.append(partner)
    return small + large[::-1]

def possible(arr):
    n = len(arr)
    for L in divisors(n):
        target = None
        ok = True
        lo = hi = None
        cnt = 0
        for v in arr:
            if cnt == 0:
                lo = hi = v
            else:
                lo = min(lo, v)
                hi = max(hi, v)
            cnt += 1
            if cnt == L:
                s = lo + hi
                if target is None:
                    target = s
                elif s != target:
                    ok = False
                    break
                cnt = 0
        if ok:
            return True
    return False

def main() -> None:
    rd = sys.stdin.readline
    N = int(rd())
    A = list(map(int, rd().split()))
    print(1 if possible(A) else 0)

if __name__ == "__main__":
    main()