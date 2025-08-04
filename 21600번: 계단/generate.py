#!/usr/bin/env python3
import argparse
import random
import sys
import time

def main():
	parser = argparse.ArgumentParser(description="Histogram staircase random TC generator")
	parser.add_argument("--cases", type=str, default="normal", help="TC Variations") # small/normal/large
	parser.add_argument("--seed", type=int, help="Random Seed (if it didn't set custom seed, then it will set time value as default)")
	args = parser.parse_args()

	seed = args.seed if args.seed is not None else time.time_ns()
	random.seed(seed)

	# small  | N : [1, 100], Ai : [1, 1000]
	# normal | N : [1, 1000], Ai : [1, 10**6]
	# large  | N : [1, 10000], Ai : [1, 10**9]

	A = []
	case_type = args.cases
	if case_type == "small":
		N = random.randint(1, 100)
		for _ in range(N):
			A.append(random.randint(1, 1000))
	elif case_type == "normal":
		N = random.randint(1, 1000)
		for _ in range(N):
			A.append(random.randint(1, 10**6))
	elif case_type == "large":
		N = random.randint(1, 10000)
		for _ in range(N):
			A.append(random.randint(1, 10**9))

	print(N)
	print(*A)

if __name__ == "__main__":
	main()
