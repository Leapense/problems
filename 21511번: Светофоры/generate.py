import random
import sys

def generate_test_case():
	a = random.randint(1,100)
	b = random.randint(1,100)
	x = random.randint(1,100_000)
	print(f"{a} {b} {x}")

if __name__ == "__main__":
	generate_test_case()
