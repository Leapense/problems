import argparse
import random
import sys
from typing import List

def tiny_case(n_max: int):
    n = random.randint(1, min(5, n_max))
    cows = [random.randint(0, 10) for _ in range(n)]
    stalls = [random.randint(0, 10) for _ in range(n)]
    return n, cows, stalls

def all_cows_too_big(n_max: int):
    n = random.randint(1, n_max)
    big = 10**9
    cows = [big + random.randint(1, 100) for _ in range(n)]
    stalls = [big - random.randint(1, 100) for _ in range(n)]
    return n, cows, stalls

def identical_multiset(n_max: int):
    n = random.randint(1, n_max)
    values = [random.randint(0, 10**6) for _ in range(n)]
    return n, values[:], values[:]

def overflow_hunter(n_max: int):
    n = random.randint(51, max(51, n_max))
    base = random.randint(1, 10**12)
    cows = [base + i for i in range(n)]
    stalls = [base + n + i for i in range(n)]
    random.shuffle(cows), random.shuffle(stalls)
    return n, cows, stalls

def adversarial_order(n_max: int):
    n = random.randint(1, n_max)
    cows = list(range(n, 0, -1))
    stalls = list(range(1, n + 1))
    return n, cows, stalls

def random_noise(n_max: int):
    n = random.randint(1, n_max)
    upper = 10**18
    cows = [random.randint(0, upper) for _ in range(n)]
    stalls = [random.randint(0, upper) for _ in range(n)]
    return n, cows, stalls

SCENARIOS = [
    tiny_case,
    all_cows_too_big,
    identical_multiset,
    overflow_hunter,
    adversarial_order,
    random_noise,
]

def emit_case(n: int, cows: List[int], stalls: List[int]) -> None:
    sys.stdout.write(f"{n}\n")
    sys.stdout.write(" ".join(map(str, cows)) + "\n")
    sys.stdout.write(" ".join(map(str, stalls)) + "\n")

def main() -> None:
    parser = argparse.ArgumentParser(description="Generate test cases for the cow-stall assignment problem.")
    parser.add_argument("--cases", type=int, default=1, help="Number of test cases to emit")
    parser.add_argument("--n-max", type=int, default=3000, help="Maximum n per test case")
    parser.add_argument("--seed", type=int, default=None, help="RNG seed for reproducibility")
    args = parser.parse_args()
    if args.seed is not None:
        random.seed(args.seed)

    for _ in range(args.cases):
        scenario = random.choice(SCENARIOS)
        n, cows, stalls = scenario(args.n_max)
        emit_case(n, cows, stalls)

if __name__ == "__main__":
    main()