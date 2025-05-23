class CardFlip:
    def solve(self):
        import sys
        input_data = sys.stdin.read().split()
        if not input_data:
            return
        
        n = int(input_data[0])
        p = [0] * n
        if n % 2 == 0:
            l, r, idx = 1, n, 0
            while l < r:
                p[idx] = l
                p[idx + 1] = r
                l += 1
                r -= 1
                idx += 2
        else:
            m = (n + 1) // 2
            p[0] = m
            left, right, idx = m - 1, m + 1, 1
            while left >= 1 or right <= n:
                if right <= n:
                    p[idx] = right
                    idx += 1
                    right += 1
                if left >= 1:
                    p[idx] = left
                    idx += 1
                    left -= 1
        b = [0] * n
        used = [False] * (n + 1)
        for i in range(n - 1):
            diff = abs(p[i + 1] - p[i])
            b[p[i] - 1] = diff
            used[diff] = True
        for num in range(1, n + 1):
            if not used[num]:
                b[p[n - 1] - 1] = num
                break
        out = []
        out.append("YES")
        out.append(" ".join(map(str, b)))
        out.append(" ".join(map(str, p)))
        sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    CardFlip().solve()