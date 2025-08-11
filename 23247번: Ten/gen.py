#!/usr/bin/env python3
import argparse
import random
import sys

def choose_dims(args, rng):
    case = args.case
    m = args.m
    n = args.n
    if case == 'min':
        return 1, 1
    if case == 'max':
        return 300, 300
    if case == 'thin_row':
        return 1, (n or rng.randint(1, 300))
    if case == 'thin_col':
        return (m or rng.randint(1, 300)), 1
    return (m or rng.randint(1, 300)), (n or rng.randint(1, 300))

def gen_grid(case, m, n, rng, lo, hi):
    if case == 'all_ones':
        grid = [[1] * n for _ in range(m)]
    elif case == 'all_tens':
        grid = [[10] * n for _ in range(m)]
    elif case == 'no_solution_threes':
        grid = [[3] * n for _ in range(m)]
    else:
        grid = [[rng.randint(lo, hi) for _ in range(n)] for _ in range(m)]
    return grid

def plant_tens(grid, k, rng):
    if k <= 0:
        return
    m = len(grid)
    n = len(grid[0]) if m else 0
    total = m * n
    k = min(k, total)
    positions = rng.sample(range(total), k)
    for p in positions:
        i = p // n
        j = p % n
        grid[i][j] = 10

def print_grid(grid):
    m = len(grid)
    n = len(grid[0]) if m else 0
    out = sys.stdout
    print(m, n, file=out)
    for row in grid:
        print(' '.join(map(str, row)), file=out)

def main():
    parser = argparse.ArgumentParser(description="Generate a single test case for the submatrix-sum==10 solver.")
    parser.add_argument(
        '--case',
        choices=[
            'random',
            'min',
            'max',
            'thin_row',
            'thin_col',
            'all_ones',
            'all_tens',
            'no_solution_threes',
        ],
        default='random'
    )
    parser.add_argument('-m', type=int, help='Rows (1..300). If omitted, chosen per case.')
    parser.add_argument('-n', type=int, help='Cols (1..300). If omitted, chosen per case.')
    parser.add_argument('--seed', type=int, help='Random seed for reproducibility.')
    parser.add_argument('--min-value', type=int, default=1, help='Cell min (clamped to 1..10).')
    parser.add_argument('--max-value', type=int, default=10, help='Cell max (clamped to 1..10).')
    parser.add_argument(
        '--plant-tens',
        type=int,
        default=0,
        help='Number of random cells to force to 10 (guarantees at least this many single-cell solutions).'
    )
    args = parser.parse_args()

    if args.m is not None and not (1 <= args.m <= 300):
        parser.error("m must be in 1..300")
    if args.n is not None and not (1 <= args.n <= 300):
        parser.error("n must be in 1..300")

    rng = random.Random(args.seed)
    lo = max(1, args.min_value)
    hi = min(10, args.max_value)
    if lo > hi:
        parser.error("min-value must be <= max-value and within 1..10")
    m, n = choose_dims(args, rng)
    grid = gen_grid(args.case, m, n, rng, lo, hi)
    if args.plant_tens:
        plant_tens(grid, args.plant_tens, rng)
    print_grid(grid)

if __name__ == '__main__':
    main()