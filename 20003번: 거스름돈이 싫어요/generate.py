import random

def main():
    n = random.randint(1, 51)
    print(n)
    for i in range(n):
        a = random.randint(1, 41)
        b = random.randint(1, 41)
        print(a, b)

if __name__ == "__main__":
    main()