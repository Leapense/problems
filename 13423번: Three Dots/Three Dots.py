def count_evenly_spaced_points(points):
    points.sort()
    point_set = set(points)
    count = 0

    n = len(points)
    for i in range(n):
        for j in range(i + 1, n):
            if (points[i] + points[j]) % 2 == 0:
                mid = (points[i] + points[j]) // 2
                if mid in point_set:
                    count += 1
    
    return count

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    points = list(map(int, input().split()))
    print(count_evenly_spaced_points(points))