import sys
import threading

def main():
    import sys
    import math
    sys.setrecursionlimit(1 << 25)
    N, M = map(int, sys.stdin.readline().split())
    A = [0] + list(map(int, sys.stdin.readline().split()))
    S, T = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(N + 1)]
    rev_graph = [[] for _ in range(N + 1)]
    for _ in range(M):
        u, v, c = map(int, sys.stdin.readline().split())
        graph[u].append((v, c))
        rev_graph[v].append((u, c))

    INF = float('inf')

    def dijkstra(start, graph):
        import heapq
        dist = [INF] * (N + 1)
        dist[start] = 0
        heap = [(0, start)]
        while heap:
            d, u = heapq.heappop(heap)
            if d > dist[u]:
                continue
            for v, cost in graph[u]:
                if dist[v] > dist[u] + cost:
                    dist[v] = dist[u] + cost
                    heapq.heappush(heap, (dist[v], v))
        return dist

    distS = dijkstra(S, graph)
    distT = dijkstra(T, rev_graph)

    D = distS[T]

    # Check if there's a path from S to T
    if D == INF:
        print(-1)
        return

    min_sum = INF

    for u in range(1, N + 1):
        if distS[u] == INF:
            continue
        for v, cost in graph[u]:
            if distT[v] == INF:
                continue
            if distS[u] + cost + distT[v] == D:
                total_A = A[u] + A[v]
                if total_A < min_sum:
                    min_sum = total_A

    if min_sum == INF:
        print(-1)
    else:
        print(min_sum)

if __name__ == "__main__":
    main()
