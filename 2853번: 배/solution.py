from __future__ import annotations
import sys
from math import isqrt, ceil
from functools import lru_cache


# ────────────────────────────────────────────────────────────────────────
# helpers
# ────────────────────────────────────────────────────────────────────────
def divisors(n: int) -> list[int]:
    ds = {1, n}
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            ds.add(i)
            ds.add(n // i)
    return list(ds)


# ────────────────────────────────────────────────────────────────────────
def minimum_ships(days: list[int]) -> int:
    n = len(days)
    T = days[-1]
    day_set = set(days)

    lower_bound = ceil((T - 1) / (n - 1))

    @lru_cache(maxsize=None)
    def good(p: int) -> bool:
        """is `p` a feasible period? ( ≤ 5 000 membership checks )"""
        d = 1 + p
        while d <= T:
            if d not in day_set:
                return False
            d += p
        return True

    candidate_periods: set[int] = set()
    for d in (x - 1 for x in days[1:]):          # skip day 1 ( d == 0 )
        for div in divisors(d):
            if div >= lower_bound and div not in candidate_periods:
                if good(div):
                    candidate_periods.add(div)

    good_periods = sorted(candidate_periods)      # small → large
    chosen: list[int] = []

    for d in (x - 1 for x in days[1:]):
        # covered already?
        if any(d % p == 0 for p in chosen):
            continue
        # find the first ( = smallest ) good divisor
        for p in good_periods:
            if d % p == 0:
                chosen.append(p)
                break
        else:
            raise RuntimeError("Internal error: no covering period found")

    return len(chosen)


def main() -> None:
    it = iter(map(int, sys.stdin.read().split()))
    n = next(it)
    days = [next(it) for _ in range(n)]
    print(minimum_ships(days))

if __name__ == "__main__":
    main()