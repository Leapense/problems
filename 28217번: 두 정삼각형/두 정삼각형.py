import sys
input = sys.stdin.readline

def rotate(M):
    N = len(M)
    R = [[0] * (i + 1) for i in range(N)]
    for i in range(N):
        for j in range(i + 1):
            a = j
            b = N - 1 - i
            c = i - j
            a, b, c = b, c, a
            ni = N - 1 - b
            nj = a
            R[ni][nj] = M[i][j]
    return R

def mirror(M):
    N = len(M)
    R = [[0] * (i + 1) for i in range(N)]
    for i in range(N):
        for j in range(i + 1):
            a = j
            b = N - 1 - i
            c = i - j
            a, b, c = c, b, a
            ni = N - 1 - b
            nj = a
            R[ni][nj] = M[i][j]
    return R

def variants(A):
    out = []
    cur = A
    for _ in range(3):
        out.append(cur)
        cur = rotate(cur)
    cur = mirror(A)
    for _ in range(3):
        out.append(cur)
        cur = rotate(cur)
    return out

def diff(X, Y):
    n = len(X)
    return sum(X[i][j] ^ Y[i][j] for i in range(n) for j in range(i + 1))

def main():
    N = int(input())
    A = [list(map(int, input().split())) for _ in range(N)]
    B = [list(map(int, input().split())) for _ in range(N)]
    ans = min(diff(V, B) for V in variants(A))
    print(ans)

if __name__ == "__main__":
    main()
