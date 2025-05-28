import sys
from math import gcd

def main():
    a, b, n = map(int, sys.stdin.read().split())
    g = gcd(a, b)
    lcm = a // g * b

    count_a = n // a
    count_b = n // b
    count_both = n // lcm

    result = count_a + count_b - count_both
    print(result)

if __name__ == "__main__":
    main()