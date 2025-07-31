import sys

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    small = [0] * (n + 1)
    big = [0] * (n + 1)
    index = 1
    for i in range(1, n):
        small[i] = int(data[index])
        big[i] = int(data[index + 1])
        index += 2
    k = int(data[index])
    INF = float('inf')
    dp = [[INF, INF] for _ in range(n + 1)]
    dp[1][0] = 0
    for i in range(1, n):
        for used in (0, 1):
            current = dp[i][used]
            if current == INF:
                continue
            if i + 1 <= n:
                dp[i + 1][used] = min(dp[i + 1][used], current + small[i])
            if i + 2 <= n:
                dp[i + 2][used] = min(dp[i + 2][used], current + big[i])

            if used == 0 and i + 3 <= n:
                dp[i + 3][1] = min(dp[i + 3][1], current + k)

    result = min(dp[n][0], dp[n][1])
    print(int(result))

if __name__ == "__main__":
    main()