import sys

input = sys.stdin.readline
n, m = map(int, input().split())
L = 10000.0
a = L / n
b = L / (n + m)
dp = [[float('inf')] * (n + m + 1) for _ in range(n + 1)]
for j in range(n + m + 1):
    dp[0][j] = 0.0

def circ_dist(x, y):
    d = abs(x - y)
    return min(d, L - d)

for j in range(1, n + m + 1):
    for i in range(1, min(j, n) + 1):
        cost = circ_dist((i - 1) * a, (j - 1) * b)
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + cost)

print(f"{dp[n][n + m]:.4f}")