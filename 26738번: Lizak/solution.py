import sys
from typing import List, Dict

def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    n = data[0]
    a = data[1:1+n]
    last_two: Dict[int, List[int]] = {}
    INF = 10 ** 18
    ans = INF
    for i, v in enumerate(a):
        lst = last_two.get(v)
        if lst is None:
            last_two[v] = [i]
        else:
            lst.append(i)
            if len(lst) >= 3:
                cand = lst[-1] - lst[-3] + 1
                if cand < ans:
                    ans = cand
            if len(lst) > 2:
                last_two[v] = lst[-2:]
    if ans == INF:
        print("NIE")
    else:
        print(ans)

if __name__ == "__main__":
    solve()