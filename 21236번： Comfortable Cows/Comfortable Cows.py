import sys
from collections import defaultdict

input = sys.stdin.readline
N = int(input())

occupied = set()
adj_count = defaultdict(int)
is_comfortable = defaultdict(bool)

comfortable_count = 0
dirs = [(1,0),(-1,0),(0,1),(0,-1)]

def update_comfort(x, y):
    global comfortable_count
    if (x, y) not in occupied:
        return
    
    c = adj_count[(x, y)]
    p = is_comfortable[(x, y)]
    c2 = (c == 3)
    if p and not c2:
        comfortable_count -= 1
        is_comfortable[(x, y)] = False
    elif not p and c2:
        comfortable_count += 1
        is_comfortable[(x, y)] = True

for _ in range(N):
    x, y = map(int, input().split())
    occupied.add((x, y))
    for dx, dy in dirs:
        nx, ny = x + dx, y + dy

        if (nx, ny) in occupied:
            adj_count[(x, y)] += 1
            adj_count[(nx, ny)] += 1
    update_comfort(x, y)
    for dx, dy in dirs:
        update_comfort(x + dx, y + dy)
    print(comfortable_count)