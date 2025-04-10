import sys
from collections import deque

input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    adj = [[] for _ in range(n)]

    for _ in range(n - 1):
        p, c = map(int, input().split())
        adj[p].append(c)
    
    values = list(map(int, input().split()))

    value_to_node_map = [0] * n
    for i in range(n):
        node_value = values[i]
        value_to_node_map[node_value] = i

    try:
        target_node = value_to_node_map[k]
    except IndexError:
        print("-1")
        return
    
    depths = [-1] * n
    queue = deque()

    if n > 0:
        depths[0] = 0
        queue.append(0)

    result_depth = -1

    while queue:
        current_node = queue.popleft()

        if current_node == target_node:
            result_depth = depths[current_node]
            break

        for child in adj[current_node]:
            if depths[child] == -1:
                depths[child] = depths[current_node] + 1
                queue.append(child)

    print(result_depth)

solve()