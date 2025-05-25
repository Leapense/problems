#!/usr/bin/env python3

import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    
    target = int(data[0])
    club_count = int(data[1])
    clubs = list(map(int, data[2:2+club_count]))

    INF = target + 1
    dp = [INF] * (target + 1)
    dp[0] = 0

    for i in range(target + 1):
        if dp[i] == INF:
            continue

        for dist in clubs:
            next_pos = i + dist
            if next_pos <= target:
                if dp[next_pos] > dp[i] + 1:
                    dp[next_pos] = dp[i] + 1

    if dp[target] <= target:
        print(f"Roberta wins in {dp[target]} strokes.")
    else:
        print("Roberta acknowledges defeat.")

if __name__ == "__main__":
    solve()