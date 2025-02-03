class Solution:
    def solve(self):
        import sys
        data = sys.stdin.read().split()
        a, b, c = map(float, data[:3])
        v0, v1, v2 = map(float, data[3:6])
        T1 = a / v0 + c / v1 + b / v2
        T2 = b / v0 + c / v1 + a / v2
        T3 = a / v0 + a / v1 + b / v0 + b / v1
        T4 = a / v0 + c / v1 + c / v2 + a / v2
        T5 = a / v0 + c / v1 + c / v2 + b / v2
        T6 = b / v0 + c / v1 + c / v2 + a / v2
        T7 = a / v0 + c / v0 + c / v1 + a / v2
        T8 = b / v0 + c / v0 + c / v1 + b / v2
        ans = min(T1, T2, T3, T4, T5, T6, T7, T8)
        sys.stdout.write("{:.15f}".format(ans))

if __name__ == "__main__":
    Solution().solve()