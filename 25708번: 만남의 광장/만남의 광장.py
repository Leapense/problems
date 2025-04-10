import sys

input = sys.stdin.readline

N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
rowSum = [sum(r) for r in grid]
colSum = [sum(grid[i][j] for i in range(N)) for j in range(M)]
ans = -10**18

for i in range(N):
    for k in range(i + 1, N):
        A = k - i - 1
        arr = [colSum[j] - (grid[i][j] + grid[k][j]) for j in range(M)]
        best = -10**18
        best_val = -10**18
        for l in range(1, M):
            best = max(best, arr[l - 1] - A * (l - 1))
            candidate = best + arr[l] + A * l - A
            best_val = max(best_val, candidate)
        ans = max(ans, rowSum[i] + rowSum[k] + best_val)

sys.stdout.write(str(ans))