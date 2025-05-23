import sys
import heapq

def main():
    input = sys.stdin.readline
    basic_edges = [(1, 7), (1, 4), (2, 1), (3, 4), (3, 5)]
    n = 7
    graph = {i : [] for i in range(1, n + 1)}
    indegree = {i : 0 for i in range(1, n + 1)}
    for u, v in basic_edges:
        graph[u].append(v)
        indegree[v] += 1
    while True:
        a = int(input())
        b = int(input())
        if a == 0 and b == 0:
            break
        graph[a].append(b)
        indegree[b] += 1

    heap = []
    for i in range(1, n + 1):
        if indegree[i] == 0:
            heapq.heappush(heap, i)
    
    result = []
    while heap:
        cur = heapq.heappop(heap)
        result.append(cur)
        for nxt in graph[cur]:
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                heapq.heappush(heap, nxt)
    if len(result) != n:
        print("Cannot complete these tasks. Going to bed.")
    else:
        print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()