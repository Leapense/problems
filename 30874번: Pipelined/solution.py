#!/usr/bin/env python3
import sys

def solve():
    inp = sys.stdin.readline
    N = int(inp())
    s = list(map(int, inp().split()))
    if N == 0:
        print(0)
        return
    
    s.sort()
    answer = 0
    for i, si in enumerate(s):
        finish = si + i
        if finish > answer:
            answer = finish

    print(answer)

if __name__ == "__main__":
    solve()