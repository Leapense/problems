import random
import argparse
import sys

def generate_test_case(n, max_color, scenario):
	squares = []
	if scenario == "monochromatic":
		color = random.randint(1, max_color)
		squares = [color] * n
	elif scenario == "alternating":
		c1, c2 = random.sample(range(1, max_color + 1), 2)
		for i in range(n):
			squares.append(c1 if i % 2 == 0 else c2)
	elif scenario == "high_merge":
		if max_color < 2:
			scenario = "general"
		else:
			bread_color, sandwich_color = random.sample(range(1, max_color + 1), 2)
			pattern = [bread_color, sandwich_color]

			while len(squares) < n:
				block_len = random.randint(1, 5)
				squares.extend([bread_color] * block_len)
				if len(squares) >= n: break

				block_len = random.randint(1, 3)
				other_color = random.randint(1, max_color)
				while other_color == bread_color:
					other_color = random.randint(1, max_color)
				squares.extend([other_color] * block_len)
	if not squares:
		current_len = 0
		while current_len < n:
			color = random.randint(1, max_color)
			block_len = random.randint(1, 10)
			block_len = min(block_len, n - current_len)
			squares.extend([color] * block_len)
			current_len += block_len
	return squares[:n]

if __name__ == "__main__":
	parser = argparse.ArgumentParser(
		description="Generate test cases for the Squarow problem."
	)
	parser.add_argument("n", type=int, help="Number of squares (1 to 200,000).")
	parser.add_argument("--max-color", type=int, default=200000, help="Maximum value for a color (default: 200,000).")
	parser.add_argument("--scenario", type=str, default="general", choices=["general", "monochromatic", "alternating", "high_merge"], help="Type of test case scenario to generate.")
	parser.add_argument("--subtask", type=int, choices=[1, 2, 3], help="Automatically set N and max_color for a specific subtask.")

	args = parser.parse_args()

	n = args.n
	max_color = args.max_color
	scenario = args.scenario

	if args.subtask:
		if args.subtask == 1:
			n = random.randint(1, 100)
			max_color = 100
		elif args.subtask == 2:
			n = random.randint(101, 10000)
			max_color = 1000
		elif args.subtask == 3:
			n = random.randint(10001, 200000)
			max_color = 200000
	if not (1 <= n <= 200000):
		sys.stderr.write("Error: N must be between 1 and 200,000.\n")
		sys.exit(1)
	if not (1 <= max_color <= 200000):
		sys.stderr.write("Error: max_color must be between 1 and 200,000.\n")
		sys.exit(1)

	result_squares = generate_test_case(n, max_color, scenario)
	print(len(result_squares))
	print(*result_squares)
