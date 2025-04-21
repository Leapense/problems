import sys
def solve():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    total = 0
    for _ in range(N):
        row = list(map(int, input().split()))
        j = 0
        while j < M:
            if row[j] == 0:
                j += 1
                continue
            k = j
            while k + 1 < M and row[k + 1] != 0:
                k += 1
            B = row[j:k+1]
            L = len(B)
            dp = [[0]*L for _ in range(L)]
            for i in range(L):
                dp[i][i] = 1
            for length in range(2, L+1):
                for i in range(0, L-length+1):
                    r = i + length - 1
                    # worst: paint B[r] separately
                    v = dp[i][r-1] + 1
                    # try merge with same-color earlier stroke
                    for m in range(i, r):
                        if B[m] == B[r]:
                            cost = dp[i][m] + (dp[m+1][r-1] if m+1 <= r-1 else 0)
                            if cost < v:
                                v = cost
                    dp[i][r] = v
            total += dp[0][L-1]
            j = k + 1
    print(total)

if __name__ == "__main__":
    solve()