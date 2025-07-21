import sys
import random

def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <n_limit> <m_limit>")
        sys.exit(1)
    n_limit = int(sys.argv[1])
    m_limit = int(sys.argv[2])
    if n_limit > 100 or n_limit < 1:
        print("N limit should be between 1 and 100")
        sys.exit(1)
    if m_limit > 10000 or m_limit < 1:
        print("M limit should be between 1 and 10000")
        sys.exit(1)

    i_love_bins = [0, 1]
    n = random.randint(1, n_limit)
    m = random.randint(1, m_limit)
    print(n, m)
    for i in range(m):
        for j in range(0, n + 1):
            print(random.choice(i_love_bins), end=' ')
        print()

if __name__ == '__main__':
    main()
