import sys
from typing import List, Tuple

def ceil_div(a: int, b: int) -> int:
    return (a + b - 1) // b

def min_computers(n: int, t: List[int], s: List[int]) -> int:
    deadlines: List[Tuple[int, int]] = []
    for i in range(n):
        if s[i] != -1:
            deadlines.append((s[i], t[i]))
    deadlines.sort()
    total = 0
    required = 0
    for deadline, work in deadlines:
        total += work
        need = ceil_div(total, deadline)
        if need > required:
            required = need
    return required

def main() -> None:
    data = sys.stdin.read().strip().split()
    it = iter(data)
    n = int(next(it))
    t = [int(next(it)) for _ in range(n)]
    s = [int(next(it)) for _ in range(n)]
    print(min_computers(n, t, s))

if __name__ == "__main__":
    main()