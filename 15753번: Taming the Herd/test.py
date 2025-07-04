import sys
from typing import List
import numpy as np
import matplotlib.pyplot as plt

UPPER_BOUND = 100


def time_curve(n_axis: np.ndarray) -> np.ndarray:
    return n_axis ** 3


def space_curve(n_axis: np.ndarray) -> np.ndarray:
    return n_axis ** 2


def draw(n_max: int) -> None:
    n_values = np.arange(1, n_max + 1)
    t_values = time_curve(n_values)
    s_values = space_curve(n_values)

    fig, ax_left = plt.subplots()
    ax_left.set_title('Time / Space Complexity for Taming the Herd')
    ax_left.set_xlabel('N (days in log)')
    ax_left.set_ylabel('Time units', color='tab:blue')
    ax_left.plot(n_values, t_values, color='tab:blue', label='Time O(N³)')
    ax_left.tick_params(axis='y', labelcolor='tab:blue')

    ax_right = ax_left.twinx()
    ax_right.set_ylabel('Space units', color='tab:orange')
    ax_right.plot(n_values, s_values, color='tab:orange', label='Space O(N²)')
    ax_right.tick_params(axis='y', labelcolor='tab:orange')

    handles_left, labels_left = ax_left.get_legend_handles_labels()
    handles_right, labels_right = ax_right.get_legend_handles_labels()
    ax_left.legend(handles_left + handles_right, labels_left + labels_right, loc='upper left')

    plt.tight_layout()
    plt.show()


def main(args: List[str]) -> None:
    n_limit = int(args[1]) if len(args) > 1 else UPPER_BOUND
    draw(n_limit)


if __name__ == '__main__':
    main(sys.argv)