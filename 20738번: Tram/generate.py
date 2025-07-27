#!/usr/bin/env python3
import argparse
import random
import os

def generate_case(n, lo, hi):
    pairs = []
    if n >= 3:
        pairs.extend([
            (0, 0),
            (lo, hi),
            (hi, lo)
        ])

    while len(pairs) < n:
        x = random.randint(lo, hi)
        y = random.randint(lo, hi)
        pairs.append((x, y))

    pairs = pairs[:n]
    random.shuffle(pairs)
    return pairs

def write_case(pairs, filename):
    with open(filename, 'w') as f:
        f.write(f"{len(pairs)}\n")
        for x, y in pairs:
            f.write(f"{x} {y}\n")

def main():
    parser = argparse.ArgumentParser(
        description="Generate random test cases for the average-difference program"
    )
    parser.add_argument("--cases", type=int, default=5,
                        help="Number of test files to generate.")
    parser.add_argument("--max-n", type=int, default=10,
                        help="Maximum number of pairs per case.")
    parser.add_argument("--min-val", type=int, default=-100,
                        help="Minimum integer value for x and y.")
    parser.add_argument('--max-val', type=int, default=100,
                        help="Maximum integer value for x and y.")
    parser.add_argument("--seed", type=int, default=None,
                        help="Random seed for reproducibility.")
    parser.add_argument("--out-dir", type=str, default='.',
                        help="Directory to write test files into.")
    args = parser.parse_args()
    random.seed(args.seed)
    os.makedirs(args.out_dir, exist_ok=True)

    for i in range(1, args.cases + 1):
        n = random.randint(1, args.max_n)
        pairs = generate_case(n, args.min_val, args.max_val)
        fname = os.path.join(args.out_dir, f"case_{i:02d}.in")
        write_case(pairs, fname)
        print(f"Generated {fname} ({n} pairs)")

if __name__ == "__main__":
    main()