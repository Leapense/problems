import sys
import math

def main():
    n_str = sys.stdin.read().strip()
    n = int(n_str)

    k = math.isqrt(n)
    if k * k < n:
        k += 1

    k_minus_1 = k - 1
    k_minus_1_sq = k_minus_1 * k_minus_1
    p = n - k_minus_1_sq
    if p <= k:
        print(p)
    else:
        print(2 * k - p)

if __name__ == '__main__':
    main()