import math
import sys

def input():
    return sys.stdin.readline()

def egcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        g, x, y = egcd(b, a % b)
        return (g, y, x - (a // b) * y)
    
def modinv(a, m):
    g, x, _ = egcd(a, m)
    if g != 1:
        return None
    return x % m

def ceil_div(x, y):
    q, r = divmod(x, y)
    if r != 0 and ((y > 0 and r > 0) or (y < 0 and r < 0)):
        return q + 1
    return q

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    a = int(data[0])
    b = int(data[1])
    M = 1 << 61
    T = (1 << 60) - 1
    if b <= 0:
        print(-1)
        return
    if a == b:
        if a == 0:
            print(0 if T == 0 else -1)
            return
        r = a
        g = math.gcd(abs(r), M)
        if T % g != 0:
            print(-1)
            return
        r1 = r // g
        M1 = M // g
        T1 = T // g
        inv = modinv(r1 % M1, M1)
        k0 = (T1 * inv) % M1
        if k0 <= 0:
            k0 += M1

        print(k0)
        return
    if a == 0:
        ans = ceil_div(T, b)
        print(ans)
        return
    
    cand1 = ceil_div(T, b)
    cand2 = ceil_div(M - T, -a)
    ans = min(cand1, cand2)
    print(ans)

if __name__ == "__main__":
    main()