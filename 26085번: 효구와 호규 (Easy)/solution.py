import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    it = iter(data)
    n = int(next(it))
    m = int(next(it))
    grid = [[int(next(it)) for _ in range(m)] for _ in range(n)]

    cnt0 = 0
    cnt1 = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                cnt0 += 1
            else:
                cnt1 += 1

    has_adj_equal = False
    for i in range(n):
        for j in range(m):
            if j + 1 < m and grid[i][j] == grid[i][j + 1]:
                has_adj_equal = True
                break
            if i + 1 < n and grid[i][j] == grid[i + 1][j]:
                has_adj_equal = True
                break
        if has_adj_equal:
            break
        
    if has_adj_equal and (cnt0 % 2 == 0) and (cnt1 % 2 == 0):
        print(1)
    else:
        print(-1)

if __name__ == "__main__":
    solve()