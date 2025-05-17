from sys import stdin, setrecursionlimit
from collections import deque

def solve():
    setrecursionlimit(10000)

    results = []
    while True:
        line = ''
        while line.strip() == '':
            line = stdin.readline()
            if not line:
                return
        W, H = map(int, line.strip().split())
        if W == 0 and H == 0:
            break

        grid = []
        start = None
        for y in range(H):
            row = stdin.readline().strip()
            grid.append(list(row))
            if '@' in row:
                start = (y, row.index('@'))

        visited = [[False for _ in range(W)] for _ in range(H)]
        q = deque()
        sy, sx = start
        q.append((sy, sx))
        visited[sy][sx] = True
        count = 1

        for_dy_dx = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:
            y, x = q.popleft()
            for dy, dx in for_dy_dx:
                ny, nx = y + dy, x + dx
                if 0 <= ny < H and 0 <= nx < W:
                    if not visited[ny][nx] and grid[ny][nx] in ('.', '@'):
                        visited[ny][nx] = True
                        q.append((ny, nx))
                        count += 1
        results.append(str(count))
    print('\n'.join(results))

if __name__ == "__main__":
    solve()