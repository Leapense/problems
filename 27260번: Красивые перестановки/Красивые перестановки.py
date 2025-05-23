class Solver:
    def solve(self):
        import sys
        data = sys.stdin.read().strip().split()
        n = int(data[0])
        k = int(data[1])
        from itertools import permutations
        arr = range(1, n + 1)
        ans = 0
        for perm in permutations(arr):
            s = 0
            for i in range(n - 1):
                s += perm[i] * perm[i + 1]
            if s % k == 0:
                ans += 1
        print(ans)

if __name__ == "__main__":
    Solver().solve()