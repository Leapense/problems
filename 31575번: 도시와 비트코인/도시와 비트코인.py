def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(M)]
    dp = [[False] * N for _ in range(M)]
    dp[0][0] = True
    
    for i in range(M):
        for j in range(N):
            if grid[i][j] != 1:
                continue
            if i == 0 and j == 0:
                continue
            if i > 0 and dp[i - 1][j]:
                dp[i][j] = True
            if j > 0 and dp[i][j - 1]:
                dp[i][j] = True

    print("Yes" if dp[M - 1][N - 1] else "No")

if __name__ == "__main__":
    main()