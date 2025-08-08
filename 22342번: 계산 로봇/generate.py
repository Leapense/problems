#!/usr/bin/env python3
import argparse
import os
import random
import sys
from typing import List, Tuple


def clamp(v: int, lo: int, hi: int) -> int:
    return max(lo, min(hi, v))


def to_digit_char(v: int) -> str:
    return str(clamp(v, 1, 9))


def gen_uniform(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    grid = []
    for i in range(rows):
        row = [to_digit_char(rng.randint(lo, hi)) for _ in range(cols)]
        grid.append("".join(row))
    return grid


def gen_checker(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    grid = []
    a, b = lo, hi
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(to_digit_char(a if (i + j) % 2 == 0 else b))
        grid.append("".join(row))
    return grid


def gen_stripes_h(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    grid = []
    for i in range(rows):
        val = hi if i % 2 == 0 else lo
        grid.append("".join(to_digit_char(val) for _ in range(cols)))
    return grid


def gen_stripes_v(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    grid = []
    for i in range(rows):
        row = [to_digit_char(hi if j % 2 == 0 else lo) for j in range(cols)]
        grid.append("".join(row))
    return grid


def gen_diagonal(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    span = hi - lo + 1
    if span <= 0:
        span = 1
    grid = []
    for i in range(rows):
        row = []
        for j in range(cols):
            v = lo + ((i + j) % span)
            row.append(to_digit_char(v))
        grid.append("".join(row))
    return grid


def gen_gradient(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    grid = []
    denom = max(1, (rows - 1) + (cols - 1))
    for i in range(rows):
        row = []
        for j in range(cols):
            t = (i + j) / denom
            v = int(round(lo + t * (hi - lo)))
            row.append(to_digit_char(v))
        grid.append("".join(row))
    return grid


def gen_spikes(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    base = lo
    grid = [[base for _ in range(cols)] for _ in range(rows)]
    area = rows * cols
    spikes = max(1, area // 100)  # ~1% spikes
    for _ in range(spikes):
        r = rng.randrange(rows)
        c = rng.randrange(cols)
        grid[r][c] = hi
        # small local halo to make it interesting
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            rr, cc = r + dr, c + dc
            if 0 <= rr < rows and 0 <= cc < cols:
                grid[rr][cc] = max(grid[rr][cc], hi - 1)
    return ["".join(to_digit_char(v) for v in row) for row in grid]


def gen_low(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    grid = []
    for _ in range(rows):
        row = []
        for _ in range(cols):
            if rng.random() < 0.75:
                row.append(to_digit_char(lo))
            else:
                row.append(to_digit_char(rng.randint(lo, hi)))
        grid.append("".join(row))
    return grid


def gen_high(rows: int, cols: int, rng: random.Random, lo: int, hi: int) -> List[str]:
    grid = []
    for _ in range(rows):
        row = []
        for _ in range(cols):
            if rng.random() < 0.75:
                row.append(to_digit_char(hi))
            else:
                row.append(to_digit_char(rng.randint(lo, hi)))
        grid.append("".join(row))
    return grid


PATTERNS = {
    "uniform": gen_uniform,
    "checker": gen_checker,
    "stripes_h": gen_stripes_h,
    "stripes_v": gen_stripes_v,
    "diagonal": gen_diagonal,
    "gradient": gen_gradient,
    "spikes": gen_spikes,
    "low": gen_low,
    "high": gen_high,
}


def write_to_stdout(rows: int, cols: int, lines: List[str]) -> None:
    print(f"{rows} {cols}")
    for line in lines:
        print(line)


def write_to_file(path: str, rows: int, cols: int, lines: List[str]) -> None:
    with open(path, "w", encoding="utf-8") as f:
        f.write(f"{rows} {cols}\n")
        for line in lines:
            f.write(line)
            f.write("\n")


def generate_single(args: argparse.Namespace) -> None:
    rng = random.Random(args.seed)
    if args.pattern not in PATTERNS:
        raise ValueError(f"Unknown pattern: {args.pattern}")
    lo = clamp(args.min_digit, 1, 9)
    hi = clamp(args.max_digit, 1, 9)
    if lo > hi:
        lo, hi = hi, lo
    lines = PATTERNS[args.pattern](args.rows, args.cols, rng, lo, hi)
    write_to_stdout(args.rows, args.cols, lines)


def suite_definitions(max_rows: int, max_cols: int, include_max: bool) -> List[Tuple[str, int, int, str, int]]:
    cases: List[Tuple[str, int, int, str, int]] = []
    cases.append(("01_min_1x1", 1, 1, "uniform", 1))
    cases.append(("02_single_row_1x16", 1, min(16, max_cols), "diagonal", 2))
    cases.append(("03_single_col_16x1", min(16, max_rows), 1, "gradient", 3))
    cases.append(("04_sample_like_3x4", 3, 4, "diagonal", 4))
    cases.append(("05_small_checker_7x7", min(7, max_rows), min(7, max_cols), "checker", 5))
    cases.append(("06_medium_uniform_100x100", min(100, max_rows), min(100, max_cols), "uniform", 6))
    cases.append(("07_medium_stripes_h_127x113", min(127, max_rows), min(113, max_cols), "stripes_h", 7))
    cases.append(("08_medium_spikes_199x199", min(199, max_rows), min(199, max_cols), "spikes", 8))
    wide_n = min(2000, max_cols)
    tall_m = min(2000, max_rows)
    cases.append(("09_edge_wide_1x2000", 1, wide_n, "high", 9))
    cases.append(("10_edge_tall_2000x1", tall_m, 1, "low", 10))
    if include_max:
        cases.append(("11_edge_max_2000x2000", tall_m, wide_n, "gradient", 11))
    return cases


def generate_suite(args: argparse.Namespace) -> None:
    os.makedirs(args.out_dir, exist_ok=True)
    defs = suite_definitions(args.max_rows, args.max_cols, args.include_max)
    for name, r, c, pattern, seed in defs:
        rng = random.Random(seed if args.seed is None else args.seed + seed)
        lo = clamp(args.min_digit, 1, 9)
        hi = clamp(args.max_digit, 1, 9)
        if lo > hi:
            lo, hi = hi, lo
        lines = PATTERNS[pattern](r, c, rng, lo, hi)
        path = os.path.join(args.out_dir, f"{name}.in")
        write_to_file(path, r, c, lines)
        print(f"Wrote {path} ({r}x{c}, {pattern})")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Generator for the '계산 로봇' problem inputs."
    )
    subparsers = parser.add_subparsers(dest="cmd", required=True)

    p_single = subparsers.add_parser("single", help="Emit a single test to STDOUT")
    p_single.add_argument("--rows", "-r", type=int, required=True)
    p_single.add_argument("--cols", "-c", type=int, required=True)
    p_single.add_argument("--pattern", "-p", type=str, default="uniform", choices=sorted(PATTERNS.keys()))
    p_single.add_argument("--min-digit", type=int, default=1)
    p_single.add_argument("--max-digit", type=int, default=9)
    p_single.add_argument("--seed", type=int, default=None)
    p_single.set_defaults(func=generate_single)

    p_suite = subparsers.add_parser("suite", help="Generate a suite of boundary/structured tests into a directory")
    p_suite.add_argument("--out-dir", "-o", type=str, required=True)
    p_suite.add_argument("--include-max", action="store_true", help="Include the 2000x2000 case")
    p_suite.add_argument("--max-rows", type=int, default=2000)
    p_suite.add_argument("--max-cols", type=int, default=2000)
    p_suite.add_argument("--min-digit", type=int, default=1)
    p_suite.add_argument("--max-digit", type=int, default=9)
    p_suite.add_argument("--seed", type=int, default=None, help="Base seed to mix with per-case seeds")
    p_suite.set_defaults(func=generate_suite)

    return parser


def main() -> None:
    parser = build_parser()
    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()