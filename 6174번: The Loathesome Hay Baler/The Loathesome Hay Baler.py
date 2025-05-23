import sys
import math
sys.setrecursionlimit(10000)
input_data = sys.stdin.read().split()
n = int(input_data[0])
xt, yt = int(input_data[1]), int(input_data[2])
rollers = []
for i in range(n):
    x = int(input_data[3+3*i])
    y = int(input_data[4+3*i])
    r = int(input_data[5+3*i])
    rollers.append((x, y, r))
graph = [[] for _ in range(n)]
for i in range(n):
    xi, yi, ri = rollers[i]
    for j in range(i+1, n):
        xj, yj, rj = rollers[j]
        if (xi - xj) ** 2 + (yi - yj) ** 2 == (ri + rj) ** 2:
            graph[i].append(j)
            graph[j].append(i)

start = None
target = None
for i in range(n):
    if rollers[i][0] == 0 and rollers[i][1] == 0:
        start = i
    if rollers[i][0] == xt and rollers[i][1] == yt:
        target = i

visited = [False] * n
result = None

def dfs(idx, speed, total):
    global result
    if idx == target:
        result = total + abs(speed)
        return True
    visited[idx] = True
    for nxt in graph[idx]:
        if not visited[nxt]:
            _, _, rnxt = rollers[nxt]
            newspeed = -speed * rollers[idx][2] / rnxt
            if dfs(nxt, newspeed, total + abs(speed)):
                return True
    return False

dfs(start, 10000, 0)
print(int(result))