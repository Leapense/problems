import sys

def popcount(x: int) -> int:
    try:
        return x.bit_count()
    except AttributeError:
        return bin(x).count('1')

def main():
    input = sys.stdin.readline
    N = int(input().strip())
    A = list(map(int, input().split()))

    if N == 1:
        print(0)
        return
    NEG = -10**15
    dp = [NEG] * (N + 1)
    dp[0] = 0
    if N >= 2:
        dp[2] = dp[0] + popcount(A[0] ^ A[1])
    if N >= 3:
        dp[3] = max(dp[1] + popcount(A[1] ^ A[2]) if dp[1] != NEG else NEG, dp[0] + popcount(A[0] ^ A[1] ^ A[2]))

    for i in range(4, N + 1):
        best = NEG
        two = dp[i - 2]
        if two != NEG:
            best = max(best, two + popcount(A[i - 2] ^ A[i - 1]))
        three = dp[i - 3]
        if three != NEG:
            best = max(best, three + popcount(A[i - 3] ^ A[i - 2] ^ A[i - 1]))
        dp[i] = best

    print(dp[N])

if __name__ == "__main__":
    main()