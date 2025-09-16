import sys

def solve():
    input = sys.stdin.readline
    n, m = map(int, input().split())

    color_to_id = {}
    next_id = 0
    grid = []
    for _ in range(n):
        row_vals = list(map(int, input().split()))
        row_ids = [0] * m
        for j, v in enumerate(row_vals):
            cid = color_to_id.get(v)
            if cid is None:
                cid = next_id
                color_to_id[v] = cid
                next_id += 1
            row_ids[j] = cid
        grid.append(row_ids)
    
    K = next_id

    cnt = [0] * K
    ssum = [0] * K
    ans = 0
    for i in range(n):
        r = i + 1
        row = grid[i]
        for cid in row:
            c = cnt[cid]
            s = ssum[cid]
            ans += c * r - s
            cnt[cid] = c + 1
            ssum[cid] = s + r
    cnt = [0] * K
    ssum = [0] * K

    for j in range(m):
        cidx = j + 1
        for i in range(n):
            cid = grid[i][j]
            c = cnt[cid]
            s = ssum[cid]
            ans += c * cidx - s
            cnt[cid] = c + 1
            ssum[cid] = s + cidx

    print(ans)

if __name__ == "__main__":
    solve()