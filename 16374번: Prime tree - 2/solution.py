import sys
import time
import random
import math
from collections import deque

def solve():
    data = list(map(int, sys.stdin.read().split()))
    t = data[0]
    idx = 1
    out = []
    for _ in range(t):
        n = data[idx]
        idx += 1
        adj = [[] for _ in range(n)]
        for _ in range(n - 1):
            u = data[idx] - 1
            v = data[idx + 1] - 1
            idx += 2
            adj[u].append(v)
            adj[v].append(u)
        part = [0] * n
        dq = deque([0])
        part[0] = 1
        while dq:
            u = dq.popleft()
            for w in adj[u]:
                if part[w] == 0:
                    part[w] = 3 - part[u]
                    dq.append(w)
        group1 = [i for i, p in enumerate(part) if p == 1]
        group2 = [i for i, p in enumerate(part) if p == 2]
        evens = list(range(2, n + 1, 2))
        odds = list(range(1, n + 1, 2))
        if len(group1) >= len(evens):
            even_side = group1
            odd_side = group2
        else:
            even_side = group2
            odd_side = group1
        label = [0] * n
        ie = 0
        io = 0
        for v in even_side:
            if ie < len(evens):
                label[v] = evens[ie]
                ie += 1
            else:
                label[v] = odds[io]
                io += 1
        for v in odd_side:
            label[v] = odds[io]
            io += 1
        start = time.time()
        if n <= 20000:
            trials = n * 5
            for _ in range(trials):
                if time.time() - start > 0.9:
                    break
                u = random.randrange(n)
                v = random.randrange(n)
                if u == v:
                    continue
                lu = label[u]
                lv = label[v]
                delta = 0
                for w in adj[u]:
                    if w == v:
                        continue
                    before = math.gcd(lu, label[w]) > 1
                    after = math.gcd(lv, label[w]) > 1
                    if after and not before:
                        delta += 1
                    elif before and not after:
                        delta -= 1
                for w in adj[v]:
                    if w == u:
                        continue
                    before = math.gcd(lv, label[w]) > 1
                    after = math.gcd(lu, label[w]) > 1
                    if after and not before:
                        delta += 1
                    elif before and not after:
                        delta -= 1
                if delta < 0:
                    label[u], label[v] = lv, lu
        out.append(" ".join(map(str, label)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()
