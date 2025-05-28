import sys
from collections import deque

def read_ints():
    """한 줄에서 정수 리스트를 반환"""
    return map(int, sys.stdin.readline().split())

def main():
    input = sys.stdin.readline
    n, k = map(int, input().split())
    candidates = list(read_ints())

    adj = [[] for _ in range(n + 1)]
    indegree = [0] * (n + 1)
    for _ in range(n):
        data = list(read_ints())
        u, children = data[0], data[1:]
        for v in children:
            adj[u].append(v)
            indegree[v] += 1

    queue = deque(u for u in range(1, n + 1) if indegree[u] == 0)
    topo = []
    while queue:
        u = queue.popleft()
        topo.append(u)
        for v in adj[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                queue.append(v)

    closure = [0] * (n + 1)
    for u in reversed(topo):
        mask = 0
        for v in adj[u]:
            mask |= (1 << (v - 1)) | closure[v]
        closure[u] = mask

    best_id = None
    best_count = -1

    for x in candidates:
        cnt = closure[x].bit_count()
        if cnt > best_count or (cnt == best_count and (best_id is None or x < best_id)):
            best_id, best_count = x, cnt

    print(best_id)

if __name__ == "__main__":
    main()