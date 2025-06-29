import sys

def solve():
    """
    Calculates the secured perimeter of a rectilinear polygon.
    """
    try:
        n_str = sys.stdin.readline()
        if not n_str:
            return
        n = int(n_str)

        points = []
        for _ in range(n):
            points.append(list(map(int, sys.stdin.readline().split())))

        if not points:
            print(0)
            return

        x_coords = [p[0] for p in points]
        y_coords = [p[1] for p in points]
        min_x = min(x_coords)
        max_x = max(x_coords)
        min_y = min(y_coords)
        max_y = max(y_coords)

        bounding_box_perimeter = 2 * ((max_x - min_x) + (max_y - min_y))

        total_perimeter = 0
        for i in range(n):
            p1 = points[i]
            p2 = points[(i + 1) % n]
            dx = abs(p1[0] - p2[0])
            dy = abs(p1[1] - p2[1])
            total_perimeter += dx + dy

        secured_perimeter = total_perimeter - bounding_box_perimeter
        print(secured_perimeter)
    except (IOError, ValueError) as e:
        pass

if __name__ == "__main__":
    solve()