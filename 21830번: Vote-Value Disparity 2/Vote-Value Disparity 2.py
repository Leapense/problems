import sys
from collections import deque

input = sys.stdin.readline
H, W, N, K = map(int, input().split())
S = [list(map(int, input().split())) for _ in range(H)]
P = [int(input()) for _ in range(N)]
adj = [[] for _ in range(N)]

for i in range(H):
    for j in range(W):
        if j + 1 < W and S[i][j] != S[i][j + 1]:
            a, b = S[i][j] - 1, S[i][j + 1] - 1
            adj[a].append(b)
            adj[b].append(a)
        if i + 1 < H and S[i][j] != S[i + 1][j]:
            a, b = S[i][j] - 1, S[i + 1][j] - 1
            adj[a].append(b)
            adj[b].append(a)

d = [0] * N
total = sum(P)
target = total / K
used = 0
district = 1

def bfs(start):
    q = deque([start])
    d[start] = district
    s = P[start]
    while q:
        u = q.popleft()
        for nx in adj[u]:
            if d[nx] == 0:
                if s + P[nx] <= target or (district == K):
                    d[nx] = district
                    s += P[nx]
                    q.append(nx)
for i in range(N):
    if d[i] == 0:
        bfs(i)
        used += 1
        if used < K:
            district += 1

for i in range(N):
    print(d[i])