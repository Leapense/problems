import random
import time
import tracemalloc
import matplotlib.pyplot as plt

K_DEFAULT = 1
MAX_N = 100_000
STEP = 5_000

def intersects(arr_y, k):
    prev = 0
    for i in range(1, len(arr_y)):
        curr = arr_y[i] - k * i
        if (curr == 0 and i > 0) or (prev == 0 and i - 1 > 0):
            return True
        if (prev < 0 < curr) or (prev > 0 > curr):
            return True
        prev = curr
    return False

def benchmark(max_n=MAX_N, step=STEP, k=K_DEFAULT):
    ns, times, memories = [], [], []
    rng = random.Random(42)
    for n in range(step, max_n + 1, step):
        arr_y = [0] + [rng.randint(0, 1 << 30) for _ in range(n)]
        tracemalloc.start()
        start = time.perf_counter()
        intersects(arr_y, k)
        elapsed = time.perf_counter() - start
        _, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()
        ns.append(n)
        times.append(elapsed)
        memories.append(peak / 1024)
    return ns, times, memories

def main():
    ns, times, memories = benchmark()
    fig, ax_left = plt.subplots()
    ax_left.plot(ns, times, marker="o")
    ax_left.set_xlabel("n (input size)")
    ax_left.set_ylabel("Time (seconds)")
    ax_right = ax_left.twinx()
    ax_right.plot(ns, memories, marker="s")
    ax_right.set_ylabel("Memory (KiB)")
    plt.title("Time / Space Complexity of intersects()")
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()