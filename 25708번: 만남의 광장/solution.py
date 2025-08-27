import sys
def solve():
    n, m = map(int, sys.stdin.readline().split())
    grid = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    row_sums = [sum(row) for row in grid]
    col_sums = [0] * m
    for j in range(m):
        for i in range(n):
            col_sums[j] += grid[i][j]

    max_beauty = -float('inf')
    for c1 in range(m):
        for c2 in range(c1 + 1, m):
            if c2 - c1 < 1:
                continue
            v = [0] * n
            for i in range(n):
                v[i] = row_sums[i] - grid[i][c1] - grid[i][c2]

            k = c2 - c1 - 1
            l_values = [v[i] - i * k for i in range(n)]
            r_values = [v[i] + i * k for i in range(n)]

            max_l_so_far = -float('inf')
            max_row_pair_value = -float('inf')
            if n > 1:
                max_l_so_far = l_values[0]
                for r2 in range(1, n):
                    current_pair_value = max_l_so_far + r_values[r2]
                    if current_pair_value > max_row_pair_value:
                        max_row_pair_value = current_pair_value
                    if l_values[r2] > max_l_so_far:
                        max_l_so_far = l_values[r2]
            if max_row_pair_value != -float('inf'):
                col_part = col_sums[c1] + col_sums[c2]
                current_total_beauty = max_row_pair_value + col_part - k
                if current_total_beauty > max_beauty:
                    max_beauty = current_total_beauty

    print(max_beauty)

solve()