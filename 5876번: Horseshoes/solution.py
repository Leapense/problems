import sys
sys.setrecursionlimit(10_000)

N = int(sys.stdin.readline())
grid = [list(sys.stdin.readline().strip()) for _ in range(N)]

if grid[0][0] == ')':
    print(0)
    sys.exit(0)

DIRS = [(1,0), (-1,0), (0,1), (0,-1)]

best = 0

def dfs(r: int, c: int, open_cnt: int, close_cnt: int, closing: bool, mask: int):
    global best
    
    if closing and open_cnt == close_cnt:
        best = max(best, open_cnt + close_cnt)

    for dr, dc in DIRS:
        nr, nc = r + dr, c + dc
        if 0 <= nr < N and 0 <= nc < N:
            bit = 1 << (nr * N + nc)
            if mask & bit:
                continue
            ch = grid[nr][nc]
            if closing:
                if ch == ')' and close_cnt < open_cnt:
                    dfs(nr, nc, open_cnt, close_cnt + 1, True, mask | bit)
            else:
                if ch == '(':
                    dfs(nr, nc, open_cnt + 1, close_cnt, False, mask | bit)
                else:
                    if open_cnt > 0:
                        dfs(nr, nc, open_cnt, close_cnt + 1, True, mask | bit)

start_mask = 1

dfs(0, 0, 1, 0, False, start_mask)
print(best)