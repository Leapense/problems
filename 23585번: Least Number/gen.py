#!/usr/bin/env python3
import argparse
import random
import sys

def is_satisfiable(sum_n: int, d: int) -> bool:
	if sum_n < 0 or d < 0 or d > 9:
		return False
	if sum_n == 0:
		return True
	if d == 1 and sum_n == 1:
		return False
	return True

def pick_sum_for(d: int, max_sum: int) -> int:
	md = 8 if d == 9 else 9
	if random.random() < 0.35:
		candidates = [0, 1, 2, 8, 9, 10, 11, 17, 18, 19, 80, 81, 82, 99, 100, 101]
		if max_sum > 0:
			k = random.randint(0, max(1, min(max_sum // md, 2000)))
			for base in (k * md - 1, k * md, k * md + 1):
				if 0 <= base <= max_sum:
					candidates.append(base)
		candidates += [max(0, max_sum - 1), max_sum]
		candidates = [c for c in candidates if 0 <= c <= max_sum]
		return random.choice(candidates) if candidates else 0
	else:
		if random.random() < 0.6:
			return int(random.triangular(0, max_sum, 0))
		else:
			return random.randint(0, max_sum)

def generate_case(max_sum: int, require_satisfiable: bool) -> tuple[int, int]:
	while True:
		d = random.randint(0, 9)
		n = pick_sum_for(d, max_sum)
		if require_satisfiable and not is_satisfiable(n, d):
			continue
		return n, d

def main():
	parser = argparse.ArgumentParser(
		description="Random test-case generator for the given C/C++ program (build_min_number_c). "
			    "Emits lines of 'N d'. The C/C++ program reads exactly one line."
	)
	parser.add_argument("-n", "--count", type=int, default=1, help="Number of test cases to emit (default: 1).")
	parser.add_argument("--max-sum", type=int, default=100000, help="Upper bound for N (default: 100000).")
	parser.add_argument("--seed", type=int, default=None, help="Random seed for reproducibility (default: None).")
	parser.add_argument("--allow-unsat", action="store_true", help="Allow unsatisfiable cases (notably N=1, d=1).")

	args = parser.parse_args()

	if args.seed is not None:
		random.seed(args.seed)

	require_satisfiable = not args.allow_unsat

	for i in range(args.count):
		n, d = generate_case(args.max_sum, require_satisfiable)
		print(n, d)

if __name__ == "__main__":
	main()
