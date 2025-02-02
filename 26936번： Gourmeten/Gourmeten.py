class Gourmet:
    def __init__(self):
        import sys
        self.data = sys.stdin.read().split()
        self.M = int(self.data[0])
        self.N = int(self.data[1])
        self.times = list(map(int, self.data[2:2+self.N]))
    def solve(self):
        dp = [0] * (self.M + 1)
        dp[0] = 1
        for m in range(1, self.M + 1):
            for t in self.times:
                if m >= t:
                    dp[m] += dp[m - t]
        print(dp[self.M])
if __name__ == "__main__":
    Gourmet().solve()