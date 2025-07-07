import sys

MOD = 1_000_000_009
MAX_N = 1000
MAX_M = MAX_N

def build_prefix():
    dp = [[0] * (MAX_M + 1) for _ in range(MAX_N + 3)]
    dp[0][0] = 1
    for n in range(1, MAX_N + 1):
        for k in range(1, MAX_M + 1):
            total = dp[n-1][k-1]
            if n >= 2:
                total += dp[n-2][k-1]
            if n >= 3:
                total += dp[n-3][k-1]
            dp[n][k] = total % MOD
    pref = [[0] * (MAX_M + 1) for _ in range(MAX_N + 1)]
    for n in range(1, MAX_N + 1):
        running = 0
        for k in range(1, MAX_M + 1):
            running = (running + dp[n][k]) % MOD
            pref[n][k] = running
    return pref

def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    t = int(data[0])
    pref = build_prefix()
    out = []
    idx = 1
    for _ in range(t):
        n = int(data[idx])
        m = int(data[idx + 1])
        idx += 2
        m = min(m, MAX_M)
        out.append(str(pref[n][m]))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()