import sys

sys.setrecursionlimit(1000000)

class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.rank = [0] * (n + 1)

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)
        if xroot == yroot:
            return
        if self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
        else:
            self.parent[yroot] = xroot
            if self.rank[xroot] < self.rank[yroot]:
                self.parent[xroot] = yroot
            else:
                self.parent[yroot] = xroot
                if self.rank[xroot] == self.rank[yroot]:
                    self.rank[xroot] += 1
def main():
    case_num = 1
    while True:
        line = ''
        while line.strip() == '':
            line = sys.stdin.readline()
            if not line:
                return
        n, m = map(int, line.strip().split())
        if n == 0 and m == 0:
            break
        
        dsu = DSU(n)
        for _ in range(m):
            while True:
                pair_line = sys.stdin.readline()
                if pair_line.strip() != '':
                    break
            a, b = map(int, pair_line.strip().split())
            dsu.union(a, b)
        
        roots = set()
        for i in range(1, n + 1):
            roots.add(dsu.find(i))
        print(f"Case {case_num}: {len(roots)}")
        case_num += 1

if __name__ == "__main__":
    main()