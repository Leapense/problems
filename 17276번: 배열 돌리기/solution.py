import sys

def step_cw(a):
    n = len(a)
    m = n // 2
    b = [row[:] for row in a]
    for r in range(n):
        b[r][m] = a[r][r]
        b[r][n - 1 - r] = a[r][m]
        b[m][n - 1 - r] = a[r][n - 1 - r]
        b[r][r] = a[m][r]
    return b

def rotate(a, deg):
    steps = ((deg // 45) % 8 + 8) % 8
    for _ in range(steps):
        a = step_cw(a)
    return a

def main():
    rd = sys.stdin.readline
    t = int(rd())
    out = []
    for _ in range(t):
        n, d = map(int, rd().split())
        mat = [list(map(int, rd().split())) for _ in range(n)]
        res = rotate(mat, d)
        for row in res:
            out.append(' '.join(map(str, row)) + ' ')
    sys.stdout.write('\n'.join(out))

if __name__ == "__main__":
    main()