import sys
sys.setrecursionlimit(10000)
input_data = sys.stdin.read().strip().split()
it = iter(input_data)
T = int(next(it))
results = []
for tc in range(1, T+1):
    R = int(next(it))
    C = int(next(it))
    grid = [list(next(it).strip()) for _ in range(R)]
    grid = [list(map(int, row)) for row in grid]
    N = int(next(it))
    query_results = []
    def dfs(i, j):
        stack = [(i, j)]
        grid[i][j] = 0
        while stack:
            x, y = stack.pop()
            for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                nx, ny = x+dx, y+dy
                if 0 <= nx < R and 0 <= ny < C and grid[nx][ny] == 1:
                    grid[nx][ny] = 0
                    stack.append((nx, ny))
    for _ in range(N):
        op = next(it)
        if op == "Q":
            temp_grid = [row[:] for row in grid]
            regions = 0
            for i in range(R):
                for j in range(C):
                    if temp_grid[i][j] == 1:
                        regions += 1
                        dfs_i, dfs_j = i, j
                        stack = [(dfs_i, dfs_j)]
                        temp_grid[dfs_i][dfs_j] = 0
                        while stack:
                            x, y = stack.pop()
                            for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                                nx, ny = x+dx, y+dy
                                if 0 <= nx < R and 0 <= ny < C and temp_grid[nx][ny] == 1:
                                    temp_grid[nx][ny] = 0
                                    stack.append((nx, ny))
            query_results.append(str(regions))
        else:
            x = int(next(it))
            y = int(next(it))
            z = int(next(it))
            grid[x][y] = z
    results.append("Case #{}:\n{}".format(tc, "\n".join(query_results)))
sys.stdout.write("\n".join(results))
