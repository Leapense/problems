import sys
from collections import deque

def main():
    input = sys.stdin.readline
    N, M, K = map(int, input().split())

    blocked = [[False] * M for _ in range(N)]
    for _ in range(K):
        y, x = map(int, input().split())
        blocked[y][x] = True

    if blocked[0][0] or blocked[N-1][M-1]:
        print(-1)
        return
    
    dist = [[-1] * M for _ in range(N)]
    dist[0][0] = 0
    q = deque([(0, 0)])
    while q:
        r, c = q.popleft()
        if r % 2 == 0:
            neigh = [(0, -1), (0, 1), (-1, -1), (-1, 0), (1, -1), (1, 0)]
        else:
            neigh = [(0, -1), (0, 1), (-1, 0), (-1, 1), (1, 0), (1, 1)]

        for dr, dc in neigh:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M and not blocked[nr][nc] and dist[nr][nc] == -1:
                dist[nr][nc] = dist[r][c] + 1
                if nr == N - 1 and nc == M - 1:
                    print(dist[nr][nc])
                    return
                
                q.append((nr, nc))
    print(-1)

if __name__ == "__main__":
    main()