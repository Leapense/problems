import random

def main():
    n = random.randint(2, 300001)
    r = random.randint(1, 10**9+1)
    d = random.sample(range(1, 10**9+1), n)
    d.sort()
    print(n, r)
    print(' '.join(map(str, d)))

if __name__ == "__main__":
    main()