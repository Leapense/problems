def max_diet_days(N, M, K, P):
    max_days = 0
    total = 0
    for d in range(1, N + 1):
        total += P[d - 1]
        biscuits_to_use = min(K, d)
        top_biscuit_days = sorted(P[:d], reverse=True)[:biscuits_to_use]
        milk_required = total - sum(top_biscuit_days)

        if milk_required <= M:
            max_days = d
        else:
            break
    return max_days

if __name__ == '__main__':
    import sys
    input_data = sys.stdin.read().strip().split()
    if input_data:
        N, M, K = map(int, input_data[:3])
        P = list(map(int, input_data[3:3+N]))
        result = max_diet_days(N, M, K, P)
        print(result)