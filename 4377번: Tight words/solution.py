def tight_word_percent(k: int, n: int) -> float:
    dp = [1] * (k + 1)
    for _ in range(1, n):
        ndp = [0] * (k + 1)
        for j in range(k + 1):
            if j > 0:
                ndp[j] += dp[j - 1]
            ndp[j] += dp[j]
            if j < k:
                ndp[j] += dp[j + 1]
        dp = ndp
    
    total_tight = sum(dp)
    total_words = (k + 1) ** n
    percent = 100.0 * total_tight / total_words
    return percent

def main():
    import sys
    for line in sys.stdin:
        if not line.strip():
            continue
        k, n = map(int, line.strip().split())
        print(f"{tight_word_percent(k, n):.5f}")

if __name__ == "__main__":
    main()