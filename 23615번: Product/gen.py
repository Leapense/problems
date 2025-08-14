#!/usr/bin/env python3
import argparse
import random

LONG_MIN = -(1 << 63)
LONG_MAX = (1 << 63) - 1

def sign(x: int) -> int:
    return -1 if x < 0 else 1

def rand_large_value(rng: random.Random, lo_abs=2, hi_abs=10**9) -> int:
    v = rng.randint(lo_abs, hi_abs)
    if rng.random() < 0.5:
        v = -v
    return v

def gen_two_zeros(rng: random.Random, n: int | None) -> list[int]:
    if n is None or n < 2:
        n = rng.randint(2, 60)
    zeros = rng.randint(2, min(10, n))
    rest = n - zeros
    arr = [0] * zeros
    for _ in range(rest):
        if rng.random() < 0.6:
            arr.append(1 if rng.random() < 0.5 else -1)
        else:
            arr.append(rand_large_value(rng, 2, 10**6))
    rng.shuffle(arr)
    return arr

def gen_one_zero(rng: random.Random, n: int | None) -> list[int]:
    if n is None or n < 1:
        n = rng.randint(1, 60)
    arr = [0]
    rest = n - 1
    for _ in range(rest):
        if rng.random() < 0.6:
            arr.append(1 if rng.random() < 0.5 else -1)
        else:
            arr.append(rand_large_value(rng, 2, 10 ** 6))
    rng.shuffle(arr)
    return arr

def gen_ones_even(rng: random.Random, n: int | None) -> list[int]:
    if n is None or n < 1:
        n = rng.randint(1, 60)
    
    neg_ones = rng.randrange(0, n + 1, 2)
    pos_ones = n - neg_ones
    arr = [-1] * neg_ones + [1] * pos_ones
    rng.shuffle(arr)
    return arr

def gen_ones_odd(rng: random.Random, n: int | None) -> list[int]:
    if n is None:
        n = rng.randint(1, 60)
    if n == 0:
        n = 1
    neg_ones = 1 if n == 1 else rng.randrange(1, n + 1, 2)
    pos_ones = n - neg_ones
    arr = [-1] * neg_ones + [1] * pos_ones
    rng.shuffle(arr)
    return arr

def gen_valid_candidate(rng: random.Random, n: int | None) -> list[int]:
    if n is None or n < 2:
        n = rng.randint(2, 60)
    max_k = min(5, n - 1)
    k = rng.randint(1, max_k)
    others = []
    prod_abs = 1
    sign_prod = 1
    for _ in range(k):
        v_abs = rng.randint(2, 9)
        v = v_abs if rng.random() < 0.5 else -v_abs
        prod_abs *= v_abs
        sign_prod *= sign(v)
        others.append(v)
    ones_count = n - (k + 1)
    neg_ones = rng.randint(0, ones_count) if ones_count > 0 else 0
    pos_ones = ones_count - neg_ones
    ones_sign = -1 if (neg_ones & 1) else 1
    candidate_sign = ones_sign * sign_prod
    candidate = candidate_sign * prod_abs
    arr = list(others) + [candidate] + [-1] * neg_ones + [1] * pos_ones
    rng.shuffle(arr)
    return arr

def gen_invalid_candidate_sign(rng: random.Random, n: int | None) -> list[int]:
    if n is None or n < 2:
        n = rng.randint(2, 60)
    max_k = min(5, n - 1)
    k = rng.randint(1, max_k)
    others = []
    prod_abs = 1
    sign_prod = 1
    for _ in range(k):
        v_abs = rng.randint(2, 9)
        v = v_abs if rng.random() < 0.5 else -v_abs
        prod_abs *= v_abs
        sign_prod *= sign(v)
        others.append(v)
    ones_count = n - (k + 1)
    neg_ones = rng.randint(0, ones_count) if ones_count > 0 else 0
    pos_ones = ones_count - neg_ones
    ones_sign = -1 if (neg_ones & 1) else 1
    candidate_sign = -(ones_sign * sign_prod)
    candidate = candidate_sign * prod_abs
    arr = list(others) + [candidate] + [-1] * neg_ones + [1] * pos_ones
    rng.shuffle(arr)
    return arr

def gen_many_large(rng: random.Random, n: int | None) -> list[int]:
    min_required = 31
    if n is None or n < min_required:
        n = rng.randint(min_required, 60)
    arr = []
    for _ in range(n):
        arr.append(rand_large_value(rng, 2, 10**9))
    rng.shuffle(arr)
    return arr

def main():
    parser = argparse.ArgumentParser(description="Random test generator for the given Java program (one test case).")
    parser.add_argument("--seed", type=int, default=None, help="RNG seed for reproducibility")
    parser.add_argument("--kind", type=str, default="random", choices=["random", "valid_candidate", "invalid_candidate_sign", "two_zeros", "one_zero", "ones_even", "ones_odd", "many_large"], help="What scenario to generate")
    parser.add_argument("-n", type=int, default=None, help="Target length; generator may increase it if the scenario needs more")
    args = parser.parse_args()
    rng = random.Random(args.seed)

    if args.kind == "random":
        kinds = [
            ("valid_candidate", 0.28),
            ("invalid_candidate_sign", 0.22),
            ("two_zeros", 0.12),
            ("one_zero", 0.10),
            ("ones_even", 0.10),
            ("ones_odd", 0.08),
            ("many_large", 0.10),
        ]
        labels, weights = zip(*kinds)
        args.kind = rng.choices(labels, weights=weights, k=1)[0]

    generators = {
        "valid_candidate": gen_valid_candidate,
        "invalid_candidate_sign": gen_invalid_candidate_sign,
        "two_zeros": gen_two_zeros,
        "one_zero": gen_one_zero,
        "ones_even": gen_ones_even,
        "ones_odd": gen_ones_odd,
        "many_large": gen_many_large,
    }

    arr = generators[args.kind](rng, args.n)
    print(len(arr))
    print(" ".join(str(x) for x in arr))

if __name__ == "__main__":
    main()