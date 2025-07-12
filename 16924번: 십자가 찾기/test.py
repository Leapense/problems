import random, time
import matplotlib.pyplot as plt

def in_bounds(r, c, n, m):
    return 0 <= r < n and 0 <= c < m

def max_arm_length(r, c, n, m, grid):
    if grid[r][c] != '*':
        return 0

    length = 0
    while True:
        length += 1
        for dr, dc in ((-length, 0), (length, 0), (0, -length), (0, length)):
            nr, nc = r + dr, c + dc
            if not in_bounds(nr, nc, n, m) or grid[nr][nc] != '*':
                return length - 1

def detect_crosses(n, m, grid):
    crosses = []
    for r in range(n):
        for c in range(m):
            size = max_arm_length(r, c, n, m, grid)
            if size >= 1:
                crosses.append((r, c, size))
    return crosses

def random_grid(n, m, density=0.7):
    return [['*' if random.random() < density else '.' for _ in range(m)] for _ in range(n)]

def benchmark(sizes, trials=3):
    times = []
    for k in sizes:
        elapsed = 0.0
        for _ in range(trials):
            g = random_grid(k, k)
            t0 = time.perf_counter()
            detect_crosses(k, k, g)
            elapsed += time.perf_counter() - t0
        times.append(elapsed / trials)
    return times

if __name__ == "__main__":
    ks = [10, 15, 20, 25, 30]
    t_emp = benchmark(ks)
    t_theory = [t_emp[0] * (k / ks[0]) ** 3 for k in ks]

    plt.plot(ks, t_emp, marker='o', label='Empirical')
    plt.plot(ks, t_theory, linestyle='--', label='~k^3')
    plt.xlabel('Grid size k (n = m = k)')
    plt.ylabel('Time (seconds)')
    plt.legend()
    plt.grid(True)
    plt.show()