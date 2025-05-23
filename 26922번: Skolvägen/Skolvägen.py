import sys

class Skolvagen:
    def solve(self):
        s = sys.stdin.readline().strip()
        INF = 10**9
        dp_north, dp_south = 0, INF
        for ch in s:
            if ch == 'N':
                cost_north, cost_south = 1, 0
            elif ch == 'S':
                cost_north, cost_south = 0, 1
            else:
                cost_north, cost_south = 1, 1
            new_dp_north = min(dp_north + cost_north, dp_south + 1 + cost_north)
            new_dp_south = min(dp_south + cost_south, dp_north + 1 + cost_south)
            dp_north, dp_south = new_dp_north, new_dp_south
        sys.stdout.write(str(min(dp_north, dp_south + 1)))

if __name__ == '__main__':
    Skolvagen().solve()