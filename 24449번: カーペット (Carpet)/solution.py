from collections import deque

def solve():
    h, w = map(int, input().split())
    grid = [list(input().strip()) for _ in range(h)]

    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    visited = [[False] * w for _ in range(h)]

    queue = deque()
    queue.append((0, 0, 0))
    visited[0][0] = True

    while queue:
        x, y, steps = queue.popleft()
        if x == h - 1 and y == w - 1:
            print(steps)
            return
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < h and 0 <= ny < w:
                if not visited[nx][ny] and grid[nx][ny] != grid[x][y]:
                    visited[nx][ny] = True
                    queue.append((nx, ny, steps + 1))
    print(-1)

if __name__ == "__main__":
    solve()