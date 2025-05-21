import sys
from collections import deque
from typing import List, Deque

def read_input() -> (List[int], List[List[int]]): # type: ignore
    """Reads K, N, M, the cows' starting positions, and the directed edges."""
    data = sys.stdin.readline().split()
    if not data:
        return [], []
    k, n, m = map(int, data)
    starts = [int(sys.stdin.readline()) for _ in range(k)]
    adj: List[List[int]] = [[] for _ in range(n + 1)]
    for _ in range(m):
        u_str, v_str = sys.stdin.readline().split()
        u, v = int(u_str), int(v_str)
        adj[u].append(v)
    return starts, adj

def bfs_from(start: int, adj: List[List[int]], reach_count: List[int]) -> None:
    """Performs BFS from `start`, marking reachable nodes by incrementing their counter in `reach_count`."""
    n = len(adj) - 1
    visited = [False] * (n + 1)
    queue: Deque[int] = deque([start])
    visited[start] = True
    while queue:
        node = queue.popleft()
        reach_count[node] += 1

        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

def main() -> None:
    """Main execution: orchestrates input, multiple BFS runs, and output."""
    starts, adj = read_input()
    if not starts:
        return
    
    n = len(adj) - 1
    k = len(starts)
    reach_count = [0] * (n + 1)


    for start in starts:
        bfs_from(start, adj, reach_count)

    result = sum(1 for count in reach_count if count == k)
    print(result)

if __name__ == "__main__":
    main()