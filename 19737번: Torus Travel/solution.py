import sys
import math

def main() -> None:
    r, R, n = map(int, sys.stdin.readline().split())
    pi = math.pi
    l = pi * r / 2.0
    if n == 1:
        ans = l
    else:
        a = 2.0 * pi * (R - r) / n
        b = 2.0 * pi * R / n
        if n == 2:
            ans = 3.0 * l + a
        else:
            inner_cnt = (n - 1) // 2
            south_cnt = (n - 1) - inner_cnt
            ans = n * l + inner_cnt * a + south_cnt * b

    print(f"{ans:.15f}")

if __name__ == "__main__":
    main()