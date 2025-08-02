import sys
from collections import deque

sys.setrecursionlimit(10000)

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    n, a, b = map(int, data)
    if abs(a - b) == 1 and a != 1 and a != n and b != 1 and b != n:
        print(0)
        return
    visited = [False] * (n + 1)
    visited[a] = True
    path = [a]

    def is_connected(nxt):
        remain = n - len(path)
        dq = deque([nxt])
        seen = [False] * (n + 1)
        seen[nxt] = True
        cnt = 1
        while dq:
            v = dq.popleft()
            for w in (v - 2, v - 1, v + 1, v + 2):
                if 1 <= w <= n and not visited[w] and not seen[w]:
                    seen[w] = True
                    cnt += 1
                    dq.append(w)
        return cnt == remain

    def dfs(cur):
        if len(path) == n:
            return cur == b
        for d in (-2, -1, 1, 2):
            nxt = cur + d
            if nxt < 1 or nxt > n or visited[nxt]:
                continue
            if nxt == b and len(path) != n - 1:
                continue
            visited[nxt] = True
            if is_connected(nxt):
                path.append(nxt)
                if dfs(nxt):
                    return True
                path.pop()
            visited[nxt] = False
        return False

    dfs(a)
    for i in range(1, len(path)):
        print(path[i] - path[i - 1])

if __name__ == "__main__":
    solve()