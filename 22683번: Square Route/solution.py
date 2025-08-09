import sys
from collections import defaultdict
from typing import Dict, List

def contiguous_sum_counts(a: List[int]) -> Dict[int, int]:
    n = len(a)
    counts: Dict[int, int] = defaultdict(int)
    for i in range(n):
        s = 0
        for j in range(i, n):
            s += a[j]
            counts[s] += 1
    return counts

def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    out_lines: List[str] = []
    while True:
        try:
            n = next(it)
            m = next(it)
        except StopIteration:
            break
        
        if n == 0 and m == 0:
            break
        h = [next(it) for _ in range(n)]
        w = [next(it) for _ in range(m)]
        hc = contiguous_sum_counts(h)
        wc = contiguous_sum_counts(w)
        ans = 0
        if len(hc) < len(wc):
            for k, v in hc.items():
                ans += v * wc.get(k, 0)
        else:
            for k, v in wc.items():
                ans += v * hc.get(k, 0)
        out_lines.append(str(ans))
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()