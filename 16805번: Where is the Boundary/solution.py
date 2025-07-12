import sys
input = sys.stdin.readline

n, m = map(int, input().split())
e = [0] * (n + 1)
for _ in range(m):
    line = input().strip()
    for j, ch in enumerate(line, start=1):
        if ch == 'E':
            e[j] += 1
sumE = [0] * (n + 1)
sumW = [0] * (n + 1)
for j in range(1, n + 1):
    sumE[j] = sumE[j - 1] + e[j]
    sumW[j] = sumW[j - 1] + (m - e[j])

best = 10 ** 18
pos = 0
totalW = sumW[n]
for k in range(0, n + 1):
    errors = sumE[k] + (totalW - sumW[k])
    if errors < best:
        best = errors
        pos = k

print(pos, pos + 1)