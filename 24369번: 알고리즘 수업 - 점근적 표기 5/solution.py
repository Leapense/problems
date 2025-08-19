import sys
import math
from typing import Tuple

def read_input() -> Tuple[int, int, int, int, int]:
    data = sys.stdin.read().strip().split()
    a2 = int(data[0])
    a1 = int(data[1])
    a0 = int(data[2])
    c = int(data[3])
    n0 = int(data[4])
    return a2, a1, a0, c, n0

def d_value(a2: int, a1: int, a0: int, c: int, n: int) -> int:
    return (a2 - c) * n * n + a1 * n + a0

def satisfies_omega(a2: int, a1: int, a0: int, c: int, n0: int) -> int:
    d2 = a2 - c
    if d2 < 0:
        return 0
    if d2 == 0:
        if a1 < 0:
            return 0
        return 1 if a1 * n0 + a0 >= 0 else 0
    n_star = -a1 / (2.0 * d2)
    candidates = set()
    candidates.add(n0)
    candidates.add(n0 + 1)
    if n_star >= n0:
        lo = int(math.floor(n_star))
        hi = int(math.ceil(n_star))
        if lo < n0:
            lo = n0
        candidates.add(lo)
        candidates.add(hi)
    min_val = min(d_value(a2, a1, a0, c, n) for n in candidates if n >= n0)
    return 1 if min_val >= 0 else 0

def main() -> None:
    a2, a1, a0, c, n0 = read_input()
    result = satisfies_omega(a2, a1, a0, c, n0)
    print(result)

if __name__ == "__main__":
    main()