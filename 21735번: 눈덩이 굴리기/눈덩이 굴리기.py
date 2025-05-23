N, M = map(int, input().split())
a = list(map(int, input().split()))
dp = [[-1] * (N+1) for _ in range(M+1)]
dp[0][0] = 1

for t in range(M):
    for i in range(N+1):
        if dp[t][i] == -1:
            continue
        if i+1 <= N:
            dp[t+1][i+1] = max(dp[t+1][i+1], dp[t][i] + a[i])
        if i+2 <= N:
            new_size = dp[t][i]//2 + a[i+1]
            dp[t+1][i+2] = max(dp[t+1][i+2], new_size)
result = 0
for t in range(M+1):
    for i in range(N+1):
        if dp[t][i] > result:
            result = dp[t][i]
print(result)