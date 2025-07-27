import sys
data = sys.stdin.read().split()

n = int(data[0])
s = 0
for i in range(n):
    x = int(data[2 * i + 1])
    y = int(data[2 * i + 2])
    s += y - x
a = s / n
print(f"{a:.6f}")