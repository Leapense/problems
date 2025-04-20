import sys
input = sys.stdin.readline

def main():
    N, K, Q = map(int, input().split())
    A = list(map(int, input().split()))
    X = list(map(int, input().split()))

    dp = [0] * (N + 1)
    res = [0] * (N + 1)

    for i in range(1, N + 1):
        if A[i-1] != K:
            dp[i] = dp[i-1] + 1
        else:
            dp[i] = 0
        res[i] = res[i-1] + dp[i]

    out = []
    for x in X:
        out.append(str(res[x]))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
