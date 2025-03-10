def solve_case():
    import sys
    data = sys.stdin.read().split()
    if not data:
        return
    
    it = iter(data)
    T = int(next(it))
    results = []

    for case in range(1, T + 1):
        M = int(next(it))
        N = int(next(it))
        grid = []

        for _ in range(M):
            hex_str = next(it).strip()
            bin_str = bin(int(hex_str, 16))[2:].zfill(N)
            grid.append([int(ch) for ch in bin_str])

        orig_dp = [[0] * N for _ in range(M)]
        for r in range(M - 1, -1, -1):
            for c in range(N - 1, -1, -1):
                if r == M - 1 or c == N - 1:
                    orig_dp[r][c] = 1
                else:
                    a = grid[r][c]
                    if grid[r][c+1] != a and grid[r+1][c] != a and grid[r+1][c+1] == a:
                        orig_dp[r][c] = 1 + min(orig_dp[r][c+1], orig_dp[r+1][c], orig_dp[r+1][c+1])
                    else:
                        orig_dp[r][c] = 1
        avail = [[1] * N for _ in range(M)]
        counts = {}
        while True:
            dp_avail = [[0] * N for _ in range(M)]
            for r in range(M-1, -1, -1):
                for c in range(N-1, -1, -1):
                    if avail[r][c] == 0:
                        dp_avail[r][c] = 0
                    else:
                        if r == M - 1 or c == N - 1:
                            dp_avail[r][c] = 1
                        else:
                            dp_avail[r][c] = 1 + min(dp_avail[r][c+1], dp_avail[r+1][c], dp_avail[r+1][c+1])
            best_size = 0
            best_r = best_c = -1
            for r in range(M):
                for c in range(N):
                    if avail[r][c]:
                        cand = dp_avail[r][c]
                        if cand > orig_dp[r][c]:
                            cand = orig_dp[r][c]
                        if cand > best_size:
                            best_size = cand
                            best_r = r
                            best_c = c
            if best_size == 0:
                break
            counts[best_size] = counts.get(best_size, 0) + 1
            for r in range(best_r, best_r + best_size):
                for c in range(best_c, best_c + best_size):
                    avail[r][c] = 0

        sorted_sizes = sorted(counts.keys(), reverse=True)
        out_lines = [f"Case #{case}: {len(sorted_sizes)}"]
        for s in sorted_sizes:
            out_lines.append(f"{s} {counts[s]}")
        results.append("\n".join(out_lines))
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve_case()