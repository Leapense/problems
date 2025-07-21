import sys
import random

def main():
    directions = ['U', 'L', 'D', 'R']
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <n_limit> <t_limit> > <your_test_case_name>")
        sys.exit(1)

    n_limit = int(sys.argv[1])
    t_limit = int(sys.argv[2])
    print(random.choice(range(1, n_limit + 1)))
    for _ in range(1, n_limit + 1):
        print(random.choice(range(0, t_limit + 1)), random.choice(directions))

if __name__ == "__main__":
    main()
        