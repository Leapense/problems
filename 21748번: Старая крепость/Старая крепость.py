import math, sys

n, r = map(int, sys.stdin.readline().split())
fragments = []

for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    if b <= a:
        b += 360
    fragments.append((a, b))
fragments.sort()

arc_length = 0

for a, b in fragments:
    arc_length += math.radians(b - a) * r

gaps = []
for i in range(n):
    a1, b1 = fragments[i]
    a2, b2 = fragments[(i + 1) % n]
    gap = a2 - b1
    if gap < 0:
        gap += 360
    gaps.append(gap)

chord_length = 0
for gap in gaps:
    theta = math.radians(gap)
    chord_length += 2 * r * math.sin(theta / 2)

total_length = arc_length + chord_length
print(total_length)