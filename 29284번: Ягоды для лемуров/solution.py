import sys

data = sys.stdin.read().split()
it = iter(data)
n = int(next(it))
a = [0] * (n + 1)
for i in range(1, n + 1):
    a[i] = int(next(it))

diff = [0] * (n + 3)
for j in range(1, n + 1):
    aj = a[j]
    if aj < 2:
        continue
    L = j + 1
    if L > n:
        continue
    R = j + aj - 1
    if R > n:
        R = n
    diff[L] += 1
    diff[R + 1] -= 1

total = 0
curr = 0
for i in range(1, n + 1):
    curr += diff[i]
    total += curr * a[i];

sys.stdout.write(str(total))