import sys
import math
from functools import reduce

def lcm(x, y):
    return x // math.gcd(x, y) * y

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    n = int(data[0])
    nums = list(map(int, data[1:]))
    a = nums[0::2]
    b = nums[1::2]
    l = reduce(lcm, b)
    numerators = [ai * (l // bi) for ai, bi in zip(a, b)]
    g = reduce(math.gcd, numerators)
    g_common = math.gcd(g, l)
    p = g // g_common
    q = l // g_common
    print(p, q)

if __name__ == '__main__':
    main()