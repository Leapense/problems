#!/usr/bin/env python3
"""
Random test generator for the provided solver.

Input format produced:
- First line: T (number of test cases)
- Next T lines: n k (space-separated, any whitespace acceptable)

Design goals:
- Avoid k = 0 to prevent division by zero in q = s // k.
- Include curated edge cases: s = 0 (n = 1), s < k (q = 0), q = 1,
  q equal to triangular numbers with even/odd parity of t, and q just
  below/above a triangular number.
- Mix in broad random coverage across large ranges.
- Reproducible with --seed; configurable ranges for n and k.

Usage examples:
  python3 gen.py > input.txt
  python3 gen.py -t 50 --seed 123
  python3 gen.py -t 1000 --max-n 1000000000000000000 --max-k 1000000000000000000
  python3 gen.py -t 200 --no-curated
"""

import argparse
import math
import random
from typing import List, Optional, Tuple

IntPair = Tuple[int, int]


def tri(t: int) -> int:
    return t * (t + 1) // 2


def choose_t_with_parity(rng: random.Random, t_min: int, t_max: int, parity: Optional[str]) -> Optional[int]:
    """
    Choose integer t in [t_min, t_max] with desired parity:
    - parity=None: any t
    - parity='even' or 'odd'
    Returns None if no such t exists.
    """
    if t_min > t_max:
        return None
    if parity is None:
        return rng.randint(t_min, t_max)
    want_even = (parity == 'even')
    # Adjust bounds to match parity
    low = t_min if (t_min % 2 == 0) == want_even else t_min + 1
    high = t_max if (t_max % 2 == 0) == want_even else t_max - 1
    if low > high:
        return None
    steps = (high - low) // 2
    return low + 2 * rng.randint(0, steps)


