import sys
def main():
    data = sys.stdin.read().split()
    T = int(data[0])
    idx = 1
    for _ in range(T):
        n = int(data[idx])
        idx += 1
        p = list(map(float, data[idx:idx+n]))
        idx += n
        dp = [0.0] * (n+1)
        for i in range(1,n+1):
            option1 = dp[i-1]
            option2 = p[i-1] + (dp[i-3] if i >= 3 else 0.0)
            dp[i] = max(option1, option2)
        print("{0:.1f}".format(dp[n]))
if __name__ == '__main__':
    main()