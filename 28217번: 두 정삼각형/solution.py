import sys
input = sys.stdin.readline

def transforms(A):
    N = len(A)
    out = []

    def rot(A):
        N = len(A)
        B = [[0] * (i + 1) for i in range(N)]
        for i in range(N):
            for j in range(i + 1):
                x, y = N - 1 - j, i
                B[x][y] = A[i][j]
        return B
    
    def flip(A):
        N = len(A)
        B = [row[::-1] for row in A]
        return B
    
    cur = A
    for _ in range(3):
        out.append(cur)
        cur = rot(cur)
    f = flip(A)
    cur = f
    for _ in range(3):
        out.append(cur)
        cur = rot(cur)
    return out

def diff(A, B):
    N = len(A)
    cnt = 0
    for i in range(N):
        for j in range(i + 1):
            if A[i][j] != B[i][j]:
                cnt += 1
    return cnt

def main():
    N = int(input())
    A = [list(map(int, input().split())) for _ in range(N)]
    B = [list(map(int, input().split())) for _ in range(N)]
    ans = N * (N + 1) // 2
    for T in transforms(A):
        ans = min(ans, diff(T, B))
    print(ans)

if __name__ == "__main__":
    main()