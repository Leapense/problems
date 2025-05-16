import sys
import math
import heapq

def solve():
    input_lines = sys.stdin.read().splitlines()
    idx = 0
    results = []
    while idx < len(input_lines):
        if not input_lines[idx].strip():
            idx += 1
            continue
        N = int(input_lines[idx])
        idx += 1
        planets = []
        letter_to_idx = {}
        for i in range(N):
            line = input_lines[idx].strip()
            idx += 1
            parts = line.split()
            letter = parts[0]
            value = float(parts[1])
            connections = parts[2]
            planets.append((letter, value, connections))
            letter_to_idx[letter] = i

        adj = [[] for _ in range(N)]
        earth_nodes = []

        for i, (letter, value, connections) in enumerate(planets):
            for c in connections:
                if c == '*':
                    earth_nodes.append(i)
                else:
                    if c in letter_to_idx:
                        j = letter_to_idx[c]
                        adj[i].append(j)
        for i, (letter, value, connections) in enumerate(planets):
            for c in connections:
                if c != '*' and c in letter_to_idx:
                    j = letter_to_idx[c]
                    if i not in adj[j]:
                        adj[j].append(i)

        INF = float('inf')
        min_hops = [INF] * N
        heap = []

        for src in earth_nodes:
            min_hops[src] = 0
            heapq.heappush(heap, (0, src))

        while heap:
            hops, u = heapq.heappop(heap)
            if hops > min_hops[u]:
                continue
            for v in adj[u]:
                if min_hops[v] > hops + 1:
                    min_hops[v] = hops + 1
                    heapq.heappush(heap, (hops + 1, v))

        max_effective_value = -1
        best_letter = ''
        for i, (letter, value, _) in enumerate(planets):
            if min_hops[i] == INF:
                continue

            effective = value * (0.95 ** min_hops[i])
            if effective > max_effective_value or (math.isclose(effective, max_effective_value) and letter < best_letter):
                max_effective_value = effective
                best_letter = letter
        results.append(f"Import from {best_letter}")

    for res in results:
        print(res)

if __name__ == "__main__":
    solve()