from collections import deque

def percolates(grid):
    M = len(grid)
    N = len(grid[0])
    visited = [[False] * N for _ in range(M)]
    queue = deque()

    for j in range(N):
        if grid[0][j] == '0':
            queue.append((0, j))
            visited[0][j] = True

    directions = [(-1,0),(1,0),(0,-1),(0,1)]

    while queue:
        x, y = queue.popleft()
        if x == M - 1:
            return "YES"
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < M and 0 <= ny < N:
                if not visited[nx][ny] and grid[nx][ny] == '0':
                    visited[nx][ny] = True
                    queue.append((nx, ny))
    return "NO"

N, M = map(int, input().split())
grid = [input().strip() for _ in range(N)]
results = percolates(grid)
print(results)