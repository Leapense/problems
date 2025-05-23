def can_connect_plug(n, d, socket_details):
    import math
    
    points = []
    for details in socket_details:
        x, y, t = map(int, details.split())
        points.append((x, y, t))

    for i in range(n):
        x1, y1, t1 = points[i]
        for j in range(i + 1, n):
            x2, y2, t2 = points[j]
            distance = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

            if math.isclose(distance, d, rel_tol=1e-9) and t1 != t2:
                return 'Yes'
    return 'No'

n, d = map(int, input().split())
socket_details = []
for _ in range(n):
    socket_details.append(input())

print(can_connect_plug(n, d, socket_details))