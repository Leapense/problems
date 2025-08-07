import random

def generate_boundary_cases():
    B = [1, 2, 9999, 10000]
    cases = []
    for b in B:
        cases.append([b] * 6)
    for _ in range(4):
        case = [random.choice(B) for _ in range(6)]
        cases.append(case)
    return cases

def generate_random_case():
    return [random.randint(3, 9998) for _ in range(6)]

def main():
    random.seed()
    TOTAL = 50

    test_cases = generate_boundary_cases()
    while len(test_cases) < TOTAL:
        test_cases.append(generate_random_case())

    for case in test_cases:
        print(" ".join(map(str, case)))
    print("0 0 0 0 0 0")

if __name__ == "__main__":
    main()