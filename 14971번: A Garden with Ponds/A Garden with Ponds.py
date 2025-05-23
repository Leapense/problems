import sys

def main():
    data = sys.stdin.read().split()
    idx = 0
    while idx < len(data):
        d = int(data[idx])
        w = int(data[idx + 1])
        idx += 2
        if d == 0 and w == 0:
            break
        grid = []
        for _ in range(d):
            row = list(map(int, data[idx : idx + w]))
            grid.append(row)
            idx += w
        max_cap = 0
        for top in range(d - 2):
            for left in range(w - 2):
                for bottom in range(top + 2, d):
                    for right in range(left + 2, w):
                        outer = []
                        for x in range(left, right + 1):
                            outer.append(grid[top][x])
                            outer.append(grid[bottom][x])
                        for y in range(top + 1, bottom):
                            outer.append(grid[y][left])
                            outer.append(grid[y][right])
                        min_outer = min(outer)
                        inner = []
                        valid = True
                        for y in range(top + 1, bottom):
                            for x in range(left + 1, right):
                                if grid[y][x] >= min_outer:
                                    valid = False
                                    break
                                inner.append(grid[y][x])
                            if not valid:
                                break
                        if valid:
                            cap = sum(min_outer - val for val in inner)
                            if cap > max_cap:
                                max_cap = cap

        print(max_cap)

if __name__ == '__main__':
    main()