def main():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    n = int(data[0])
    dots = []
    for i in range(n):
        x = int(data[2 * i + 1])
        y = int(data[2 * i + 2])
        dots.append((x, y))
    
    current = (0, 0)
    # List to store the intermediate points (excluding the starting point (0,0))
    out_points = []
    
    # For each dot, add a horizontal segment (if needed) and then a vertical segment (if needed)
    for dot in dots:
        target_x, target_y = dot
        # If x coordinate is different, move horizontally first.
        if current[0] != target_x:
            out_points.append((target_x, current[1]))
        # Then move vertically to the dot.
        if current[1] != target_y:
            out_points.append((target_x, target_y))
        current = (target_x, target_y)
    
    # Print the number of segments and then each point.
    # Note: The starting point (0,0) is implicit.
    sys.stdout.write(str(len(out_points)) + "\n")
    for x, y in out_points:
        sys.stdout.write(f"{x} {y}\n")
    
if __name__ == '__main__':
    main()
