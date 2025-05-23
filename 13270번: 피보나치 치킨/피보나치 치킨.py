def fibonacci_sets(N):
    sets = []
    a, b = 2, 1
    while a <= N:
        if a > b:
            sets.append((a, b))

        a, b = a + b, a
    return sets

def solve(N):
    sets = fibonacci_sets(N)
    INF = 10**9
    dp_min = [INF] * (N + 1)
    dp_max = [-1] * (N + 1)
    dp_min[0] = 0
    dp_max[0] = 0

    for i in range(1, N + 1):
        for p, c in sets:
            if i - p >= 0:
                if dp_min[i - p] != INF:
                    dp_min[i] = min(dp_min[i], dp_min[i - p] + c)
                if dp_max[i - p] != -1:
                    dp_max[i] = max(dp_max[i], dp_max[i - p] + c)
    return dp_min[N], dp_max[N]

if __name__ == "__main__":
    N = int(input().strip())
    mn, mx = solve(N)
    print(mn, mx)