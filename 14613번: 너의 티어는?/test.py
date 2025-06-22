import matplotlib.pyplot as plt

def time_complexity(n: int) -> int:
    return n * (2 * n + 1)

def space_complexity(n: int) -> int:
    return 2 * n + 1

def plot_complexities(n_max: int = 100) -> None:
    ns = list(range(n_max + 1))
    times = [time_complexity(n) for n in ns]
    spaces = [space_complexity(n) for n in ns]

    plt.figure(figsize=(10, 6))
    plt.plot(ns, times, label='Time Complexity T(N) = 2N^2 + N', linewidth=2)
    plt.plot(ns, spaces, label='Space Complexity S(N) = 2N + 1', linewidth=2)

    plt.title('DP Algorithm Complexity', fontsize=14)
    plt.xlabel('N (MATCH_COUNT)', fontsize=12)
    plt.ylabel('Memory Usage', fontsize=12)
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_complexities(100)
