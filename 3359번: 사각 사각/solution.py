import sys
from typing import List, Tuple

def max_upper_perimeter(data: List[Tuple[int, int]]) -> int:
    a0, b0 = data[0]
    dp_prev = [a0, b0]
    h_prev = [b0, a0]

    for a, b in data[1:]:
        base = [a, b]
        h_cur = [b, a]

        dp_cur = [0, 0]
        for o in (0, 1):
            best = 0
            for p in (0, 1):
                cand = dp_prev[p] + abs(h_prev[p] - h_cur[o])
                if cand > best:
                    best = cand
            dp_cur[o] = best + base[o]

        dp_prev, h_prev = dp_cur, h_cur

    return max(dp_prev)

def main() -> None:
    it = map(int, sys.stdin.read().strip().split())
    try:
        n = next(it)
    except StopIteration:
        return
    rects = [(next(it), next(it)) for _ in range(n)]
    rects = [tuple(sorted(t)) for t in rects]

    print(max_upper_perimeter(rects))

if __name__ == "__main__":
    main()