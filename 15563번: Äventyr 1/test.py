#!/usr/bin/env python3
"""
Visualise time- and space-complexity for the ‘violin timeline’ Java solution.

Assumptions
-----------
* Each query costs  log₂(N)  (TreeSet)  →  total time ≈ Q · log₂(N) + N
* Memory is dominated by the TreeSet payload               →  space  ≈ N
* Worst-case Q = N (update + query mixed at 1:1 ratio)

Execution
---------
$ python3 complexity_plot.py
A PNG named  'complexity_plot.png'  is created in the current directory.
"""

from __future__ import annotations

import math
from pathlib import Path
from typing import List, Tuple

import matplotlib.pyplot as plt
import numpy as np


def generate_series(
    min_size: int,
    max_size: int,
    step_size: int,
) -> Tuple[np.ndarray, np.ndarray, np.ndarray]:
    """
    Create three aligned arrays:
    * input_sizes   : N
    * time_costs    : Q·log₂(N) + N,   with Q = N
    * memory_costs  : N
    """
    input_sizes = np.arange(min_size, max_size + 1, step_size, dtype=np.int64)

    # NumPy’s log2 returns float64; keep the same dtype for consistency later
    time_costs = input_sizes * np.log2(input_sizes) + input_sizes
    memory_costs = input_sizes.astype(np.float64)  # cast for unified plotting

    return input_sizes, time_costs, memory_costs


def plot_complexities(
    n_values: np.ndarray,
    time_values: np.ndarray,
    memory_values: np.ndarray,
    destination: Path,
) -> None:
    """
    Render a dual-axis plot:
    • X-axis: N (problem size)
    • Left Y-axis : time cost   (Big-O with hidden constant 1)
    • Right Y-axis: memory cost (Big-O with hidden constant 1)
    """
    fig, ax_time = plt.subplots(figsize=(12, 6))

    ax_space = ax_time.twinx()

    # Time curve
    ax_time.plot(
        n_values,
        time_values,
        color="tab:blue",
        linewidth=2,
        label=r"Time  $T(N)=N\log_2 N + N$",
    )
    ax_time.set_xlabel("N  (number of nodes / queries)")
    ax_time.set_ylabel("Estimated Time Units", color="tab:blue")
    ax_time.tick_params(axis="y", labelcolor="tab:blue")

    # Space curve
    ax_space.plot(
        n_values,
        memory_values,
        color="tab:red",
        linestyle="--",
        linewidth=2,
        label=r"Space $S(N)=N$",
    )
    ax_space.set_ylabel("Estimated Memory Units", color="tab:red")
    ax_space.tick_params(axis="y", labelcolor="tab:red")

    # Titles and legend
    plt.title("Time & Space Complexity for the TreeSet-based Java Solution")
    lines, labels = ax_time.get_legend_handles_labels()
    lines2, labels2 = ax_space.get_legend_handles_labels()
    ax_time.legend(lines + lines2, labels + labels2, loc="upper left")

    # Layout & export
    fig.tight_layout()
    plt.savefig(destination, dpi=150)
    plt.close(fig)


def main() -> None:
    """
    Entry-point: build data, render the graph, and persist it as PNG.
    """
    n_min, n_max, n_step = 1_000, 100_000, 1_000
    xs, ys_time, ys_space = generate_series(n_min, n_max, n_step)

    output_file = Path("complexity_plot.png")
    plot_complexities(xs, ys_time, ys_space, output_file)
    print(f"Graph successfully written to: {output_file.resolve()}")


if __name__ == "__main__":
    main()
