#!/usr/bin/env python3
"""
Random test data generator for the "작업 순서" problem.

Features
--------
* Generates a single test case or a batch of test cases.
* Supports boundary conditions:
	- Minimum values (N = 1, M = 0)
	- Empty graph (M = 0)
	- Full graph (M = N*(N-1)/2, capped at 200 000)
	- Large graph (N = 100 000, M = 200 000)
	- Random moderate cases
* Guarantees:
	- No duplicate edges
	- No self-loops
	- Acyclicity (edges only from a lower-indexed node to a higher-indexed node)
* Uses a deterministic seed for reproducibility (default 42).

Usage
-----
	python generate.py [--batch COUNT] [--output FILE]

Examples
--------
	# Generate 5 random test cases and print to stdout
	python generate.py --batch 5

	# Generate a single test case with N=10, M=15, X=7
	python generate.py --n 10 --m 15 --x 7

	# Generate all boundary cases and write to tests.txt
	python generate.py --output tests.txt
"""

import random
import sys
from typing import List, Tuple, Set

# ------------------------------------------------------------------------------------------ #
# 1. Helper: generate a single test case
# ------------------------------------------------------------------------------------------ #
def generate_case(n: int, m: int, x: int) -> str:
	"""
	Return a string that represents one test case.

	Parameters
	----------
	n : int
	    Number of tasks (vertices).
	m : int
	    Number of precedence relations (edges).
	x : int
	    Target task to finish today.

	Returns
	-------
	str
	    Formatted test case ready to be printed or written to a file.
"""

	edges: Set[Tuple[int, int]] = set()
	while len(edges) < m:
		a = random.randint(1, n - 1)
		b = random.randint(a + 1, n)
		edges.add((a, b))
	lines = [f"{n} {m}"]
	for a, b in edges:
		lines.append(f"{a} {b}")
	lines.append(str(x))
	return "\n".join(lines)

# ----------------------------------------------------------------------------------- #
# 2. Boundary test cases
# ----------------------------------------------------------------------------------- #
def boundary_cases() -> List[str]:
	"""
	Return a list of strings, each string is a boundary test case.
	"""
	cases = []
	cases.append(generate_case(n=1, m=0, x=1))
	cases.append(generate_case(n=5, m=0, x=3))
	n_small = 5
	m_full = n_small * (n_small - 1) // 2
	cases.append(generate_case(n=n_small, m=m_full, x=4))
	cases.append(generate_case(n=100_000, m=0, x=1))
	n_large = 100_000
	m_max = min(n_large * (n_large - 1) // 2, 200_000)
	cases.append(generate_case(n=n_large, m=m_max, x=99999))

	cases.append(generate_case(n=1000, m=5000, x=500))
	return cases

# ------------------------------------------------------------------------------------ #
# 3. Random batch generator
# ------------------------------------------------------------------------------------ #
def random_batch(count: int, seed: int = 42) -> List[str]:
	"""
	Generate a batch of random test cases.

	Parameters
	----------
	count : int
		Number of test cases to generate.
	seed : int
		Random seed of reproducibility.

	Returns
	-------
	List[str]
		List of formatted test case strings.
	"""
	random.seed(seed)
	batch = []
	for _ in range(count):
		n = random.randint(1, 100_000)
		max_possible = min(n * (n - 1) // 2, 200_000)
		m = random.randint(0, max_possible)
		x = random.randint(1, n)
		batch.append(generate_case(n, m, x))
	return batch

# ---------------------------------------------------------------------------------- #
# 4. CLI handling
# ---------------------------------------------------------------------------------- #
def main() -> None:
	import argparse
	parser = argparse.ArgumentParser(description="Generate test data for the problem.")
	parser.add_argument("--batch", type=int, default=0, help="Generate a batch of random test cases (default: 0).")
	parser.add_argument("--n", type=int, help="Number of tasks for a single test case.")
	parser.add_argument("--m", type=int, help="Number of tasks for a single test case.")
	parser.add_argument("--x", type=int, help="Target task for a single test case.")
	parser.add_argument("--output", type=str, help="File to write the output to.")
	args = parser.parse_args()

	if args.batch > 0:
		cases = random_batch(args.batch)
	elif args.n is not None and args.m is not None and args.x is not None:
		cases = [generate_case(args.n, args.m, args.x)]
	else:
		cases = boundary_cases()
	
	output = "\n\n".join(cases)

	if args.output:
		with open(args.output, "w", encoding="utf-8") as f:
			f.write(output)
	else:
		print(output)

if __name__ == "__main__":
	main()