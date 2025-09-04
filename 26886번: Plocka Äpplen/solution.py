import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    it = iter(data)
    n = int(next(it))
    k_max = int(next(it))
    north = [int(next(it)) for _ in range(n)]
    south = [int(next(it)) for _ in range(n)]
    
    INF_NEG = -10 ** 18
    dp_prev = [[INF_NEG] * (k_max + 1) for _ in range(2)]
    answer = 0

    dp_prev[1][1] = south[0]
    answer = max(answer, dp_prev[1][1])
    if k_max >= 2:
        dp_prev[0][2] = south[0] + north[0]
        answer = max(answer, dp_prev[0][2])
    if k_max >= 3:
        dp_prev[1][3] = south[0] + north[0]
        answer = max(answer, dp_prev[1][3])
    for col in range(1, n):
        dp_curr = [[INF_NEG] * (k_max + 1) for _ in range(2)]
        for row in (0, 1):
            for used in range(1, k_max + 1):
                val = dp_prev[row][used]
                if val == INF_NEG:
                    continue
                if used + 1 <= k_max:
                    gain = north[col] if row == 0 else south[col]
                    nv = val + gain
                    if nv > dp_curr[row][used + 1]:
                        dp_curr[row][used + 1] = nv
                        if nv > answer:
                            answer = nv
                    if used + 2 <= k_max:
                        gain = (north[col] + south[col])
                        end_row = 1 - row
                        nv = val + gain
                        if nv > dp_curr[end_row][used + 2]:
                            dp_curr[end_row][used + 2] = nv
                            if nv > answer:
                                answer = nv
                    if used + 3 <= k_max:
                        gain = (north[col] + south[col])
                        end_row = row
                        nv = val + gain
                        if nv > dp_curr[end_row][used + 3]:
                            dp_curr[end_row][used + 3] = nv
                            if nv > answer:
                                answer = nv
        dp_prev = dp_curr
    print(answer)

if __name__ == "__main__":
    solve()