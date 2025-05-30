import sys

def solve():
    data = sys.stdin.read().split()
    S = data[0].strip()
    T = data[1].strip()
    A_cost, C_cost, G_cost, T_cost = map(int, data[2:6])
    cost_map = {'A': A_cost, 'C': C_cost, 'G': G_cost, 'T': T_cost}

    N, M = len(S), len(T)
    total_cost = sum(cost_map[c] for c in T)

    pos_in_T = {'A': [], 'C': [], 'G': [], 'T': []}
    for idx, ch in enumerate(T):
        pos_in_T[ch].append(idx)

    NEG_INF = -10**18
    dp_prev = [NEG_INF] * M
    best_match = 0

    for i in range(N):
        ch = S[i]
        positions = pos_in_T[ch]
        if not positions:
            dp_prev = [NEG_INF] * M
            continue

        prefix_max_prev = [NEG_INF] * M
        current_max = NEG_INF

        for j in range(M):
            if dp_prev[j] > current_max:
                current_max = dp_prev[j]
            prefix_max_prev[j] = current_max

        dp_end = [NEG_INF] * M
        w = cost_map[ch]
        for j in positions:
            if w > dp_end[j]:
                dp_end[j] = w
            if j > 0 and prefix_max_prev[j - 1] + w > dp_end[j]:
                dp_end[j] = prefix_max_prev[j - 1] + w
            
            if dp_end[j] > best_match:
                best_match = dp_end[j]

        dp_prev = dp_end

    answer = total_cost - best_match
    print(answer)

if __name__ == "__main__":
    solve() 