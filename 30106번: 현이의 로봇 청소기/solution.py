import sys
from collections import deque

def main():
    data = list(map(int, sys.stdin.read().split()))
    if not data:
        return
    it = iter(data)
    N = next(it); M = next(it); K = next(it)
    H = [[next(it) for _ in range(M)] for _ in range(N)]

    visited = [[False] * M for _ in range(N)]
    dirs = [(1,0), (-1,0), (0,1), (0,-1)]

    def bfs(sr, sc):
        q = deque()
        q.append((sr, sc))
        visited[sr][sc] = True
        while q:
            r, c = q.popleft()
            h = H[r][c]
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M and not visited[nr][nc]:
                    if abs(h - H[nr][nc]) <= K:
                        visited[nr][nc] = True
                        q.append((nr, nc))

    components = 0
    for r in range(N):
        for c in range(M):
            if not visited[r][c]:
                bfs(r, c)
                components += 1
    print(components)

if __name__ == "__main__":
    main()