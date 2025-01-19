import sys
n = int(sys.stdin.readline())

def phi(x):
    r = x
    p = 2

    while p * p <= x:
        if x % p == 0:
            while x % p == 0:
                x //= p
            r -= r // p
        p += 1 if p == 2 else 2
    if x > 1:
        r -= r // x
    return r

print(n * phi(n))