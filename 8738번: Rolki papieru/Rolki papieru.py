import sys

input_data = sys.stdin.read().strip().split()
n = int(input_data[0])
rolls = input_data[1:]

d = []
r = []

for i in range(n):
    di = int(rolls[2 * i])
    ri = int(rolls[2 * i + 1])
    d.append(di)
    r.append(ri)

D_min = min(d)

r.sort()
if n % 2 == 1:
    median_r = r[n // 2]
else:
    median_r = r[n // 2 - 1]

R = median_r
if R > D_min:
    R = D_min

result = 0
for ri in r:
    result += abs(ri - R)

print(result)