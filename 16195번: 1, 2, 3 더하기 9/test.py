import time, tracemalloc, math
import matplotlib.pyplot as plt
import matplotx

MOD = 1_000_000_009

def build_prefix(max_n: int, max_m: int):
    dp = [[0] * (max_m + 1) for _ in range(max_n + 3)]
    dp[0][0] = 1
    for n in range(1, max_n + 1):
        for k in range(1, max_m + 1):
            total = dp[n-1][k-1]
            if n >= 2:
                total += dp[n-2][k-1]
            if n >= 3:
                total += dp[n-3][k-1]
            dp[n][k] = total % MOD

    pref = [[0] * (max_m + 1) for _ in range(max_n + 1)]
    for n in range(1, max_n + 1):
        running = 0
        for k in range(1, max_m + 1):
            running = (running + dp[n][k]) % MOD
            pref[n][k] = running
    return pref

def run_profile():
    ns = list(range(100, 1001, 100))
    times, mems = [], []
    for n in ns:
        tracemalloc.start()
        t0 = time.perf_counter()
        build_prefix(n, n)
        elapsed = time.perf_counter() - t0
        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()

        times.append(elapsed)
        mems.append(peak / (1024 * 1024))

        print(f"n={n:4d}  time={elapsed:.4f}s  peak={mems[-1]:.1f} MB")

    plt.style.use(matplotx.styles.onedark)
    plt.figure()
    plt.plot(ns, times, marker='o')
    plt.title("Build Time vs n (MAX_N = MAX_M = n)")
    plt.xlabel("n")
    plt.ylabel("seconds")
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    plt.figure()
    plt.plot(ns, mems, marker='s')
    plt.title("Peak Memory vs n (MAX_N = MAX_M = n)")
    plt.xlabel("n")
    plt.ylabel("MB")
    plt.yscale('log')
    plt.grid(True, which='both')
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    run_profile()