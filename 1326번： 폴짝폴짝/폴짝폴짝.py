#!/usr/bin/env python3
import sys
from collections import deque

def main():
    input = sys.stdin.readline
    N = int(input().strip())
    stones = list(map(int, input().split()))
    a, b = map(int, input().split())

    if a == b:
        print(0)
        return
    
    visited = [False] * (N + 1)
    visited[a] = True

    queue = deque()
    queue.append((a, 0))

    used = {}

    while queue:
        current, jumps = queue.popleft()
        current_value = stones[current - 1]
        r = current % current_value
        key = (current_value, r)

        if key not in used:
            neighbors = []
            if r == 0:
                start = current_value
            else:
                start = r
            
            for j in range(start, N + 1, current_value):
                neighbors.append(j)
            used[key] = neighbors
        else:
            neighbors = used[key]

        for j in neighbors:
            if j == current:
                continue
            if not visited[j]:
                visited[j] = True
                if j == b:
                    print(jumps + 1)
                    return
                queue.append((j, jumps + 1))

    print(-1)

if __name__ == "__main__":
    main()