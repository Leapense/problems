import sys
from collections import deque

data = sys.stdin.read().split()
it = iter(data)
n = int(next(it))
grid_type = []
grid_color = []
for _ in range(n):
    row_t = []
    row_c = []
    for _ in range(n):
        row_t.append(next(it))
        row_c.append(int(next(it)))
    grid_type.append(row_t)
    grid_color.append(row_c)

def compute_score(grid):
    visited = [[False] * n for _ in range(n)]
    max_by_key = {}
    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for r in range(n):
        for c in range(n):
            if visited[r][c]:
                continue
            key = grid[r][c]
            q = deque()
            q.append((r, c))
            visited[r][c] = True
            size = 0
            while q:
                y, x = q.popleft()
                size += 1
                for dy, dx in dirs:
                    ny = y + dy
                    nx = x + dx
                    if 0 <= ny < n and 0 <= nx < n and (not visited[ny][nx]) and grid[ny][nx] == key:
                        visited[ny][nx] = True
                        q.append((ny, nx))
            if key in max_by_key:
                if size > max_by_key[key]:
                    max_by_key[key] = size
            else:
                max_by_key[key] = size
    total = 0
    for v in max_by_key.values():
        if v >= 2:
            total += v * (v - 1) // 2
    return total

score_types = compute_score(grid_type)
score_colors = compute_score(grid_color)
print(f"{score_types} {score_colors}")