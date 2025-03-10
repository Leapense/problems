import sys
input = sys.stdin.readline

N, M = map(int, input().split())
dp = [[False] * 101 for _ in range(101)]
dp[1][1] = False

for s in range(3, 201):
    for a in range(1, 101):
        b = s - a
        if b < 1 or b > 100:
            continue
        win = False
        if b >= 2:
            for x in range(1, b):
                if not dp[x][b - x]:
                    win = True
                    break
        if not win and a >= 2:
            for x in range(1, a):
                if not dp[x][a - x]:
                    win = True
                    break
        dp[a][b] = win

result = "A" if dp[N][M] else "B"
sys.stdout.write(result)