#!/usr/bin/env python3
import sys
from collections import deque

def main():
    input = sys.stdin.readline
    R = int(input())
    C = int(input())
    grid = [input().rstrip() for _ in range(R)]
    sr = int(input())
    sc = int(input())

    dq = deque()
    dq.append((sr, sc))
    visited = [[False] * C for _ in range(R)]
    visited[sr][sc] = True

    value_map = {'S':1, 'M':5, 'L':10}
    total = 0

    ch0 = grid[sr][sc]
    if ch0 in value_map:
        total += value_map[ch0]
    
    for dr,dc in ((1,0),(-1,0),(0,1),(0,-1)):
        pass

    while dq:
        r, c = dq.popleft()
        for dr, dc in ((1,0),(-1,0),(0,1),(0,-1)):
            nr, nc = r + dr, c + dc
            if 0 <= nr < R and 0 <= nc < C and not visited[nr][nc]:
                ch = grid[nr][nc]
                if ch == '*':
                    continue
                visited[nr][nc] = True
                if ch in value_map:
                    total += value_map[ch]
                dq.append((nr,nc))

    print(total)

if __name__ == "__main__":
    main()