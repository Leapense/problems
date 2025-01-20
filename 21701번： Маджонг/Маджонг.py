import sys
from collections import deque

def main():
    sys.setrecursionlimit(1 << 25)
    m, n = map(int, sys.stdin.readline().split())
    grid = []
    color_positions = dict()
    for x in range(m):
        row = list(map(int, sys.stdin.readline().split()))
        grid.append(row)
        for y in range(n):
            color = row[y]
            if color not in color_positions:
                color_positions[color] = []
            color_positions[color].append((x, y))
    rows = [deque() for _ in range(m)]
    columns = [deque() for _ in range(n)]
    for x in range(m):
        for y in range(n):
            rows[x].append(y)
    for y in range(n):
        for x in range(m):
            columns[y].append(x)
    grid_map = [[0]*n for _ in range(m)]
    for color, positions in color_positions.items():
        for (x, y) in positions:
            grid_map[x][y] = color
    removable = deque()
    removed = set()
    in_queue = set()
    def is_removable(color):
        (x1, y1), (x2, y2) = color_positions[color]
        if color in removed:
            return False
        left1 = rows[x1][0] == y1
        right1 = rows[x1][-1] == y1
        left2 = rows[x2][0] == y2
        right2 = rows[x2][-1] == y2
        top1 = columns[y1][0] == x1
        bottom1 = columns[y1][-1] == x1
        top2 = columns[y2][0] == x2
        bottom2 = columns[y2][-1] == x2
        if (left1 and left2) or (right1 and right2) or (top1 and top2) or (bottom1 and bottom2):
            return True
        return False
    for color in color_positions:
        if is_removable(color):
            removable.append(color)
            in_queue.add(color)
    result = []
    while removable:
        color = removable.popleft()
        in_queue.discard(color)
        if color in removed:
            continue
        result.append(color)
        removed.add(color)
        (x1, y1), (x2, y2) = color_positions[color]
        for (x, y) in [(x1, y1), (x2, y2)]:
            if y in rows[x]:
                rows[x].remove(y)
            if x in columns[y]:
                columns[y].remove(x)
            if rows[x]:
                new_left = rows[x][0]
                new_right = rows[x][-1]
                new_color = grid_map[x][new_left]
                if new_color not in removed and is_removable(new_color) and new_color not in in_queue:
                    removable.append(new_color)
                    in_queue.add(new_color)
                new_color = grid_map[x][new_right]
                if new_color not in removed and is_removable(new_color) and new_color not in in_queue:
                    removable.append(new_color)
                    in_queue.add(new_color)
            if columns[y]:
                new_top = columns[y][0]
                new_bottom = columns[y][-1]
                new_color = grid_map[new_top][y]
                if new_color not in removed and is_removable(new_color) and new_color not in in_queue:
                    removable.append(new_color)
                    in_queue.add(new_color)
                new_color = grid_map[new_bottom][y]
                if new_color not in removed and is_removable(new_color) and new_color not in in_queue:
                    removable.append(new_color)
                    in_queue.add(new_color)
    print(len(result))
    print(' '.join(map(str, result)))
if __name__ == "__main__":
    main()