#!/usr/bin/env python3
import sys

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    moves = input().strip()

    directions = [(0, -1), (1, 0), (0, 1), (-1, 0)]
    x, y = 0, 0
    dir_idx = 2

    visited = set()
    visited.add((x, y))

    for move in moves:
        if move == 'F':
            dx, dy = directions[dir_idx]
            x += dx
            y += dy
            visited.add((x, y))
        elif move == 'L':
            dir_idx = (dir_idx - 1) % 4
        elif move == 'R':
            dir_idx = (dir_idx + 1) % 4

    min_x = min(p[0] for p in visited)
    max_x = max(p[0] for p in visited)
    min_y = min(p[1] for p in visited)
    max_y = max(p[1] for p in visited)

    maze = []
    for y_coord in range(min_y, max_y + 1):
        row = []
        for x_coord in range(min_x, max_x + 1):
            if (x_coord, y_coord) in visited:
                row.append('.')
            else:
                row.append('#')
        maze.append(''.join(row))

    print("\n".join(maze))

if __name__ == "__main__":
    main()