import sys
from math import gcd

def main():
    data = sys.stdin.read().strip().split()
    n, m, p = map(int, data)

    g1 = gcd(n, m)
    g2 = gcd(abs(p - n), m)
    g3 = p
    B = g1 + g2 + g3
    I = (m * p - B) // 2 + 1

    print(I)

if __name__ == "__main__":
    main()