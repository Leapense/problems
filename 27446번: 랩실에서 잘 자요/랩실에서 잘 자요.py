class Solution:
    def solve(self):
        import sys
        input_data = sys.stdin.read().strip().split()
        N, M = map(int, input_data[:2])
        if M > 0:
            pages = list(map(int, input_data[2:2+M]))
        else:
            pages = []

        have = set(pages)
        missing = [i for i in range(1, N + 1) if i not in have]
        if not missing:
            print(0)
            return
        
        missing.sort()
        k = len(missing)
        dp = [0] * (k + 1)
        for i in range(k - 1, -1, -1):
            dp[i] = float('inf')
            for j in range(i, k):
                cost = 5 + 2 * (missing[j] - missing[i] + 1)
                dp[i] = min(dp[i], cost + dp[j+1])
        print(dp[0])

if __name__ == "__main__":
    Solution().solve()