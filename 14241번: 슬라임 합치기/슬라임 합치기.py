N, *rest = map(int, open(0).read().split())
A = rest[:N]
prefix = [0] * (N + 1)

for i in range(N):
    prefix[i + 1] = prefix[i] + A[i]

dp = [[0] * N for _ in range(N)]
for length in range(2, N + 1):
    for i in range(N - length + 1):
        j = i + length - 1
        for k in range(i, j):
            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + (prefix[k + 1] - prefix[i]) * (prefix[j + 1] - prefix[k + 1]))
print(dp[0][N-1])