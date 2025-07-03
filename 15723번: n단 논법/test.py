import sys
from typing import List
import matplotlib.pyplot as plt
import numpy as np

ALPHABET_SIZE = 26
FLOYD_TIME = ALPHABET_SIZE ** 3
SPACE_USAGE = ALPHABET_SIZE ** 2
DEFAULT_M = 10

def time_complexity(n_values: np.ndarray, m: int) -> np.ndarray:
    return FLOYD_TIME + n_values + m

def plot_complexities(n_max: int = 26) -> None:
    n_vals: np.ndarray = np.arange(2, n_max + 1)
    time_vals: np.ndarray = time_complexity(n_vals, DEFAULT_M)
    space_vals: np.ndarray = np.full_like(n_vals, SPACE_USAGE)
    fig, ax_time = plt.subplots()
    ax_time.set_title('Time / Space Complexity of Syllogism Solver')
    ax_time.set_xlabel('Number of Premises (n)')
    ax_time.set_ylabel('Time Units', color='tab:blue')
    ax_time.plot(n_vals, time_vals, label='Time Complexity', color='tab:blue')
    ax_time.tick_params(axis='y', labelcolor='tab:blue')
    ax_space = ax_time.twinx()
    ax_space.set_ylabel('Space Units', color='tab:orange')
    ax_space.plot(n_vals, space_vals, label='Space Complexity', color='tab:orange')
    ax_space.tick_params(axis='y', labelcolor='tab:orange')

    handles1, labels1 = ax_time.get_legend_handles_labels()
    handles2, labels2 = ax_space.get_legend_handles_labels()
    ax_time.legend(handles1 + handles2, labels1 + labels2, loc='upper left')

    plt.tight_layout()
    plt.show()

def main(args: List[str]) -> None:
    if len(args) > 1:
        n_limit = int(args[1])
    else:
        n_limit = 26
    plot_complexities(n_limit)

if __name__ == "__main__":
    main(sys.argv)