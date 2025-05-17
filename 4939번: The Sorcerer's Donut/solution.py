from sys import stdin

DIRS = [(-1, 0), (-1, 1), (0, 1), (1, 1),
        (1, 0),  (1, -1), (0, -1), (-1, -1)]

def gen_cycles(grid, h, w):
    cycles = []
    for r in range(h):
        for c in range(w):
            for dr, dc in DIRS:
                sr, sc = r, c
                cr, cc = r, c
                s = []
                while True:
                    s.append(grid[cr][cc])
                    cr = (cr + dr) % h
                    cc = (cc + dc) % w
                    if cr == sr and cc == sc:
                        break
                cycles.append(''.join(s))
    return cycles

def longest_spell(grid, h, w):
    cycles = gen_cycles(grid, h, w)
    max_len = h * w
    def has_repeat(L):
        seen = {}
        for idx, cyc in enumerate(cycles):
            if len(cyc) < L:
                continue
            key = cyc[:L]
            if key in seen and seen[key] != idx:
                return True
            seen[key] = idx
        return False
    lo, hi = 2, max_len
    best = 0
    while lo <= hi:
        mid = (lo + hi) // 2
        if has_repeat(mid):
            best = mid
            lo = mid + 1
        else:
            hi = mid - 1
    if best < 2:
        return "0"
    from collections import defaultdict
    occurrences = defaultdict(set)
    for idx, cyc in enumerate(cycles):
        if len(cyc) >= best:
            occurrences[cyc[:best]].add(idx)
    candidates = [s for s, ids in occurrences.items() if len(ids) >= 2]
    return min(candidates) if candidates else "0"

def solve() -> None:
    it = iter(stdin.read().splitlines())
    out_lines = []
    while True:
        h, w = map(int, next(it).split())
        if h == 0 and w == 0:
            break
        grid = [next(it).strip() for _ in range(h)]
        out_lines.append(longest_spell(grid, h, w))
    print("\n".join(out_lines))

if __name__ == "__main__":
    solve()