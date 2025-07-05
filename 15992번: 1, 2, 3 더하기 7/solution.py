MOD = 1000000009

def solve_123_sum_with_m_terms(test_cases):
    max_n = max(n for n, m in test_cases)
    max_m = max(m for n, m in test_cases)
    dp = [[0] * (max_m + 2) for _ in range(max_n + 4)]
    dp[0][0] = 1
    for i in range(1, max_n + 1):
        for j in range(1, max_m + 1):
            if i - 1 >= 0:
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD
            if i - 2 >= 0:
                dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % MOD
            if i - 3 >= 0:
                dp[i][j] = (dp[i][j] + dp[i - 3][j - 1]) % MOD

    results = []
    for n, m in test_cases:
        results.append(dp[n][m] % MOD)
    return results

def main():
    T = int(input())
    test_cases = []
    for _ in range(T):
        line = input().strip()
        if not line:
            continue

        parts = line.split()
        n = int(parts[0])
        m = int(parts[1])
        test_cases.append((n, m))
    results = solve_123_sum_with_m_terms(test_cases)
    for res in results:
        print(res)

if __name__ == "__main__":
    main()