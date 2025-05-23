import sys
input = sys.stdin.readline
import bisect

N = int(input().strip())
points = [tuple(map(int, input().split())) for _ in range(N)]

slope_signs = [0] * (N + 1)

x_coords = [points[i][0] for i in range(N)]

for i in range(N - 1):
    _, y1 = points[i]
    _, y2 = points[i + 1]

    diff = y2 - y1

    if diff > 0:
        slope_signs[i] = 1
    elif diff < 0:
        slope_signs[i] = -1
    else:
        slope_signs[i] = 0

Q = int(input().strip())

for _ in range(Q):
    k = float(input().strip())

    idx = bisect.bisect_left(x_coords, k) - 1
    print(slope_signs[idx])