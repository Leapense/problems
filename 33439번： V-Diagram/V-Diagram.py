import sys,math
from sys import stdin
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

class Line:
    __slots__ = ('m', 'b')
    def __init__(self, m, b):
        self.m = m
        self.b = b
    def eval(self, x):
        return self.m * x + self.b
    
class LiChaoTree:
    __slots__ = ('l', 'r', 'line', 'left', 'right')
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.line = None
        self.left = None
        self.right = None

    def add_line(self, newline):
        l, r = self.l, self.r
        mid = (l + r) * 0.5
        if self.line is None:
            self.line = newline
            return
        if newline.eval(mid) > self.line.eval(mid):
            self.line, newline = newline, self.line

        if r - l < 1e-12:
            return
        if newline.eval(l) > self.line.eval(l):
            if self.left is None:
                self.left = LiChaoTree(l, mid)
            self.left.add_line(newline)
        elif newline.eval(r) > self.line.eval(r):
            if self.right is None:
                self.right = LiChaoTree(mid, r)
            self.right.add_line(newline)

    def query(self, x):
        ret = self.line.eval(x) if self.line is not None else -1e18
        mid = (self.l + self.r) * 0.5
        if x < mid and self.left is not None:
            ret = max(ret, self.left.query(x))
        elif x >= mid and self.right is not None:
            ret = max(ret, self.right.query(x))
        return ret

def main():
    t = int(input())
    out_lines = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        m_index = 0
        for i in range(n):
            if a[i] < a[m_index]:
                m_index = i
        leftCount = m_index + 1
        Lprefix = [0.0] * (leftCount + 1)
        Lprefix[1] = a[m_index]
        for j in range(2, leftCount + 1):
            Lprefix[j] = Lprefix[j-1] + a[m_index - j + 1]
        
        rightCount = n - m_index - 1
        Rprefix = [0.0] * (rightCount + 1)
        for j in range(1, rightCount + 1):
            Rprefix[j] = Rprefix[j-1] + a[m_index + j]

        Xmax = float(max(a))

        leftTree = LiChaoTree(0.0, Xmax)
        for j in range(2, leftCount + 1):
            leftTree.add_line(Line(-j, Lprefix[j]))

        rightTree = LiChaoTree(0.0, Xmax)
        for j in range(1, rightCount + 1):
            rightTree.add_line(Line(-j, Rprefix[j]))

        def F(M):
            return leftTree.query(M) + rightTree.query(M)
        
        low, high = 0.0, Xmax
        eps = 1e-11
        for _ in range(80):
            mid = (low + high) / 2.0
            if F(mid) >= 0:
                low = mid
            else:
                high = mid

        out_lines.append(f"{low:.20f}")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()