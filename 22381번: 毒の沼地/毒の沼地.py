import sys
from collections import deque

def readints():
    return list(map(int, sys.stdin.readline().split()))

while True:
    line = sys.stdin.readline()
    if not line:
        break

    N = int(line)
    if N == 0:
        break

    A, B, C, D = readints()
    X0, Y0 = readints()
    destinations = [tuple(readints()) for _ in range(N)]
    safe = [[False] * 101 for _ in range(101)]
    for x in range(A, C+1):
        for y in range(B, D+1):
            safe[x][y] = True
    total = 0
    current = (X0, Y0)
    for dest in destinations:
        dq = deque()
        dist = [[float('inf')] * 101 for _ in range(101)]
        cx, cy = current
        dx, dy = dest
        dist[cx][cy] = 0
        dq.append((cx, cy))
        while dq:
            x, y = dq.popleft()
            if (x, y) == (dx, dy):
                break
            for nx, ny in [(x-1,y),(x+1,y),(x,y-1),(x,y+1)]:
                if 1 <= nx <= 100 and 1 <= ny <= 100:
                    cost = 0 if safe[nx][ny] else 1
                    if dist[nx][ny] > dist[x][y] + cost:
                        dist[nx][ny] = dist[x][y] + cost
                        if cost == 0:
                            dq.appendleft((nx, ny))
                        else:
                            dq.append((nx, ny))
        total += dist[dx][dy]
        current = dest
    print(total)