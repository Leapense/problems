import sys

sys.setrecursionlimit(2000)

def solve():
    n, m = map(int, sys.stdin.readline().split())
    sum_of_squares = [0] * (m + 1)
    for i in range(1, m + 1):
        sum_of_squares[i] = sum_of_squares[i-1] + i * i

    def get_depression(days, start_mood):
        if start_mood > days:
            return 0
        depressed_days = days - start_mood
        return sum_of_squares[depressed_days]
    
    if n == 0:
        print(sum_of_squares[m])
        return

    happiness = list(map(int, sys.stdin.readline().split()))
    dp = [[float('inf')] * m for _ in range(n)]
    initial_depression = 0
    for j in range(m):
        if j > 0:
            initial_depression += j * j
        if m - 1 - j >= n - 1:
            dp[0][j] = initial_depression

    def compute(i, j_start, j_end, k_start, k_end):
        if j_start > j_end:
            return

        j_mid = (j_start + j_end) // 2
        k_mid = -1

        search_k_end = min(j_mid - 1, k_end)
        for k in range(k_start, search_k_end + 1):
            if dp[i-1][k] == float('inf'):
                continue

            cost = dp[i-1][k] + get_depression(j_mid - k - 1, happiness[i-1])
            if cost < dp[i][j_mid]:
                dp[i][j_mid] = cost
                k_mid = k
        
        if k_mid != -1:
            compute(i, j_start, j_mid - 1, k_start, k_mid)
            compute(i, j_mid + 1, j_end, k_mid, k_end)

    for i in range(1, n):
        compute(i, i, m - 1, i - 1, m - 2)

    min_total_depression = float('inf')
    for j in range(n - 1, m):
        if dp[n-1][j] == float('inf'):
            continue

        remaining_days = m - 1 - j
        final_dep = get_depression(remaining_days, happiness[n-1])
        total_depression = dp[n-1][j] + final_dep
        min_total_depression = min(min_total_depression, total_depression)

    print(min_total_depression)

solve()