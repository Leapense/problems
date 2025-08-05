import random
import argparse

def generate_and_print_case(case_type="general"):
	if case_type == "max_values":
		n = 100
	else:
		n = random.randint(3, 100)

	if case_type == "max_values":
		sectors = [random.randint(900, 1000) for _ in range(n)]
	else:
		sectors = [random.randint(1, 1000) for _ in range(n)]

	if case_type == "no_movement":
		k = random.randint(100, 10**9)
		b = random.randint(1, k)
		a = random.randint(1, b)
	elif case_type == "limited_range":
		k = random.randint(1, 10**7)
		m_range = random.randint(0, n - 2)
		m_min = random.randint(1, 100)
		m_max = m_min + m_range

		a = m_min * k + random.randint(1, k)
		b = m_max * k + random.randint(1, k)
		if a > 10**9: a = 10**9
		if b > 10**9: b = 10**9
		if a > b: a, b = b, a
	elif case_type == "full_range":
		k = random.randint(1, 10**6)
		m_range = random.randint(n - 1, n + 100)
		m_min = random.randint(1, 100)
		m_max = m_min + m_range

		a = m_min * k + random.randint(1, k)
		b = m_max * k + random.randint(1, k)
		if a > 10**9: a = 10**9
		if b > 10**9: b = 10**9
		if a > b: a, b = b, a
	elif case_type == "a_equals_b":
		a = random.randint(1, 10**9)
		b = a
		k = random.randint(1, 10**9)
	elif case_type == "max_values":
		k = random.randint(10**9 - 1000, 10**9)
		b = 10**9
		a = random.randint(10**9 - 1000, b)
	else:
		a = random.randint(1, 10**9)
		b = random.randint(a, 10**9)
		k = random.randint(1, 10**9)

	print(n)
	print(*sectors)
	print(a, b, k)

if __name__ == "__main__":
	parser = argparse.ArgumentParser(
		description="Generate test cases for the 'Wheel of Fortune' problem."
	)
	parser.add_argument(
		"--type",
		type=str,
		default="general",
		choices=[
			"general", "no_movement", "limited_range",
			"full_range", "a_equals_b", "max_values"
		],
		help="Type of test case to generate."
	)
	args = parser.parse_args()
	generate_and_print_case(args.type)
