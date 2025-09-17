import sys

def solve():
    input = sys.stdin.readline
    N = int(input().strip())
    A = list(map(int, input().split()))
    k = N // 2

    if N == 1:
        print(0)
        return
    
    BASE = 1_000_000
    D = 6000

    ops = []
    for t in range(1, k + 1):
        i = t - 1
        j = N - t
        x = BASE - t * D
        if x <= 0 or x > 1_000_000:
            raise RuntimeError("YIKES")
        
        A[i] += x
        A[j] -= x
        ops.append(A[:])

    print(len(ops))
    for arr in ops:
        print(*arr)

if __name__ == "__main__":
    solve()