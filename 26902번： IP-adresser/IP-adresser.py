class Solution:
    def solve(self):
        s = input().strip()
        n = len(s)
        count = 0
        for i in range(1, min(n, 4)):
            for j in range(i + 1, min(n, i + 4)):
                for k in range(j + 1, min(n, j + 4)):
                    a, b, c, d = s[:i], s[i:j], s[j:k], s[k:]
                    if self.is_valid(a) and self.is_valid(b) and self.is_valid(c) and self.is_valid(d):
                        count += 1
        print(count)

    def is_valid(self, segment):
        if not segment or (segment[0] == '0' and len(segment) > 1) or len(segment) > 3:
            return False
        return 0 <= int(segment) <= 255
    
if __name__ == "__main__":
    Solution().solve()