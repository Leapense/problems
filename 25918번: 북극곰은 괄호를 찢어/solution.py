import sys
from collections import deque

data = sys.stdin.read().strip().split()
if not data:
    print(-1)
    sys.exit(0)
n = int(data[0])
s = data[1].strip()
if len(s) != n:
    print(-1)
    sys.exit(0)
if s.count('(') != s.count(')'):
    print(-1)
    sys.exit(0)

prev = [i - 1 for i in range(n)]
nxt = [i + 1 for i in range(n)]
nxt[-1] = -1
removed = [False] * n
q = deque()
for i in range(n - 1):
    if s[i] != s[i + 1]:
        q.append(i)

days = 0
while q:
    days += 1
    newq = deque()
    while q:
        i = q.popleft()
        if removed[i]:
            continue
        j = nxt[i]
        if j == -1 or removed[j] or prev[j] != i or s[i] == s[j]:
            continue
        removed[i] = True
        removed[j] = True
        l = prev[i]
        r = nxt[j]
        if l != -1:
            nxt[l] = r
        if r != -1:
            prev[r] = l
        if l != -1 and r != -1 and s[l] != s[r]:
            newq.append(l)
    q = newq

if all(removed):
    print(days)
else:
    print(-1)