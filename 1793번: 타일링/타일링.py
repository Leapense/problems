def main():
    import sys
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    
    test_cases = [int(n) for n in input_data]
    max_n = max(test_cases)
    dp = [0] * (max_n + 1)

    dp[0] = 1
    if max_n >= 1:
        dp[1] = 1

    for i in range(2, max_n + 1):
        dp[i] = dp[i-1] + 2 * dp[i-2]

    results = []
    for n in test_cases:
        results.append(str(dp[n]))

    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    main()