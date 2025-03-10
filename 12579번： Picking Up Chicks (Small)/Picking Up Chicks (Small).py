def solve_case():
    import sys
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    T_cases = int(next(it))
    results = []
    for case in range(1, T_cases + 1):
        N = int(next(it))
        K = int(next(it))
        B = int(next(it))
        T = int(next(it))
        positions = [int(next(it)) for _ in range(N)]
        speeds = [int(next(it)) for _ in range(N)]
        can_reach = [False] * N
        for i in range(N):
            if positions[i] + speeds[i] * T >= B:
                can_reach[i] = True
        swaps = 0
        good = 0
        bad = 0
        for i in range(N - 1, -1, -1):
            if good >= K:
                break
            if can_reach[i]:
                good += 1
                swaps += bad
            else:
                bad += 1
        if good < K:
            results.append(f"Case #{case}: IMPOSSIBLE")
        else:
            results.append(f"Case #{case}: {swaps}")
    sys.stdout.write("\n".join(results))
    
if __name__ == "__main__":
    solve_case()
