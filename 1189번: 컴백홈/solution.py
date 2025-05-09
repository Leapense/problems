import sys

def solve():
    R, C, K = map(int, sys.stdin.readline().split())
    grid = [sys.stdin.readline().strip() for _ in range(R)]
    visited = [[False for _ in range(C)] for _ in range(R)]
    ans = 0

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    start_r, start_c = R - 1, 0
    target_r, target_c = 0, C - 1

    def dfs(r, c, dist):
        nonlocal ans

        if dist > K:
            return
        
        manhattan_dist_to_target = abs(target_r - r) + abs(target_c - c)
        if (K - dist) < manhattan_dist_to_target:
            return
        
        if r == target_r and c == target_c:
            if dist == K:
                ans += 1
            return
        
        visited[r][c] = True

        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]
            if 0 <= nr < R and 0 <= nc < C:
                if not visited[nr][nc] and grid[nr][nc] == '.':
                    dfs(nr, nc, dist + 1)

        visited[r][c] = False

    if grid[start_r][start_c] == 'T':
        print(0)
    else:
        dfs(start_r, start_c, 1)
        print(ans)

if __name__ == "__main__":
    solve()