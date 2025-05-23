class Solution:
    def solve(self):
        import sys
        input = sys.stdin.readline
        N, L = map(int, input().split())
        arr = list(map(int, input().split()))
        prefix = [0] * (N + 1)
        for i in range(N):
            prefix[i + 1] = prefix[i] + arr[i]
        count = 0
        for i in range(1, N + 1):
            start = i - L if i - L >= 0 else 0
            s = prefix[i] - prefix[start]
            c = s * 0.001
            if 0.129 <= c <= 0.138:
                count += 1
        print(count)

if __name__ == "__main__":
    Solution().solve()