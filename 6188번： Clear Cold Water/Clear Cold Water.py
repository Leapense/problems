from collections import deque
import sys
input = sys.stdin.readline

N, C = map(int, input().split())
tree = {i: [] for i in range(1, N+1)}
for _ in range(C):
    E, B1, B2 = map(int, input().split())
    tree[E].append(B1)
    tree[E].append(B2)

distances = [0] * (N+1)
queue = deque([1])
distances[1] = 1

while queue:
    cur = queue.popleft()
    for nxt in tree[cur]:
        if distances[nxt] == 0:
            distances[nxt] = distances[cur] + 1
            queue.append(nxt)

for i in range(1, N+1):
    print(distances[i])