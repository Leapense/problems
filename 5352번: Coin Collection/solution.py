import sys

def max_coins(grid):
    n = len(grid)
    m = len(grid[0])
    dp = [[0] * (m) for _ in range(n)]

    val0 = 1 if grid[0][0] == 'C' else 0
    dp[0][0] = val0

    for j in range(1, m):
        dp[0][j] = dp[0][j - 1] + (1 if grid[0][j] == 'C' else 0)

    for i in range(1, n):
        dp[i][0] = dp[i - 1][0] + (1 if grid[i][0] == 'C' else 0)

    for i in range(1, n):
        for j in range(1, m):
            best_prev = dp[i - 1][j] if dp[i-1][j] > dp[i][j-1] else dp[i][j-1]
            dp[i][j] = best_prev + (1 if grid[i][j] == 'C' else 0)

    return dp[n-1][m-1]

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        n = int(next(it))
        m = int(next(it))
        grid = [next(it).strip() for _ in range(n)]
        out.append(str(max_coins(grid)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()