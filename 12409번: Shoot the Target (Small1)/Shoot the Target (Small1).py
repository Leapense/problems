import math

def angle(x, x1, y1, x2, y2):
    ax = math.atan2(y1, x1 - x)
    bx = math.atan2(y2, x2 - x)
    res = abs(ax - bx)
    if res > math.pi:
        res = 2 * math.pi - res
    return math.degrees(res)

def ternary_search(x1, y1, x2, y2):
    left, right = -1e4, 1e4
    for _ in range(100):
        l = left + (right - left) / 3
        r = right - (right - left) / 3
        if angle(l, x1, y1, x2, y2) < angle(r, x1, y1, x2, y2):
            left = l
        else:
            right = r
    return angle((left + right) / 2, x1, y1, x2, y2)

T = int(input())
for case in range(1, T + 1):
    x1, y1, x2, y2 = map(int, input().split())
    ans = ternary_search(x1, y1, x2, y2)
    print(f"Case #{case}: {ans:.10f}")