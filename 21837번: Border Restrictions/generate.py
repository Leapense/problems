import random
import argparse
import string

def generate_country_names(n):
	names = []
	for i in range(n):
		length = random.randint(5, 15)
		name = f"COUNTRY{i}"
		names.append(name)
	return names

def generate_test_case(scenario="complex", n_countries=10):
	if n_countries < 1:
		n_countries = 1

	countries = generate_country_names(n_countries)
	random.shuffle(countries)
	rules = []

	if scenario == "disconnected":
		connected_count = random.randint(n_countries // 2, n_countries - 1) if n_countries > 1 else 1
		active_countries = countries[:connected_count]
		for dest in active_countries:
			num_origins = random.randint(0, len(active_countries) - 1)
			possible_origins = [c for c in active_countries if c != dest]
			origins = random.sample(possible_origins, num_origins)
			rules.append(f"{dest} allows travellers from {' '.join(origins)}")
	elif scenario == "linear":
		for i in range(1, n_countries):
			dest = countries[i]
			origin = countries[i - 1]
			rules.append(f"{dest} allows travellers from {origin}")
		if n_countries > 1 and len(rules) < n_countries:
			remaining = countries[len(rules):]
			for dest in remaining:
				rules.append(f"{dest} allows travellers from")
	elif scenario == "hub_spoke":
		if not countries: return
		hub = countries[0]
		spokes = countries[1:]
		rules.append(f"{hub} allows travellers from")
		for spoke in spokes:
			rules.append(f"{spoke} allows travellers from {hub}")
	else:
		for dest in countries:
			num_origins = random.randint(0, len(countries) // 2)
			possible_origins = [c for c in countries if c != dest]
			origins = random.sample(possible_origins, num_origins)
			rules.append(f"{dest} allows travellers from {' '.join(origins)}")
	while len(rules) < n_countries:
		dest = random.choice(countries)
		if not any(r.startswith(dest) for r in rules):
			rules.append(f"{dest} allows travellers from")
	random.shuffle(rules)

	print(len(rules))
	for rule in rules:
		print(rule)

if __name__ == "__main__":
	parser = argparse.ArgumentParser(
		description="Generate test cases for the Border Restrictions problem."
	)
	parser.add_argument(
		"n", type=int, help="Number of countries (and rules), between 1 and 300."
	)
	parser.add_argument(
		"--scenario",
		type=str,
		default="complex",
		choices=["complex", "disconnected", "linear", "hub_spoke"],
		help="Type of graph topology to generate."
	)

	args = parser.parse_args()
	if not (1 <= args.n <= 300):
		raise ValueError("Number of countries N must be between 1 and 300.")

	generate_test_case(args.scenario, args.n)
