import random

def main():
    N = random.randint(1, 100001)
    a = []
    for _ in range(N):
        a.append(random.randint(1, 1001))
    print(N)
    print(*a)

if __name__ == '__main__':
    main()