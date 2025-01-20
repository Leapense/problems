import sys
from collections import deque

input = sys.stdin.readline
m, n = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(m)]
mx = (m * n) // 2

pos = [[] for _ in range(mx + 1)]
for r in range(m):
    for c in range(n):
        pos[board[r][c]].append((r, c))

removed_tile = [[False] * n for _ in range(m)]
removed_color = [False] * (mx + 1)
left_count = [[0] * n for _ in range(m)]
right_count = [[0] * n for _ in range(m)]
up_count = [[0] * n for _ in range(m)]
down_count = [[0] * n for _ in range(m)]
boundary_tile = [[False] * n for _ in range(m)]
boundary_color = [False] * (mx + 1)
in_queue = [False] * (mx + 1)
q = deque()

for r in range(m):
    c_acc = 0
    for c in range(n):
        left_count[r][c] = c_acc
        c_acc += 1
    c_acc = 0
    for c in range(n-1, -1, -1):
        right_count[r][c] = c_acc
        c_acc += 1

for c in range(n):
    r_acc = 0
    for r in range(m):
        up_count[r][c] = r_acc
        r_acc += 1
    r_acc = 0
    for r in range(m-1, -1, -1):
        down_count[r][c] = r_acc
        r_acc += 1

def update_boundary_tile(rr, cc):
    if removed_tile[rr][cc]:
        return
    b = (left_count[rr][cc] == 0 or right_count[rr][cc] == 0 or up_count[rr][cc] == 0 or down_count[rr][cc] == 0)
    if b != boundary_tile[rr][cc]:
        boundary_tile[rr][cc] = b
        if b:
            col = board[rr][cc]
            if not removed_color[col]:
                p1, p2 = pos[col]
                r1, c1 = p1
                r2, c2 = p2

                if boundary_tile[r1][c1] and boundary_tile[r2][c2]:
                    if not boundary_color[col]:
                        boundary_color[col] = True
                        if not in_queue[col]:
                            in_queue[col] = True
                            q.append(col)

for r in range(m):
    for c in range(n):
        update_boundary_tile(r, c)

ans = []

def remove_color(c):
    removed_color[c] = True
    p1, p2 = pos[c]
    for (rr, cc) in (p1, p2):
        if not removed_tile[rr][cc]:
            remove_tile(rr, cc)

def remove_tile(rr, cc):
    removed_tile[rr][cc] = True
    col = board[rr][cc]
    cr = cc - 1
    while cr >= 0 and not removed_tile[rr][cr]:
        right_count[rr][cr] -= 1
        update_boundary_tile(rr, cr)
        cr -= 1
    cr = cc + 1
    while cr < n and not removed_tile[rr][cr]:
        left_count[rr][cr] -= 1
        update_boundary_tile(rr, cr)
        cr += 1
    rr2 = rr - 1
    while rr2 >= 0 and not removed_tile[rr2][cc]:
        down_count[rr2][cc] -= 1
        update_boundary_tile(rr2, cc)
        rr2 -= 1
    rr2 = rr + 1
    while rr2 < m and not removed_tile[rr2][cc]:
        up_count[rr2][cc] -= 1
        update_boundary_tile(rr2, cc)
        rr2 += 1

while q:
    c = q.popleft()
    in_queue[c] = False
    if removed_color[c]:
        continue
    remove_color(c)
    ans.append(c)

print(len(ans))
if ans:
    print(*ans)