import sys
import heapq
from collections import defaultdict

class DualHeap:
    def __init__(self):
        self.minh = []
        self.maxh = []
        self.cnt = defaultdict(int)
        self.sz = 0
    def _clnmin(self):
        while self.minh and self.cnt[self.minh[0]] == 0:
            heapq.heappop(self.minh)
    def _clnmax(self):
        while self.maxh and self.cnt[-self.maxh[0]] == 0:
            heapq.heappop(self.maxh)
    def push(self, x):
        heapq.heappush(self.minh, x)
        heapq.heappush(self.maxh, -x)
        self.cnt[x] += 1
        self.sz += 1
    def pop_min(self):
        self._clnmin()
        x = heapq.heappop(self.minh)
        while self.cnt[x] == 0:
            self._clnmin()
            x = heapq.heappop(self.minh)
        self.cnt[x] -= 1
        self.sz -= 1
        return x
    def pop_max(self):
        self._clnmax()
        x = -heapq.heappop(self.maxh)
        while self.cnt[x] == 0:
            self._clnmax()
            x = -heapq.heappop(self.maxh)
        self.cnt[x] -= 1
        self.sz -= 1
        return x
    def get_min(self):
        self._clnmin()
        return self.minh[0]
    def get_max(self):
        self._clnmax()
        return -self.maxh[0]
    def __len__(self):
        return self.sz
    
def main():
    input = sys.stdin.readline
    N = int(input().strip())

    R = N if N % 4 in (0, 1) else N - 1
    S = N * (N + 1) // 2
    SA = (S + R) // 2

    inA = [False] * (N + 1)
    l, r = 1, N
    rem = SA
    turn = 0

    while rem > 0 and l <= r:
        x = r if turn == 0 else 1
        if rem >= x:
            inA[x] = True
            rem -= x
        if turn == 0:
            r -= 1
        else:
            l += 1
        turn ^=  1

    for x in range(N, 0, -1):
        if rem == 0:
            break
        if not inA[x] and rem >= x:
            inA[x] = True
            rem -= x
    
    A = DualHeap()
    B = DualHeap()
    for x in range(1, N + 1):
        (A if inA[x] else B).push(x)
    
    ops = []

    while len(A) > 1 or len(B) > 1:
        if len(A) > 1 and len(B) > 1:
            reduce_A = (len(A) >= len(B))
        else:
            reduce_A = (len(A) > 1)

        if reduce_A:
            a = A.pop_min()
            b = B.pop_max()
            if a > b:
                ops.append((a, b))
                A.push(a - b)
            else:
                ops.append((b, a))
                B.push(b - a)
        else:
            b = B.pop_min()
            a = A.pop_max()
            if b > a:
                ops.append((b, a))
                B.push(b - a)
            else:
                ops.append((a, b))
                A.push(a - b)

    x = A.get_min()
    y = B.get_min()
    if x >= y: ops.append((x, y))
    else: ops.append((y, x))

    print(R)
    for u, v in ops:
        print(u, v)

if __name__ == "__main__":
    main()