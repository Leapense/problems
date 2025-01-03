MOD = 10 ** 9 + 7
T, M, N = map(int, input().split())
size = N - M + 1
prev = [1] * size

for _ in range(T - 1):
    current = [0] * size

    for i in range(size):
        if i > 0:
            current[i] += prev[i - 1]
        if i < size - 1:
            current[i] += prev[i + 1]
        current[i] %= MOD
    prev = current
print(sum(prev) % MOD)