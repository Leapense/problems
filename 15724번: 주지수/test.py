import sys
from typing import List
import numpy as np
import matplotlib.pyplot as plt

MAX_LIMIT = 1024
WORST_CASE_K = 100_000

def time_values(n_axis: np.ndarray, k_const: int) -> np.ndarray:
    return n_axis ** 2 + k_const

def space_values(n_axis: np.ndarray) -> np.ndarray:
    return (n_axis + 1) ** 2

def plot_complexity(n_max: int, k_const: int) -> None:
    n_axis = np.arange(1, n_max + 1)
    t_axis = time_values(n_axis, k_const)
    s_axis = space_values(n_axis)

    fig, ax_left = plt.subplots()
    ax_left.set_title('Time / Space Complexity of Prefix-Sum Solver')
    ax_left.set_xlabel('Grid size N (N = M)')
    ax_left.set_ylabel('Time units', color='tab:blue')
    ax_left.plot(n_axis, t_axis, color='tab:blue', label='Time O(N² + K)')
    ax_left.tick_params(axis='y', labelcolor='tab:blue')

    ax_right = ax_left.twinx()
    ax_right.set_ylabel('Space units', color='tab:orange')
    ax_right.plot(n_axis, s_axis, color='tab:orange', label='Space O((N+1)²)')
    ax_right.tick_params(axis='y', labelcolor='tab:orange')

    handles_left, labels_left = ax_left.get_legend_handles_labels()
    handles_right, labels_right = ax_right.get_legend_handles_labels()
    ax_left.legend(handles_left + handles_right, labels_left + labels_right, loc='upper left')

    plt.tight_layout()
    plt.show()

def main(argv: List[str]) -> None:
    if len(argv) > 1:
        n_max = int(argv[1])
    else:
        n_max = MAX_LIMIT
    if len(argv) > 2:
        k_const = int(argv[2])
    else:
        k_const = WORST_CASE_K
    plot_complexity(n_max, k_const)

if __name__ == "__main__":
    main(sys.argv)