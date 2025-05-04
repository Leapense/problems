#!/usr/bin/env python3

import sys
sys.setrecursionlimit(10_000)

def max_teams(n, a, b):
    hypers = []
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                if a[k] <= i + 1 <= j + 1 <= k + 1 <= b[i]:
                    mask = (1 << i) | (1 << j) | (1 << k);
                    span = k - i
                    hypers.append((mask, span))
    hypers.sort(key=lambda x: x[1])

    used = 0
    best = 0
    i = 0
    while i + 2 < n:
        mask = (1 << i) | (1 << (i + 1)) | (1 << (i + 2))
        if ((used & mask) == 0
            and a[i+2] <= i+1
            and (i+3) <= b[i]):
            used |= mask
            best += 1
            i += 3
        else:
            i += 1

    N_all = n
    full_mask = (1 << n) - 1

    from functools import lru_cache

    @lru_cache(None)
    def dfs(idx, used_mask, count):
        nonlocal best
        rem = N_all - used_mask.bit_count()
        # Upper bound: even if we pack perfectly
        if count + (rem // 3) <= best:
            return
        # Update best
        best = max(best, count)
        if idx >= len(hypers) or rem < 3:
            return
        mask, _ = hypers[idx]
        # Try include
        if (used_mask & mask) == 0:
            dfs(idx+1, used_mask | mask, count+1)
        # Exclude
        dfs(idx+1, used_mask, count)

    dfs(0, used, best)
    return best

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    a = [0] * n
    b = [0] * n
    ptr = 1
    for i in range(n):
        a[i] = int(data[ptr]); b[i] = int(data[ptr + 1])
        ptr += 2
    print(max_teams(n, a, b))

if __name__ == "__main__":
    main()