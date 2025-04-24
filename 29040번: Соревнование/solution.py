import sys

def build(n, k, mod):
    return [[((i - d) % n) % mod for d in range(k)] for i in range(n)]

def ok(mat):
    n, k = len(mat), len(mat[0])
    half = k // 2
    for i in range(n):
        prev = (i - 1) % n
        nxt = (i + 1) % n
        win_prev = sum(mat[i][d] > mat[prev][d] for d in range(k))
        win_nxt = sum(mat[i][d] > mat[nxt][d] for d in range(k))
        if win_prev <= half or win_nxt > half:
            return False
    return True

def solve():
    n, k = map(int, sys.stdin.readline().split())
    for m in range(2, 12):
        mat = build(n, k, m)
        if ok(mat):
            for row in mat:
                print(*row)
            return

if __name__ == "__main__":
    solve()

