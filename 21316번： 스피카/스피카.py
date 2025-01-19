import sys

g = {i: set() for i in range(1, 13)}
for _ in range(12):
    x, y = map(int, sys.stdin.readline().split())
    g[x].add(y)
    g[y].add(x)

d = {i: len(g[i]) for i in range(1, 13)}
for i in range(1, 13):
    s = sorted(d[n] for n in g[i])
    if d[i] == 3 and s == [1, 2, 3]:
        print(i)
        break