class MobisProject:
    def __init__(self):
        import sys
        self.input = sys.stdin.readline
    
    def solve(self):
        N, K = map(int, self.input().split())
        ab, ac, bc = [], [], []
        for _ in range(N):
            a, b, c = map(int, self.input().split())
            ab.append(a + b)
            ac.append(a + c)
            bc.append(b + c)
        ab.sort(reverse=True)
        ac.sort(reverse=True)
        bc.sort(reverse=True)
        res_ab = sum(ab[:K])
        res_ac = sum(ac[:K])
        res_bc = sum(bc[:K])
        print(max(res_ab, res_ac, res_bc))

if __name__ == "__main__":
    MobisProject().solve()