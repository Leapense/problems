import sys
from math import gcd

def crt_pair(a, m, b, n):
    g = gcd(m, n)
    diff = b - a
    diff_div = diff // g
    m_div = m // g
    n_div = n // g

    def extgcd(x, y):
        if y == 0:
            return (1, 0, x)
        u, v, g0 = extgcd(y, x % y)
        return (v, u - (x // y) * v, g0)
    
    inv_m, _, _ = extgcd(m_div, n_div)
    inv_m %= n_div

    t = (diff_div * inv_m) % n_div
    x = a + m * t
    l = m_div * n
    return (x % l, l)

def main():
    d = list(map(int, sys.stdin.readline().split()))
    r = list(map(int, sys.stdin.readline().split()))
    x, m = r[0], d[0]
    for i in range(1, 4):
        x, m = crt_pair(x, m, r[i], d[i])
    print(x)

if __name__ == "__main__":
    main()