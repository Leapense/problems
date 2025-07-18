import time
import math
import random
import matplotlib.pyplot as plt
import matplotx

def min_fast_forward(t: int) -> int:
    if t == 0:
        return 0
    pow3 = [1]
    while pow3[-1] < t:
        pow3.append(pow3[-1] * 3)
    m_max = len(pow3) - 1
    best = float('inf')
    for m in range(m_max + 1):
        base_dist = 1 + sum(2 * pow3[k] for k in range(1, m)) + (pow3[m] if m >= 1 else 0)
        if base_dist > t:
            continue
        diff, extra = t - base_dist, 0
        for k in range(m, -1, -1):
            add = diff // pow3[k]
            extra += add
            diff -= add * pow3[k]
        if diff == 0:
            base_sec = 1 if m == 0 else 2 * m
            best = min(best, base_sec + extra)
    return int(best)

t_vals, runtime_ns, theoretical = [], [], []
for k in range(1, 40):
    t = 3 ** k - 1
    times = []
    for _ in range(3):
        start = time.perf_counter_ns()
        min_fast_forward(t)
        times.append(time.perf_counter_ns() - start)
    t_vals.append(t)
    runtime_ns.append(sum(times) / 3)
    theoretical.append((k + 1) ** 2)

plt.style.use(matplotx.styles.onedark)
fig, ax1 = plt.subplots()

ax1.set_xscale("log")
ax1.set_yscale("log")
ax1.plot(t_vals, runtime_ns, marker="o", label="Measured runtime (ns)")
ax1.plot(t_vals, theoretical, linestyle="--", label="(log\u2083 t)\u00B2 (scaled)")
ax1.set_xlabel("target value t")
ax1.set_ylabel("nanoseconds / arbitrary units")
ax1.set_title("Time Complexity of minFastForwardSeconds")
ax1.legend()

plt.tight_layout()
plt.show()