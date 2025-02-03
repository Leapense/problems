class Solution:
    def solve(self):
        import sys
        data = sys.stdin.read().split()
        if not data:
            return
        a, b, c, v0, v1, v2 = map(int, data)
        t1 = a / v0 + c / v1 + b / v2
        t2 = b / v0 + c / v1 + a / v2
        t3 = a / v0 + a / v1 + b / v0 + b / v1
        t4 = a / v0 + c / v0 + c / v1 + a / v2
        t5 = b / v0 + c / v0 + c / v1 + b / v2
        ans = min(t1, t2, t3, t4, t5)
        sys.stdout.write(f"{ans:.15f}")

if __name__ == "__main__":
    Solution().solve()
