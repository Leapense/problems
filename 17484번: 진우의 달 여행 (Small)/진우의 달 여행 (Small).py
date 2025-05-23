import sys

def solve():
    N, M = map(int, sys.stdin.readline().split())
    grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    INF = float('inf')
    dp = [[[INF] * 4 for _ in range(M)] for _ in range(N)]

    for j in range(M):
        dp[0][j][3] = grid[0][j]

    directions = [(1, 0), (1, -1), (1, 1)]

    for i in range(N - 1):
        for j in range(M):
            for k in range(4):
                if dp[i][j][k] == INF:
                    continue
                for d in range(3):
                    if d == k:
                        continue
                    ni, nj = i + directions[d][0], j + directions[d][1]
                    if 0 <= ni < N and 0 <= nj < M:
                        dp[ni][nj][d] = min(dp[ni][nj][d], dp[i][j][k] + grid[ni][nj])

    result = INF
    for j in range(M):
        for k in range(3):
            result = min(result, dp[N-1][j][k])
    print(result)

solve()