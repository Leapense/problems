import sys

class Solution:
    def __init__(self):
        self.input = sys.stdin.read().splitlines()
        self.idx = 0

    def solve(self):
        T = int(self.input[self.idx]);self.idx += 1
        for tc in range(1, T + 1):
            N = int(self.input[self.idx]);self.idx += 1
            grid = [self.input[self.idx+i] for i in range(2 * N)];self.idx += 2 * N
            sum_top = sum(row.count('I') for row in grid[:N])
            sum_bottom = sum(row.count('I') for row in grid[N:])
            sum_left = sum(row[:N].count('I') for row in grid)
            sum_right = sum(row[N:].count('I') for row in grid)
            D_row = sum_top - sum_bottom
            D_col = sum_left - sum_right
            a = (-D_row - D_col) // 2
            b = (-D_row + D_col) // 2
            flips = abs(a) + abs(b)
            print(f"Case #{tc}: {flips}")
Solution().solve()