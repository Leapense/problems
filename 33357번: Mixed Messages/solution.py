import sys

def solve():
    input = sys.stdin.readline
    n = int(input().strip())
    s = input().strip()

    T = "spbsu"
    W = [1, 2, 2, 1]
    INF = 10 ** 18

    dp_prev = [INF] * n
    for i, ch in enumerate(s):
        if ch == T[0]:
            dp_prev[i] = 0

    for k in range(1, 5):
        dp = [INF] * n
        best = INF
        w = W[k - 1]
        prev_char = T[k - 1]
        cur_char = T[k]

        for i, ch in enumerate(s):
            if s[i] == prev_char and dp_prev[i] < INF:
                cand = dp_prev[i] - w * i
                if cand < best:
                    best = cand

            if ch == cur_char and best < INF:
                dp[i] = w * (i - 1) + best
        
        dp_prev = dp

    ans = min(dp_prev)
    print(ans)

if __name__ == "__main__":
    solve()