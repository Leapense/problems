import sys
input = sys.stdin.readline

def main():
    N = int(input())
    X = list(map(int, input().split()))
    T = list(map(int, input().split()))

    dp_prev = [[0,0] for _ in range(N)]
    for i in range(N):
        t0 = max(X[i], T[i])
        dp_prev[i][0] = dp_prev[i][1] = t0

    for k in range(2, N + 1):
        dp_cur = [[10 ** 30, 10 ** 30] for _ in range(N - k + 1)]
        for l in range(N - k + 1):
            r = l + k - 1
            d1 = dp_prev[l+1][0] + (X[l+1] - X[l])
            d2 = dp_prev[l+1][1] + (X[r] - X[l])
            best0 = min(d1, d2)
            best0 = max(best0, T[l])
            dp_cur[l][0] = best0

            d3 = dp_prev[l][0] + (X[r] - X[l])
            d4 = dp_prev[l][1] + (X[r] - X[r-1])
            best1 = min(d3, d4)
            best1 = max(best1, T[r])
            dp_cur[l][1] = best1

        dp_prev = dp_cur

    ans = min(dp_prev[0][0] + X[0], dp_prev[0][1] + X[-1])
    print(ans)

if __name__ == "__main__":
    main()