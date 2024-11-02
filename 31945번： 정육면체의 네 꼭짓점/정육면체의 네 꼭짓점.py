def is_on_same_face(a, b, c, d):
    points = [
        (0, 0, 0), (0, 0, 1), (0, 1, 0), (0, 1, 1),
        (1, 0, 0), (1, 0, 1), (1, 1, 0), (1, 1, 1)
    ]
    x = [points[i][0] for i in [a, b, c, d]]
    y = [points[i][1] for i in [a, b, c, d]]
    z = [points[i][2] for i in [a, b, c, d]]
    return (len(set(x)) == 1 or len(set(y)) == 1 or len(set(z)) == 1) and len(set(x)) <= 2 and len(set(y)) <= 2 and len(set(z)) <= 2


T = int(input())
for _ in range(T):
    a, b, c, d = map(int, input().split())
    result = "YES" if is_on_same_face(a, b, c, d) else "NO"
    print(result)