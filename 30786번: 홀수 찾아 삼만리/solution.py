#!/usr/bin/env python3
import sys

def extract(evens, odds):
    start = evens[0]
    end = odds[0]
    perm = [start]
    perm.extend(evens[1:])
    perm.extend(o for o in odds if o != end)
    perm.append(end)
    return perm


def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    
    it = iter(data)
    n = int(next(it))

    evens = []
    odds = []

    for idx in range(1, n + 1):
        x = int(next(it))
        y = int(next(it))
        if ((x + y) & 1) == 1:
            odds.append(idx)
        else:
            evens.append(idx)

    if evens and odds:
        sys.stdout.write("YES\n")
        sys.stdout.write(" ".join(map(str, extract(evens, odds))))
    else:
        sys.stdout.write("NO")

if __name__ == "__main__":
    solve()