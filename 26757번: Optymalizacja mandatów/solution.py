#!/usr/bin/env python3
import sys
data = list(map(int, sys.stdin.buffer.read().split()))
if not data:
    sys.exit(0)
it = iter(data)
n = next(it)
K = [next(it) for _ in range(n)]
R = [next(it) for _ in range(n)]
MAXK = 100000
cntK = [0] * (MAXK + 1)
for k in K:
    cntK[k] += 1
cntW = [0] * 7
sumR = 0
for r in R:
    sumR += r
    if r < 10:
        d = 1
    elif r < 100:
        d = 2
    elif r < 1000:
        d = 3
    elif r < 10000:
        d = 4
    elif r < 100000:
        d = 5
    else:
        d = 6
    cntW[d] += 1

powers = [1, 10, 100, 1000, 10000, 100000, 1000000]
res = 0
k = MAXK
for d in range(1, 7):
    to_assign = cntW[d]
    w = powers[d]
    while to_assign > 0:
        while k > 0 and cntK[k] == 0:
            k -= 1
        if k == 0:
            break
        take = cntK[k] if cntK[k] < to_assign else to_assign
        res += k * w * take
        cntK[k] -= take
        to_assign -= take
ans = res + sumR
print(ans)