import sys
from collections import deque

def main():
    input = sys.stdin.readline
    R, C = map(int, input().split())
    grid = [input().rstrip() for _ in range(R)]
    visited = [[False] * C for _ in range(R)]

    total_sheep = 0
    total_wolf = 0

    dirs = ((1,0),(-1,0),(0,1),(0,-1))

    for i in range(R):
        for j in range(C):
            if visited[i][j] or grid[i][j] == '#':
                continue
            q = deque()
            visited[i][j] = True
            q.append((i,j))
            sheep = 0
            wolf = 0

            while q:
                x, y = q.popleft()
                if grid[x][y] == 'k':
                    sheep += 1
                elif grid[x][y] == 'v':
                    wolf += 1

                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < R and 0 <= ny < C:
                        if not visited[nx][ny] and grid[nx][ny] != '#':
                            visited[nx][ny] = True
                            q.append((nx, ny))

            if sheep > wolf:
                total_sheep += sheep
            else:
                total_wolf += wolf

    print(total_sheep, total_wolf)

if __name__ == "__main__":
    main()