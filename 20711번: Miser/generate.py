#!/usr/bin/env python3
"""
Random test-case generator for the “Miser” visitor-tracking programs.

The script prints one or more complete instances of the input format
expected by the C / C++ solutions posted in the prompt.

Corner cases are injected first; afterwards a user-configurable number
of purely random instances are appended.
"""

import argparse
import random
import sys
from typing import List


def emit_instance(n: int, days: List[List[int]]) -> None:
    """Print one test instance to stdout."""
    print(n)
    for visitors in days:
        k = len(visitors)
        print(k, *visitors)


def corner_cases(n_max: int) -> List[tuple[int, List[List[int]]]]:
    """Return the five deterministic edge-case instances."""
    cases = []

    # 1. n = 1, one visitor
    cases.append((1, [[1]]))

    # 2. n = 1, k = 0
    cases.append((1, [[]]))

    # 3. Two days, same visitor appears both days
    cases.append((2, [[7], [7]]))

    # 4. Max n, everybody stays home
    cases.append((n_max, [[] for _ in range(n_max)]))

    # 5. Max n, new unique visitor each day
    cases.append((n_max, [[i + 1] for i in range(n_max)]))

    return cases


def random_instance(n_max: int, k_max: int, id_max: int) -> tuple[int, List[List[int]]]:
    """Generate a single random instance within the provided bounds."""
    n = random.randint(1, n_max)
    days: List[List[int]] = []
    for _ in range(n):
        k = random.randint(0, k_max)
        visitors = [random.randint(1, id_max) for _ in range(k)]
        days.append(visitors)
    return n, days


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate random Miser test cases.")
    parser.add_argument("--n-max", type=int, default=100_000, help="upper bound for n (days)")
    parser.add_argument("--k-max", type=int, default=1_000,   help="upper bound for k (visitors per day)")
    parser.add_argument("--id-max", type=int, default=100_000, help="upper bound for visitor IDs")
    parser.add_argument("--extra",  type=int, default=3,       help="how many extra random instances")
    parser.add_argument("--seed",   type=int, default=None,    help="PRNG seed for reproducibility")
    args = parser.parse_args()

    if args.seed is not None:
        random.seed(args.seed)

    # 1️⃣ Deterministic corner cases
    for n, days in corner_cases(args.n_max):
        emit_instance(n, days)
        print()  # blank line separator

    # 2️⃣ Additional random instances
    for _ in range(args.extra):
        n, days = random_instance(args.n_max, args.k_max, args.id_max)
        emit_instance(n, days)
        print()


if __name__ == "__main__":
    main()