import sys

MOD = 1_000_000_007

def solve():
    input = sys.stdin.readline
    N, H = map(int, input().split())
    A = list(map(int, input().split()))

    freq = [0] * 101
    for x in A:
        if 1 <= x <= 100:
            freq[x] += 1

    dp = [0] * (H + 1)
    dp[0] = 1

    for h in range(1, H + 1):
        s = 0
        for a in range(1, 101):
            fa = freq[a]
            if fa and h >= a:
                s += fa * dp[h - a]
                if s >= (1 << 63):
                    s %= MOD
        dp[h] = s % MOD

    print(dp[H] % MOD)

if __name__ == "__main__":
    solve()
