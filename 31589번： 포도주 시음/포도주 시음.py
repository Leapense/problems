import sys
import math

class SegTree:
    def __init__(self, n):
        self.size = 1
        while self.size < n:
            self.size *= 2
        self.data = [-10**18] * (2 * self.size)

    def update(self, pos, value):
        pos += self.size
        if value > self.data[pos]:
            self.data[pos] = value
            pos //= 2
            while pos:
                self.data[pos] = max(self.data[2 * pos], self.data[2 * pos + 1])
                pos //= 2

    def query(self, l, r):
        res = -10**18
        l += self.size
        r += self.size
        while l < r:
            if l & 1:
                res = max(res, self.data[l])
                l += 1
            if r & 1:
                r -= 1
                res = max(res, self.data[r])
            l //= 2
            r //= 2
        return res

def main():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    wines = list(map(int, input().split()))
    prev_dp = wines[:]
    sorted_tastes = sorted(set(wines))
    comp = {v : i for i, v in enumerate(sorted_tastes)}
    comp_size = len(sorted_tastes)

    for step in range(2, K + 1):
        tree1 = SegTree(comp_size)
        tree2 = SegTree(comp_size)

        cur_dp = [-10**18] * N
        p = 0

        for i in range(N):
            while p < i:
                pos = comp[wines[p]]
                tree1.update(pos, prev_dp[p] - wines[p])
                tree2.update(pos, prev_dp[p])
                p += 1

            pos = comp[wines[i]]
            best1 = tree1.query(0, pos)
            candidate1 = wines[i] + best1
            candidate2 = tree2.query(pos, comp_size)
            cur_dp[i] = max(candidate1, candidate2)
        prev_dp = cur_dp
    answer = max(prev_dp)
    sys.stdout.write(str(answer))

if __name__ == "__main__":
    main()