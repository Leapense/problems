MOD = 987654321

def count_valid_numbers(n: int) -> int:
    if n <= 0:
        return 0
    dp = [0] * 10

    for d in range(1, 10):
        dp[d] = 1
    if n == 1:
        return 9
    neighbors = [[] for _ in range(10)]
    for d in range(1, 10):
        start = max(1, d - 2)
        end = min(9, d + 2)
        neighbors[d] = list(range(start, end + 1))
    for _ in range(2, n + 1):
        next_dp = [0] * 10
        for d in range(1, 10):
            s = 0
            for p in neighbors[d]:
                s += dp[p]
            next_dp[d] = s % MOD
        dp = next_dp
    total = 0
    for d in range(1, 10):
        total += dp[d]
    return total % MOD

def main() -> None:
    n_str = input().strip()
    n = int(n_str)
    print(count_valid_numbers(n))

if __name__ == "__main__":
    main()