import sys

sys.setrecursionlimit(1_000_000)
inp = sys.stdin.readline

n = int(inp())
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, inp().split())
    g[a].append(b)
    g[b].append(a)

total = 0
stack = [(1, 0)]
visited = [False] * (n + 1)
visited[1] = True

while stack:
    node, d = stack.pop()
    leaf = True
    for nxt in g[node]:
        if not visited[nxt]:
            visited[nxt] = True
            stack.append((nxt, d + 1))
            leaf = False
    if leaf:
        total += d
print("Yes" if total % 2 else "No")