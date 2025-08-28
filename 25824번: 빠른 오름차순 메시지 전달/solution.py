import sys

data = list(map(int, sys.stdin.read().split()))
mat = [data[i * 12 : (i + 1) * 12] for i in range(12)]
pairs = [(0, 1), (2, 3), (4, 5), (6, 7), (8, 9), (10, 11)]
best = 10 ** 18

for mask in range(1 << 6):
    path = []
    for g in range(6):
        bit = (mask >> g) & 1
        entry = pairs[g][bit]
        other = pairs[g][1 - bit]
        path.append(entry)
        path.append(other)
    total = 0
    for i in range(11):
        total += mat[path[i]][path[i + 1]]
    if total < best:
        best = total
print(best)