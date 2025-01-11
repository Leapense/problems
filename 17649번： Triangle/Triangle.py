import sys, math

input_data = sys.stdin.read().strip().split()
N = int(input_data[0])
Q = int(input_data[1])

points = []
idx = 2

for _ in range(N):
    x = float(input_data[idx])
    y = float(input_data[idx + 1])
    points.append((x, y))
    idx += 2

dist_matrix = [[0.0] * N for _ in range(N)]
for i in range(N):
    for j in range(i + 1, N):
        dx = points[i][0] - points[j][0]
        dy = points[i][1] - points[j][1]
        d = math.hypot(dx, dy)
        dist_matrix[i][j] = d
        dist_matrix[j][i] = d

epsilon = 0.0001

output = []

for _ in range(Q):
    qx = float(input_data[idx])
    qy = float(input_data[idx + 1])
    idx += 2

    dist_Q = []
    for i in range(N):
        dx = qx - points[i][0]
        dy = qy - points[i][1]
        dist_Q.append(math.hypot(dx, dy))

    count_iso = 0

    for i in range(N):
        for j in range(i + 1, N):
            d1 = dist_Q[i]
            d2 = dist_Q[j]
            d3 = dist_matrix[i][j]

            if (abs(d1 - d2) < epsilon) or (abs(d1 - d3) < epsilon) or (abs(d2 - d3) < epsilon):
                count_iso += 1

    output.append(str(count_iso))
print("\n".join(output))