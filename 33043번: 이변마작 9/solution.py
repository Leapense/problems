import sys
from collections import defaultdict, deque

def solve():
    data = sys.stdin.read().strip().split()
    n = int(data[0])
    tiles = data[1:1+n]

    last5 = defaultdict(deque)

    INF = 10 ** 18
    ans = INF

    for i, t in enumerate(tiles, start=1):
        dq = last5[t]
        dq.append(i)
        if len(dq) > 5:
            dq.popleft()
        if len(dq) == 5:
            need = dq[-1] - dq[0] + 1
            if need < ans:
                ans = need

    print(-1 if ans == INF else ans)

if __name__ == "__main__":
    solve()