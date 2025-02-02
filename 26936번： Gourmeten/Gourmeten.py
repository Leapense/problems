class Gourmeten:
    def __init__(self, M, N, times):
        self.M = M
        self.N = N
        self.times = times

    def solve(self):
        M = self.M
        dp = [0] * (M + 1)
        dp[0] = 1
        multiples = []
        for t in self.times:
            mult = []
            k = 1
            while k * t <= M:
                mult.append(k * t)
                k += 1
            multiples.append(mult)
        for m in range(1, M + 1):
            for mult in multiples:
                for time in mult:
                    if time > m:
                        break
                    dp[m] += dp[m - time]
        return dp[M]

if __name__ == '__main__':
    import sys
    input_data = sys.stdin.read().split()
    M = int(input_data[0])
    N = int(input_data[1])
    times = list(map(int, input_data[2:2+N]))
    solver = Gourmeten(M, N, times)
    print(solver.solve())