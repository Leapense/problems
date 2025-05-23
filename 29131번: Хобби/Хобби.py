def orientation(p, q, r):
    # Find the orientation of the ordered triplet (p, q, r).
    # 0 -> p, q and r are collinear
    # 1 -> Clockwise
    # 2 -> Counterclockwise
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2

def do_intersect(p1, q1, p2, q2):
    # Check if line segment 'p1q1' and 'p2q2' intersect
    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    # General case
    if o1 != o2 and o3 != o4:
        return True

    return False

def solve():
    n = int(input())
    points = [tuple(map(int, input().split())) for _ in range(n)]
    segments = []
    
    # Sort points by x-coordinate
    sorted_points = sorted(range(n), key=lambda i: points[i])
    
    # Attempt to connect each consecutive point if it does not intersect existing segments
    for i in range(0, n, 2):
        if i + 1 < n:
            new_segment = (sorted_points[i], sorted_points[i + 1])
            intersect = False
            for seg in segments:
                if do_intersect(points[seg[0]], points[seg[1]], points[new_segment[0]], points[new_segment[1]]):
                    intersect = True
                    break
            if not intersect:
                segments.append(new_segment)
    
    # Output results
    print(len(segments))
    for a, b in segments:
        # Output 1-indexed positions
        print(a + 1, b + 1)


solve()