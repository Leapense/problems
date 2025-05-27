import sys

def solve():
    """Pearls 문제 해결. DP를 통해 최소 비용을 계산"""
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1

    outputs = []
    for _ in range(t):
        c = int(data[idx])
        idx += 1

        needs = [0] * (c + 1)
        prices = [0] * (c + 1)
        for i in range(1, c + 1):
            needs[i] = int(data[idx])
            prices[i] = int(data[idx + 1])
            idx += 2

        prefix_sum = [0] * (c + 1)
        for j in range(1, c + 1):
            prefix_sum[j] = prefix_sum[j - 1] + needs[j]

        INF = 10 ** 18
        dp = [INF] * (c + 1)
        dp[0] = 0

        for j in range(1, c + 1):
            for k in range(1, j + 1):
                total_pearls = prefix_sum[j] - prefix_sum[k - 1]
                cost = dp[k - 1] + (total_pearls + 10) * prices[j]
                if cost < dp[j]:
                    dp[j] = cost

        outputs.append(str(dp[c]))

    print("\n".join(outputs))

if __name__ == "__main__":
    solve()