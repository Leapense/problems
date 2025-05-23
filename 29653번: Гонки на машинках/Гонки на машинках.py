n = int(input())
cars = []

for _ in range(n):
    x, v = map(int, input().split())
    cars.append((x, v))

min_time = float('inf')

for i in range(n):
    x1, v1 = cars[i]
    for j in range(i + 1, n):
        x2, v2 = cars[j]
        if v1 == v2:
            continue
        t = (x2 - x1) / (v1 - v2)
        if t > 0:
            if t < min_time:
                min_time = t

print("{0:.5f}".format(min_time))