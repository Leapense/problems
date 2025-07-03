import numpy as np
import matplotlib.pyplot as plt

def plot_complexity(max_n: int = 100_000) -> None:
    n_values = np.arange(1, max_n + 1)
    time_values = n_values
    space_values = np.ones_like(n_values)

    fig, ax_time = plt.subplots()
    ax_time.set_title('Time / Space Complexity of the Java DP Solution')
    ax_time.set_xlabel('Input size (N)')
    ax_time.set_ylabel('Time units', color='tab:blue')
    ax_time.plot(n_values, time_values, color='tab:blue', label='Time Complexity O(N)')
    ax_time.tick_params(axis='y', labelcolor='tab:blue')

    ax_space = ax_time.twinx()
    ax_space.set_ylabel('Space units', color='tab:orange')
    ax_space.plot(n_values, space_values, color='tab:orange', label='Space Complexity O(1)')
    ax_space.tick_params(axis='y', labelcolor='tab:orange')

    lines, labels = ax_time.get_legend_handles_labels()
    lines2, labels2 = ax_space.get_legend_handles_labels()
    ax_time.legend(lines + lines2, labels + labels2, loc='upper left')
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    plot_complexity()