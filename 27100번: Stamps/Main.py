import sys

def main():
    data = sys.stdin.read().split()
    S, E = map(int, data[:2])
    stamps = list(map(int, data[2:2+S]))
    maxv = E * max(stamps)
    dp = [E + 1] * (maxv + 1)
    dp[0] = 0
    for v in range(1, maxv + 1):
        mv = E + 1
        for s in stamps:
            if v >= s and dp[v - s] + 1 < mv:
                mv = dp[v - s] + 1
        dp[v] = mv
    best = cur = 0
    for v in range(1, maxv + 1):
        if dp[v] <= E:
            cur += 1
            if cur > best: best = cur
        else:
            cur = 0
    sys.stdout.write(str(best))

if __name__ == '__main__':
    main()