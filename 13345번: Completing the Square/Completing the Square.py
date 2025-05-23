points = [tuple(map(int, input().split())) for _ in range(3)]
dists = [
    ((points[0][0] - points[1][0]) ** 2 + (points[0][1] - points[1][1]) ** 2, (0,1)),
    ((points[0][0] - points[2][0]) ** 2 + (points[0][1] - points[2][1]) ** 2, (0,2)),
    ((points[1][0] - points[2][0]) ** 2 + (points[1][1] - points[2][1]) ** 2, (1,2))
]

max_dist, pair = max(dists, key=lambda x : x[0])
i, j = pair

k = 3 - i - j

mid_x = (points[i][0] + points[j][0]) / 2
mid_y = (points[i][1] + points[j][1]) / 2
missing_x = int(2 * mid_x - points[k][0])
missing_y = int(2 * mid_y - points[k][1])
print(missing_x, missing_y)