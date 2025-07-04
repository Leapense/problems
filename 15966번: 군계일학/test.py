import tracemalloc
import time
import random
import matplotlib.pyplot as plt

def dp_sequence(sequence):
    dp = {}
    result = 0
    for value in sequence:
        length = dp.get(value - 1, 0) + 1
        if length > dp.get(value, 0):
            dp[value] = length
        if length > result:
            result = length
    return result

ns = [10000, 20000, 40000, 80000, 160000]
times = []
mems = []

for n in ns:
    sequence = [random.randint(1, n) for _ in range(n)]
    tracemalloc.start()
    start = time.perf_counter()
    dp_sequence(sequence)
    duration = time.perf_counter() - start
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    times.append(duration)
    mems.append(peak)

plt.plot(ns, times)
plt.xlabel('Input size n')
plt.ylabel('Time (seconds)')
plt.title('Time Complexity O(n)')
plt.show()

plt.plot(ns, mems)
plt.xlabel('Input size n')
plt.ylabel('Memory usage (bytes)')
plt.title('Space Complexity O(n)')
plt.show()