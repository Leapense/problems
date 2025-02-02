import sys
import bisect

class BellSolution:
    def __init__(self):
        data = sys.stdin.read().strip().split()
        self.N = int(data[0])
        self.M = int(data[1])
        self.K = int(data[2])
        self.A = list(map(int, data[3:3+self.N]))
        self.B = list(map(int, data[3+self.N:3+self.N+self.M]))
    def solve(self):
        ans = []
        for b in self.B:
            i = bisect.bisect_left(self.A, b)
            c = []
            if i > 0:
                c.append(abs(b - self.A[i-1]))
            if i < self.N:
                c.append(abs(b - self.A[i]))
            d = min(c) if c else float('inf')
            ans.append(self.K - d if d < self.K else 0)
        return ans
    
def main():
    s = BellSolution()
    res = s.solve()
    print('\n'.join(map(str, res)))

if __name__ == "__main__":
    main()