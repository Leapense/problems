class Skolvagen:
    def __init__(self):
        import sys
        self.data = sys.stdin.read().strip()

    def solve(self):
        s = self.data.strip()
        n = len(s)
        INF = float('inf')
        dp_north = 0
        dp_south = INF
        for ch in s:
            if ch == 'N':
                cost_n = 1
                cost_s = 0
            elif ch == 'S':
                cost_n = 0
                cost_s = 1
            else:
                cost_n = 1
                cost_s = 1
            new_dp_north = min(dp_north + cost_n, dp_south + 1 + cost_n)
            new_dp_south = min(dp_south + cost_s, dp_north + 1 + cost_s)
            dp_north, dp_south = new_dp_north, new_dp_south
        print(dp_north)

if __name__ == '__main__':
    Skolvagen().solve()