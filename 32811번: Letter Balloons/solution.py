import sys
from typing import List

def max_teams(p: int, initials: List[str]) -> int:
    masks = []
    limit = ord('A') + p

    for s in initials:
        s = s.strip()
        if any(not('A' <= ch < chr(limit)) for ch in s):
            continue
        if len(set(s)) != len(s):
            continue
        m = 0

        for ch in s:
            m |= 1 << (ord(ch) - ord('A'))
        masks.append(m)

    masks.sort(key=lambda x: bin(x).count('1'))

    n = len(masks)
    best = 0

    def dfs(idx: int, used_mask: int, count: int):
        nonlocal best

        if idx == n:
            best = max(best, count)
            return
        if count + (n - idx) <= best:
            return
        
        dfs(idx + 1, used_mask, count)
        m = masks[idx]
        if (used_mask & m) == 0:
            dfs(idx + 1, used_mask | m, count + 1)
    
    dfs(0, 0, 0)
    return best

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    
    ptr = 0
    p = int(data[ptr]); ptr += 1
    t = int(data[ptr]); ptr += 1
    initials = data[ptr:ptr+t]
    result = max_teams(p, initials)
    print(result)

if __name__ == "__main__":
    solve()