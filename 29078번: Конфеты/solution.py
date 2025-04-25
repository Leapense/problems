import sys
from collections import defaultdict
data = sys.stdin.buffer.read().split()
if not data:
    quit()
n = int(data[0])
a = list(map(int, data[1:]))
cnt = defaultdict(int)
left = 0
distinct = 0
best = 0
for right, x in enumerate(a):
    if cnt[x] == 0:
        distinct += 1
    cnt[x] += 1
    while distinct > 2:
        y = a[left]
        cnt[y] -= 1
        if cnt[y] == 0:
            distinct -= 1
        left += 1
    if distinct == 2:
        best = max(best, right - left + 1)
print(best)
