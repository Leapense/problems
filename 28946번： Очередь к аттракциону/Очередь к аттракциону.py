import sys, math

input = sys.stdin.readline
n, m, t = map(int, input().split())
a = list(map(int, input().split()))

if m:
    arrivals = list(map(int, input().split()))
else:
    arrivals = []

A_total = sum(a)
A_tail = sum(a[1:])
P = (n - 1) & 1
rs = []
for ti in arrivals:
    rs.append((ti - 1) // t)
max_r = 0

for r in rs:
    if r > max_r:
        max_r = r

freq = [0] * (max_r + 2)
for r in rs:
    freq[r] += 1

cum = [0] * (max_r + 2)
for i in range(1, max_r + 2):
    cum[i] = cum[i - 1] + freq[i - 1]

best = None
best_k = None

if 0==0:
    group_val = freq[0] if (P == 0) else a[0]
    tot = A_tail + group_val
    best = tot
    best_k = 0

cnt = [0] * (max_r + 2)
for idx, r in enumerate(rs):
    X = cnt[r]
    cnt[r] += 1
    if r == 0:
        base = A_tail
        if P == 0:
            group = freq[0] - X - 1
        else:
            group = a[0] + X
        tot = base + group
    else:
        base = A_total + cum[r]
        if P == 0:
            group = freq[r] - X - 1
        else:
            group = X
        tot = base + group
    if best is None or tot < best or (tot == best and (idx + 1) < best_k):
        best = tot
        best_k = idx + 1
print(best, best_k)