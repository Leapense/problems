import sys
import math
sys.setrecursionlimit(10**6)
def main():
    input = sys.stdin.readline
    a, b = map(int, input().split())
    X = 1 << 60
    M = 1 << 61
    T = X - 1
    if a == b:
        if a == 0:
            print(-1)
            return
        g = math.gcd(abs(a), M)
        if T % g != 0:
            print(-1)
            return
        Mprime = M // g
        a_prime = a // g
        T_prime = T // g
        inv = pow(a_prime, -1, Mprime)
        n0 = (T_prime * inv) % Mprime
        if n0 == 0:
            n0 = Mprime
        print(n0)
        return
    lo = 1
    hi = M
    ans = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        L = mid * a - T
        R = mid * b - T
        k_min = (L + M - 1) // M
        k_max = R // M
        if k_min <= k_max:
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1
    print(ans)
if __name__ == '__main__':
    main()
