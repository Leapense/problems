import sys
import math

def main():
    input = sys.stdin.readline
    N = int(input().strip())
    rollers = [tuple(map(int, input().split())) for _ in range(N)]
    graph = [[] for _ in range(N)]
    for i in range(N):
        x1, y1, r1 = rollers[i]
        for j in range(i+1, N):
            x2, y2, r2 = rollers[j]
            dx = x1 - x2
            dy = y1 - y2
            if dx*dx + dy*dy == (r1 + r2)**2:
                graph[i].append(j)
                graph[j].append(i)
    start = None
    for idx, (x, y, _) in enumerate(rollers):
        if x == 0 and y == 0:
            start = idx
            break
    prev = -1
    curr = start
    while True:
        next_node = -1
        for nei in graph[curr]:
            if nei != prev:
                next_node = nei
                break
        if next_node == -1:
            break
        prev, curr = curr, next_node
    print(rollers[curr][0], rollers[curr][1])

if __name__ == "__main__":
    main()
