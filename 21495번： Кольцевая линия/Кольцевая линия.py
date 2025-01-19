import sys
n = int(sys.stdin.readline())
r = n
x = n
p = 2

while p * p <= x:
    if x % p == 0:
        while x % p == 0:
            x //= p
        r -= r // p
    p += 1 if p == 2 else 2
if x > 1:
    r -= r // x
print(n * r)