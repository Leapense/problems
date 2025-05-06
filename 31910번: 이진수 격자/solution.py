import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    grid = [list(map(int, input().split())) for _ in range(N)]

    dp = [[0] * N for _ in range(N)]
    dp[0][0] = grid[0][0]

    for i in range(N):
        for j in range(N):
            if i == 0 and j == 0:
                continue
            best = -1
            if i > 0:
                best = dp[i-1][j]
            if j > 0:
                best = max(best, dp[i][j-1])
            dp[i][j] = (best << 1) | grid[i][j]

    print(dp[N-1][N-1])

if __name__ == "__main__":
    main()