import sys
from typing import List

class FenwickTree:
    def __init__(self, size: int) -> None:
        self.size = size
        self.data = [0] * (size + 1)
    
    def add(self, index: int, delta: int) -> None:
        i = index
        n = self.size
        while i <= n:
            self.data[i] += delta
            i += i & -i
    
    def kth(self, k: int) -> int:
        idx = 0
        bit = 1 << (self.size.bit_length())
        while bit > 0:
            nxt = idx + bit
            if nxt <= self.size and self.data[nxt] < k:
                k -= self.data[nxt]
                idx = nxt
            bit >>= 1
        return idx + 1
    
def all_pivots_worst(n: int, arr: List[int]) -> bool:
    tree = FenwickTree(n)
    for i in range(1, n + 1):
        tree.add(i, 1)
    removed = [False] * (n + 2)
    lo = 1
    hi = n
    length = n
    while length >= 2:
        k = (length + 1) // 2
        pos = tree.kth(k)
        val = arr[pos]
        if val != lo and val != hi:
            return False
        tree.add(pos, -1)
        removed[val] = True
        while lo <= n and removed[lo]:
            lo += 1
        while hi >= 1 and removed[hi]:
            hi -= 1
        length -= 1
    return True
    
def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    t = data[0]
    idx = 1
    out = []
    for case_idx in range(1, t + 1):
        n = data[idx]
        idx += 1
        nums = [0] + data[idx:idx + n]
        idx += n
        ans = "YES" if all_pivots_worst(n, nums) else "NO"
        out.append(f"Case #{case_idx}: {ans}")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()