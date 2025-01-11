import sys
from collections import defaultdict

n, *rest = map(int, sys.stdin.read().split())
socks = rest
count = defaultdict(int)
for sock in socks:
    count[sock] += 1
for v in count.values():
    if v % 2 != 0:
        print("impossible")
        sys.exit()

aux = []
moves = 0

for sock in socks:
    if aux and aux[-1] == sock:
        aux.pop()
        moves += 1
    else:
        aux.append(sock)
        moves += 1
if not aux:
    print(moves)
else:
    print("impossible")