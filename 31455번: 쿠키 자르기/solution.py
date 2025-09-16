import sys

def build_psum(a):
    n = len(a)
    ps = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n):
        row_sum = 0
        for j in range(n):
            row_sum += a[i][j]
            ps[i + 1][j + 1] = ps[i][j + 1] + row_sum
    return ps

def rect_sum(ps, r, c, sz):
    r2, c2 = r + sz, c + sz
    return ps[r2][c2] - ps[r][c2] - ps[r2][c] + ps[r][c]

def solve_case(a):
    n = len(a)
    ps = build_psum(a)

    sys.setrecursionlimit(10000)

    def dfs(r, c, sz):
        if sz == 1:
            return a[r][c]
        h = sz // 2
        s0 = rect_sum(ps, r, c, h)
        s1 = rect_sum(ps, r, c + h, h)
        s2 = rect_sum(ps, r + h, c, h)
        s3 = rect_sum(ps, r + h, c + h, h)
        eat = (s0 + s1 + s2 + s3) % 4

        total = 0
        if eat != 0: total += dfs(r, c, h)
        if eat != 1: total += dfs(r, c + h, h)
        if eat != 2: total += dfs(r + h, c, h)
        if eat != 3: total += dfs(r + h, c + h, h)
        return total
    
    return dfs(0, 0, n)

def main():
    data = sys.stdin.read().strip().split()
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        N = int(next(it))
        a = []
        for _ in range(N):
            s = list(next(it).strip())
            a.append([ord(ch) - 48 for ch in s])

        out_lines.append(str(solve_case(a)))

    print("\n".join(out_lines))

if __name__ == "__main__":
    main()