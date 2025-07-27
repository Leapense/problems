import argparse
import os
import random
import sys
from math import gcd, isqrt

_SMALL_PRIMES = (
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61
)

def _is_probable_prime(n: int) -> bool:
    if n < 2:
        return False
    for p in _SMALL_PRIMES:
        if n % p == 0:
            return n == p
        
    d, s = n - 1, 0
    while d & 1 == 0:
        d //= 2
        s += 1
    for a in (2, 7, 61):
        x = pow(a, d, n)
        if x in (1, n - 1):
            continue
        for _ in range(s - 1):
            x = x * x % n
            if x == n - 1:
                break
        else:
            return False
    return True

def _random_prime(low: int, high: int) -> int:
    while True:
        cand = random.randint(low | 1, high)
        if cand % 2 == 0:
            cand += 1
        if _is_probable_prime(cand):
            return cand
        
def all_ones(n: int, v_max: int) -> list[int]:
    return [1] * n

def all_same_prime(n: int, v_max: int) -> list[int]:
    p = _random_prime(2, min(v_max, 10 ** 6))
    return [p] * n

def all_distinct_large_primes(n: int, v_max: int) -> list[int]:
    low = max(2, v_max // 4)
    vals = set()
    while len(vals) < n:
        vals.add(_random_prime(low, v_max))
    return list(vals)

def dense_small_factors(n: int, v_max: int) -> list[int]:
    small = [2, 3, 5]
    return [
        random.choice(small) * random.randint(1, v_max // max(small))
        for _ in range(n)
    ]

def mixed_values(n: int, v_max: int) -> list[int]:
    half = n // 2
    part1 = [random.randint(1, v_max) for _ in range(half)]
    part2 = all_distinct_large_primes(n - half, v_max)
    return part1 + part2

def random_uniform(n: int, v_max: int) -> list[int]:
    return [random.randint(1, v_max) for _ in range(n)]

_CASE_FUNCS = [
    (all_ones, 1),
    (all_same_prime, 1),
    (all_distinct_large_primes, 1),
    (dense_small_factors, 2),
    (mixed_values, 2),
    (random_uniform, 3),
]

def _choose_case_func():
    funcs, weights = zip(*_CASE_FUNCS)
    return random.choices(funcs, weights)[0]

def _single_case(n_max: int, v_max: int) -> tuple[int, list[int]]:
    n = random.randint(1, n_max)
    values = _choose_case_func()(n, v_max)
    assert len(values) == n
    assert all(1 <= v <= v_max for v in values)
    return n, values

def main() -> None:
    ap = argparse.ArgumentParser(
        description="Generate random test cases for the friendly-sequence solver."
    )
    ap.add_argument("--cases", type=int, default=1, help="How many cases to emit")
    ap.add_argument("--n-max", type=int, default=1000, help="Upper bound for N")
    ap.add_argument("--v-max", type=int, default=10**9, help="Upper bound for A_i")
    ap.add_argument("--seed", type=int, default=None, help="PRNG seed (optional)")
    args = ap.parse_args()

    if args.seed is not None:
        random.seed(args.seed)

    if args.cases == 1:
        n, vals = _single_case(args.n_max, args.v_max)
        print(n)
        print(*vals)
    else:
        os.makedirs("inputs", exist_ok=True)
        for idx in range(1, args.cases + 1):
            n, vals = _single_case(args.n_max, args.v_max)
            fname = f"inputs/input_{idx:02}.txt"
            with open(fname, "w") as f:
                f.write(str(n) + "\n")
                f.write(" ".join(map(str, vals)) + "\n")
        print(f"Wrote {args.cases} files to ./inputs/")
    
if __name__ == "__main__":
    main()