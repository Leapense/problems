import math

def solve():
    try:
        n, m = map(int, input().split())
        if n == 1:
            print(m)
            return

        if m == 1:
            print(n)
            return

        result = math.gcd(n - 1, m - 1) + 1
        print(result)
    except (IOError, ValueError) as e:
        pass

solve()