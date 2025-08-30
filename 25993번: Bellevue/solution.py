import sys
import math

data = sys.stdin.read().strip().split()
n = int(data[0])
coords = list(map(int, data[1:]))

xs = coords[0::2]
ys = coords[1::2]

x_left = xs[0]
x_right = xs[-1]
best = 0.0
max_h = ys[0]

for i in range(1, n):
    y = ys[i]
    if y > max_h:
        dx = xs[i] - x_left
        if dx > 0:
            angle = math.degrees(math.atan(y / dx))
            if angle > best:
                best = angle
    if y > max_h:
        max_h = y
max_h = ys[-1]
for i in range(n - 2, -1, -1):
    y = ys[i]
    if y > max_h:
        dx = x_right - xs[i]
        if dx > 0:
            angle = math.degrees(math.atan(y / dx))
            if angle > best:
                best = angle
    if y > max_h:
        max_h = y
print("{:.10f}".format(best))