def triangular_q_case(
    rng: random.Random,
    max_n: int,
    max_k: int,
    parity: Optional[str] = None,
    offset: int = 0
) -> Optional[IntPair]:
    """
    Construct (n, k) such that q = s // k equals tri(t) + offset for some t,
    where t can be constrained by parity. Keeps numbers within [1..max_n] and [1..max_k].
    Returns None if construction fails with current bounds.
    """
    if max_n < 1 or max_k < 1:
        return None

    # For feasibility: With k=1, we need q <= max_n - 1.
    # Let Tmax be the largest t with tri(t) <= max_n - 1 (safe baseline).
    # Note: if offset > 0, require tri(t) + offset <= max_n - 1.
    # We compute an upper bound on t using isqrt trick.
    # tri(t) ~ t^2/2 -> t ~ floor((sqrt(1 + 8X) - 1)/2) for tri(t) <= X
    X = max(0, max_n - 1 - max(offset, 0))
    if X == 0:
        return None
    t_max = (math.isqrt(1 + 8 * X) - 1) // 2
    if t_max < 1:
        return None

    # Favor a spread of t magnitudes. We'll attempt a few times.
    for _ in range(60):
        # Bias: pick small t sometimes, large t other times.
        if rng.random() < 0.5:
            # Small-ish t region
            t_hi = max(1, min(t_max, 10_000))
            t_lo = 1
        else:
            # Large t region
            t_lo = max(1, t_max - min(t_max - 1, 1_000_000))
            t_hi = t_max

        t = choose_t_with_parity(rng, t_lo, t_hi, parity)
        if t is None:
            continue

        q = tri(t) + offset
        if q <= 0:
            # We avoid q <= 0 here; handle q==0 separately with s<k case elsewhere.
            continue

        # Given q, must pick k in [1..min(max_k, (max_n - 1) // q)]
        k_hi = min(max_k, (max_n - 1) // q)
        if k_hi < 1:
            continue

        k = rng.randint(1, k_hi)
        # r in [0..min(k-1, (max_n - 1) - q*k)]
        r_hi = min(k - 1, (max_n - 1) - q * k)
        if r_hi < 0:
            # Shouldn't happen if k <= (max_n - 1) // q, but be safe.
            continue
        r = rng.randint(0, r_hi)
        s = q * k + r
        n = s + 1
        # Sanity checks
        if 1 <= n <= max_n and 1 <= k <= max_k and s // k == q:
            return (n, k)
    return None


def s_zero_case(rng: random.Random, max_k: int) -> Optional[IntPair]:
    if max_k < 1:
        return None
    k = rng.randint(1, max_k)
    n = 1  # s = n - 1 = 0
    return (n, k)


def s_lt_k_case(rng: random.Random, max_n: int, max_k: int) -> Optional[IntPair]:
    if max_n < 1 or max_k < 1:
        return None
    k = rng.randint(1, max_k)
    # s in [0..min(k-1, max_n-1)]
    s_hi = min(k - 1, max_n - 1)
    if s_hi < 0:
        return None
    s = rng.randint(0, s_hi)
    n = s + 1
    return (n, k)


def q_equal_case(rng: random.Random, max_n: int, max_k: int, q_val: int) -> Optional[IntPair]:
    """
    Construct s, k so that s // k = q_val.
    For q_val >= 1: choose k <= min(max_k, (max_n-1)//q_val) and then s = q_val*k + r.
    For q_val == 0: fallback to s<k construction.
    """
    if q_val <= 0:
        return s_lt_k_case(rng, max_n, max_k)
    if max_n < 1 or max_k < 1:
        return None
    k_hi = min(max_k, (max_n - 1) // q_val)
    if k_hi < 1:
        return None
    k = rng.randint(1, k_hi)
    r_hi = min(k - 1, (max_n - 1) - q_val * k)
    r = rng.randint(0, max(0, r_hi))
    s = q_val * k + r
    n = s + 1
    return (n, k)


def q_one_case(rng: random.Random, max_n: int, max_k: int) -> Optional[IntPair]:
    return q_equal_case(rng, max_n, max_k, 1)


def k_one_case(rng: random.Random, max_n: int) -> Optional[IntPair]:
    if max_n < 1:
        return None
    n = rng.randint(1, max_n)
    return (n, 1)


def near_max_case(rng: random.Random, max_n: int, max_k: int) -> Optional[IntPair]:
    """
    Choose n, k near their maxima to stress large arithmetic.
    """
    if max_n < 1 or max_k < 1:
        return None
    # Choose within the top window; ensure floor not below 1.
    def near_max(lo: int, hi: int, width: int) -> int:
        lo2 = max(lo, hi - max(1, width) + 1)
        return rng.randint(lo2, hi)

    n = near_max(1, max_n, width=1_000_000)
    k = near_max(1, max_k, width=1_000_000)
    return (n, k)


def n_large_k_small_case(rng: random.Random, max_n: int) -> Optional[IntPair]:
    if max_n < 1:
        return None
    n = rng.randint(max(1, max_n - 1_000_000), max_n)
    k = rng.randint(1, 1_000)
    return (n, k)


def uniform_case(rng: random.Random, min_n: int, max_n: int, min_k: int, max_k: int) -> Optional[IntPair]:
    if min_n > max_n or min_k > max_k or max_k < 1:
        return None
    n = rng.randint(min_n, max_n)
    k = rng.randint(max(1, min_k), max_k)
    return (n, k)


def build_curated_cases(rng: random.Random, min_n: int, max_n: int, min_k: int, max_k: int) -> List[IntPair]:
    """
    Produce a small set of hand-picked edge cases that exercise important branches.
    """
    cases: List[IntPair] = []
    def add(opt: Optional[IntPair]):
        if opt is not None:
            n, k = opt
            # Clamp up to min bounds if needed (n>=min_n, k>=min_k and >=1)
            if n < min_n:
                n = min_n
            if k < max(1, min_k):
                k = max(1, min_k)
            cases.append((n, k))

    # s == 0
    add(s_zero_case(rng, max_k))
    # s < k (q == 0) — a couple of them
    add(s_lt_k_case(rng, max_n, max_k))
    add(s_lt_k_case(rng, max_n, max_k))
    # q == 1
    add(q_one_case(rng, max_n, max_k))
    # k == 1
    add(k_one_case(rng, max_n))
    # q is triangular with even t
    add(triangular_q_case(rng, max_n, max_k, parity='even', offset=0))
    # q is triangular with odd t
    add(triangular_q_case(rng, max_n, max_k, parity='odd', offset=0))
    # q just below a triangular number (t >= 2 to keep q >= 1)
    add(triangular_q_case(rng, max_n, max_k, parity='even', offset=-1))
    # q just above a triangular number
    add(triangular_q_case(rng, max_n, max_k, parity=None, offset=1))
    # Near maxima
    add(near_max_case(rng, max_n, max_k))
    # Large n, small k
    add(n_large_k_small_case(rng, max_n))
    return cases


def random_mixed_case(
    rng: random.Random, min_n: int, max_n: int, min_k: int, max_k: int
) -> IntPair:
    """
    Produce a random case using a mixture of strategies.
    Guaranteed to return a valid pair given sane bounds.
    """
    # Strategy weights
    x = rng.random()
    # Try a specific category first; fall back as needed.
    candidates: List[Optional[IntPair]] = []

    if x < 0.12:
        candidates.append(s_zero_case(rng, max_k))
    elif x < 0.27:
        candidates.append(s_lt_k_case(rng, max_n, max_k))
    elif x < 0.42:
        candidates.append(q_one_case(rng, max_n, max_k))
    elif x < 0.62:
        # Triangular exact or +/- 1, with random parity
        parity = rng.choice([None, 'even', 'odd'])
        offset = rng.choice([0, 0, 0, -1, 1])  # favor exact triangular
        candidates.append(triangular_q_case(rng, max_n, max_k, parity=parity, offset=offset))
    elif x < 0.78:
        candidates.append(k_one_case(rng, max_n))
    elif x < 0.90:
        candidates.append(near_max_case(rng, max_n, max_k))
    else:
        candidates.append(n_large_k_small_case(rng, max_n))

    # Add uniform as a universal fall-back
    candidates.append(uniform_case(rng, min_n, max_n, min_k, max_k))

    for c in candidates:
        if c is not None:
            n, k = c
            # Enforce lower bounds
            n = max(n, min_n)
            k = max(k, max(1, min_k))
            return (n, k)

    # As a last resort, pick minimal viable pair
    return (max(1, min_n), max(1, min_k))


def main():
    ap = argparse.ArgumentParser(description="Random test generator for the given solver.")
    ap.add_argument("-t", "--tests", type=int, default=100, help="Number of test cases to generate (default: 100)")
    ap.add_argument("--min-n", type=int, default=1, help="Minimum n (inclusive, default: 1)")
    ap.add_argument("--max-n", type=int, default=10**18, help="Maximum n (inclusive, default: 1e18)")
    ap.add_argument("--min-k", type=int, default=1, help="Minimum k (inclusive, default: 1)")
    ap.add_argument("--max-k", type=int, default=10**18, help="Maximum k (inclusive, default: 1e18)")
    ap.add_argument("--seed", type=str, default=None, help="Random seed (str/int); if omitted, uses system entropy")
    ap.add_argument("--no-curated", action="store_true", help="Disable curated edge cases; use only random mix")
    args = ap.parse_args()

    # Prepare RNG
    if args.seed is None:
        rng = random.Random()
    else:
        try:
            # Accept int-like seeds or strings
            rng = random.Random(int(args.seed))
        except ValueError:
            rng = random.Random(args.seed)

    T = max(1, args.tests)
    min_n = max(1, args.min_n)
    max_n = max(min_n, args.max_n)
    min_k = max(1, args.min_k)
    max_k = max(min_k, args.max_k)

    cases: List[IntPair] = []
    curated: List[IntPair] = []

    if not args.no_curated:
        curated = build_curated_cases(rng, min_n, max_n, min_k, max_k)

    # Assemble final list
    for pair in curated:
        if len(cases) >= T:
            break
        cases.append(pair)

    while len(cases) < T:
        pair = random_mixed_case(rng, min_n, max_n, min_k, max_k)
        cases.append(pair)

    # Output
    print(len(cases))
    for n, k in cases:
        print(n, k)


if __name__ == "__main__":
    main()