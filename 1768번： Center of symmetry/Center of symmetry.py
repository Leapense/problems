def has_center_of_symmetry(points):
    n = len(points)

    sum_x = sum(p[0] for p in points)
    sum_y = sum(p[1] for p in points)

    center_x = sum_x / n
    center_y = sum_y / n

    point_set = set(points)

    for x, y in points:
        qx = 2 * center_x - x
        qy = 2 * center_y - y

        if (qx, qy) not in point_set:
            return False
    return True

def main():
    import sys
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    
    c = int(input_data[0])
    index = 1
    results = []

    for _ in range(c):
        n = int(input_data[index])
        index += 1
        points = []

        for _ in range(n):
            x = int(input_data[index])
            y = int(input_data[index + 1])
            points.append((x, y))
            index += 2
        results.append("yes" if has_center_of_symmetry(points) else "no")
    
    print("\n".join(results))

if __name__ == "__main__":
    main()