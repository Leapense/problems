from __future__ import annotations

from pathlib import Path
from typing import Tuple

import matplotlib.pyplot as plt
import numpy as np


def build_series(min_n: int, max_n: int, step: int) -> Tuple[np.ndarray, np.ndarray, np.ndarray]:
    sizes = np.arange(min_n, max_n + 1, step, dtype=np.int64)
    time_curve = sizes.astype(np.float64)
    space_curve = np.ones_like(time_curve)
    return sizes, time_curve, space_curve


def render_plot(xs: np.ndarray, ys_time: np.ndarray, ys_space: np.ndarray, destination: Path) -> None:
    fig, axis_time = plt.subplots(figsize=(12, 6))
    axis_space = axis_time.twinx()

    axis_time.plot(xs, ys_time, color="tab:blue", linewidth=2, label=r"Time  $T(N)=N$")
    axis_space.plot(xs, ys_space, color="tab:red", linestyle="--", linewidth=2, label=r"Space $S(N)=1$")

    axis_time.set_xlabel("N  (number of dolls / input size)")
    axis_time.set_ylabel("Relative Time Units", color="tab:blue")
    axis_space.set_ylabel("Relative Space Units", color="tab:red")

    axis_time.tick_params(axis="y", labelcolor="tab:blue")
    axis_space.tick_params(axis="y", labelcolor="tab:red")

    lines, labels = axis_time.get_legend_handles_labels()
    lines2, labels2 = axis_space.get_legend_handles_labels()
    axis_time.legend(lines + lines2, labels + labels2, loc="upper left")

    plt.title("Time and Space Complexity of the Sliding-Window Solution")
    fig.tight_layout()
    plt.savefig(destination, dpi=150)
    plt.close(fig)


def main() -> None:
    n_min, n_max, step = 10_000, 1_000_000, 10_000
    xs, ys_t, ys_s = build_series(n_min, n_max, step)
    output_path = Path("complexity_plot.png")
    render_plot(xs, ys_t, ys_s, output_path)
    print(f"Graph written to: {output_path.resolve()}")


if __name__ == "__main__":
    main()