import sys
from collections import deque

def read_ints() -> list[int]:
    return list(map(int, sys.stdin.readline().split()))

def find_sink_station() -> int:
    n = int(sys.stdin.readline())
    reversed_graph: list[list[int]] = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        a, b = read_ints()
        reversed_graph[b].append(a)
    for candidate in range(1, n + 1):
        visited = [False] * (n + 1)
        queue = deque([candidate])
        visited[candidate] = True
        while queue:
            node = queue.popleft()
            for neighbor in reversed_graph[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
        if all(visited[1:]):
            return candidate
    return -1

if __name__ == "__main__":
    print(find_sink_station())