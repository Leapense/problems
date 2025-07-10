from random import betavariate
import time
import matplotlib.pyplot as plt
import matplotx

def compute_dp_time_space(N, a, b):
    dp = [0] * (N + 1)
    for i in range(1, N + 1):
        best = dp[i - 1] + 1
        if i >= a + 1:
            best = min(best, dp[i - 1 - a] + 1)
        if i >= b + 1:
            best = min(best, dp[i - 1 - b] + 1)
        dp[i] = best
    return dp

max_N = 1000
step = 50

Ns = list(range(step, max_N + 1, step))
times = []
spaces = []

a, b = 3, 5

for N in Ns:
    start = time.time()
    dp = compute_dp_time_space(N, a, b)
    end = time.time()

    elapsed_time = end - start
    memory_space = len(dp)

    times.append(elapsed_time)
    spaces.append(memory_space)

plt.style.use(matplotx.styles.onedark)
plt.subplot(1, 2, 1)
plt.plot(Ns, times, marker='o')
plt.title("Time Complexity vs N")
plt.xlabel("N")
plt.ylabel("Elapsed Time (seconds)")

plt.subplot(1, 2, 2)
plt.plot(Ns, spaces, marker='s')
plt.title("Space Complexity vs N")
plt.xlabel("N")
plt.ylabel("Space (dp array size)")

plt.tight_layout()
plt.show()