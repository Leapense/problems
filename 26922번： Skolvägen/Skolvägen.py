class MinRoadCross:
    def solve(self, intersections: str) -> int:
        n = len(intersections)
        INF = 10**9
        dp = [[INF, INF] for _ in range(n + 1)]
        dp[0][0] = 0

        def costN(c):
            return 1 if c in ('N', 'B') else 0
        def costS(c):
            return 1 if c in ('S', 'B') else 0
        
        for i in range(1, n + 1):
            c = intersections[i - 1]
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1) + costN(c)
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1) + costS(c)

        return dp[n][0]
    
if __name__ == "__main__":
    solver = MinRoadCross()
    intersections = input().strip()
    print(solver.solve(intersections))