import sys
from collections import deque

def solve():
    inp = sys.stdin.readline
    N, M, K = map(int, inp().split())
    close = [False] * (N + 1)
    for _ in range(M):
        close[int(inp())] = True
    
    adj = [[] for _ in range(N + 1)]
    for _ in range(K):
        u, v = map(int, inp().split())
        adj[u].append(v)
        adj[v].append(u)

    visited = [False] * (N + 1)
    total = 0

    for i in range(1, N + 1):
        if close[i] and not visited[i]:
            q = deque([i])
            visited[i] = True
            cnt = 0
            while q:
                u = q.popleft()
                cnt += 1
                for w in adj[u]:
                    if not visited[w]:
                        visited[w] = True
                        q.append(w)
            total += cnt
    print(total)

if __name__ == "__main__":
    solve()