import sys

def main():
    R, C = map(int, sys.stdin.readline().split())
    K = int(sys.stdin.readline().strip())
    blocked = [[False] * (C + 1) for _ in range(R + 1)]
    for _ in range(K):
        r, c = map(int, sys.stdin.readline().split())
        blocked[r][c] = True

    dp = [[0] * (C + 1) for _ in range(R + 1)]
    dp[1][1] = 1

    for i in range(1, R + 1):
        for j in range(1, C + 1):
            if blocked[i][j] or (i == 1 and j == 1):
                continue
            dp[i][j] = dp[i-1][j] + dp[i][j-1]

    print(dp[R][C])

if __name__ == "__main__":
    main()