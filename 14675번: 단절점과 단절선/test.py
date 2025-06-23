import matplotlib.pyplot as plt
import numpy as np

def plot_complexities():
    plt.style.use('dark_background')
    n_values = np.logspace(2, 5, num=100, dtype=int)
    q_values = n_values.copy()

    time_complexity = n_values + q_values
    space_complexity = n_values

    fig, ax = plt.subplots(figsize=(8,5))
    ax.plot(n_values, time_complexity, label='Time: O(N + Q)', linewidth=2, color='#1f77b4')
    ax.plot(n_values, space_complexity, label='Space: O(N)', linewidth=2, color='#ff7f0e')
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.set_xlabel('Input size N (log scale)')
    ax.set_ylabel('Operations / Memory (log scale)')
    ax.set_title('Time / Space Complexity Visualizer', pad=15)
    ax.legend(loc='upper left')
    ax.grid(color='gray', linestyle='--', alpha=0.3)

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_complexities()