from collections import deque
import sys

def read_input():
    lines = sys.stdin.read().splitlines()
    return lines

def find_shortest_path(R, C, maze):
    for i in range(R):
        for j in range(C):
            if maze[i][j] == 'S':
                start = (i, j)
                break
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    visited = [[False for _ in range(C)] for _ in range(R)]
    queue = deque()
    queue.append((start[0], start[1], 0))
    visited[start[0]][start[1]] = True
    while queue:
        x, y, moves = queue.popleft()
        if maze[x][y] == 'G':
            return moves
        
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < R and 0 <= ny < C:
                if not visited[nx][ny] and maze[nx][ny] != 'X':
                    visited[nx][ny] = True
                    queue.append( (nx, ny, moves +1) )

    return -1

def main():
    lines = read_input()
    idx = 0
    T = int(lines[idx].strip())
    idx += 1

    results = []
    for _ in range(T):
        while idx < len(lines) and lines[idx].strip() == '':
            idx += 1
        if idx >= len(lines):
            break
        R_C = lines[idx].strip().split()
        R, C = map(int, R_C)
        idx += 1
        maze = []
        for _ in range(R):
            while idx < len(lines) and lines[idx].strip() == '':
                idx += 1
            if idx >= len(lines):
                maze.append('')
            else:
                line = lines[idx].rstrip()
                maze.append(line)
                idx += 1
        shortest = find_shortest_path(R, C, maze)
        if shortest != -1:
            results.append(f"Shortest Path: {shortest}")
        else:
            results.append("No Exit")

    for res in results:
        print(res)

if __name__ == '__main__':
    main()