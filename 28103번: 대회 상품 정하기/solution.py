import sys

def solve():
    input = sys.stdin.readline
    N, M, X = map(int, input().split())
    a = list(map(int, input().split()))
    base = a[-1]
    S = X - N * base
    cnt = [0] * M
    for k in range(M - 1):
        d = a[k] - base
        if d <= 0 or N == 0 or S <= 0:
            break
        t = S // d
        if t > N:
            t = N
        cnt[k] = t
        S -= t * d
        N -= t
        if N == 0:
            break
        
    if N > 0:
        cnt[M - 1] = N
    
    print(' '.join(str(x) for x in cnt))

if __name__ == "__main__":
    solve()