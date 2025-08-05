import random
import argparse

def generate_test_case(scenario="general"):
	if scenario == "a_zero":
		a = 0
		b = random.randint(-10000, 10000)
	elif scenario == "boundary":
		eps_num = 10000
		eps_den = 10000
		a = random.choice([-10000, 10000])
		b = random.choice([-10000, 10000])
		x0 = random.choice([-10000, 10000])
	else:
		a = random.randint(-10000, 10000)
		while a == 0:
			a = random.randint(-10000, 10000)
		b = random.randint(-10000, 10000)
	if scenario != "boundary":
		eps_num = random.randint(1, 10000)
		eps_den = random.randint(1, 10000)
		x0 = random.randint(-10000, 10000)

	print(eps_num, eps_den)
	print(a, b)
	print(x0)

if __name__ == "__main__":
	parser = argparse.ArgumentParser(
		description="Generate test cases for the 'Calculus Introduction' problem."
	)
	parser.add_argument(
		"--scenario",
		type=str,
		default="general",
		choices=["general", "a_zero", "boundary"],
		help="Type of test case scenario to generate."
	)

	args = parser.parse_args()
	generate_test_case(args.scenario)
