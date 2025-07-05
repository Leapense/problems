import time
import matplotlib.pyplot as plt
import matplotx
import numpy as np
import sys

plt.style.use(matplotx.styles.github["dark"])

MOD = 10 ** 9 + 9

def dp_compute(max_n):
    odd = [0] * (max_n + 4)
    even = [0] * (max_n + 4)
    even[0] = 1

    for i in range(1, max_n + 1):
        new_odd = 0
        new_even = 0
        if i - 1 >= 0:
            new_odd = (new_odd + even[i - 1]) % MOD
            new_even = (new_even + odd[i - 1]) % MOD
        if i - 2 >= 0:
            new_odd = (new_odd + even[i - 2]) % MOD
            new_even = (new_even + odd[i - 2]) % MOD
        if i - 3 >= 0:
            new_odd = (new_odd + even[i - 3]) % MOD
            new_even = (new_even + odd[i - 3]) % MOD
        odd[i] = new_odd
        even[i] = new_even
    return odd, even

def measure_time_space():
    ns = list(range(1000, 100001, 5000))
    times = []
    memories = []

    for n in ns:
        start = time.time()
        odd, even = dp_compute(n)
        end = time.time()
        times.append(end - start)

        mem_bytes = (sys.getsizeof(odd) + sys.getsizeof(even))
        memories.append(mem_bytes / (1024 * 1024))

    return ns, times, memories

ns, times, memories = measure_time_space()

plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
plt.plot(ns, times, marker='o')
plt.title("Time vs. max_n")
plt.xlabel("max_n")
plt.ylabel("Time (seconds)")

plt.subplot(1, 2, 2)
plt.plot(ns, memories, marker='s', color='orange')
plt.title("Memory vs. max_n")
plt.xlabel("max_n")
plt.ylabel("Memory (MB)")

plt.tight_layout()
plt.show()