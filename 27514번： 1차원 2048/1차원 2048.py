class Solution:
    def solve(self):
        import sys
        input = sys.stdin.readline
        N = int(input().strip())
        arr = list(map(int, input().split()))
        count = [0] * 63
        for val in arr:
            if val > 0:
                k = val.bit_length() - 1
                count[k] += 1

        for i in range(63):
            pairs = count[i] // 2
            if i < 62:
                count[i + 1] += pairs
            count[i] %= 2
        for i in range(62, -1, -1):
            if count[i] > 0:
                print(2 ** i)
                return
            
if __name__ == "__main__":
    Solution().solve()