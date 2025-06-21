from __future__ import annotations

import argparse
import math
import os
from typing import Tuple

import matplotlib.pyplot as plt
import numpy as np

FONT_NAME: str = "Apple SD Gothic Neo"
MAX_N: int = 20000

def apply_global_style(is_dark: bool) -> None:
    style_name: str = "dark_background" if is_dark else "default"
    plt.style.use(style_name)

    plt.rcParams["font.family"] = FONT_NAME
    plt.rcParams["axes.unicode_minus"] = False

    if not is_dark:
        grid_color: str = "0.85"
        plt.rcParams["grid.color"] = grid_color
        plt.rcParams["axes.edgecolor"] = "0.3"

def build_complexity_data() -> Tuple[np.ndarray, np.ndarray, np.ndarray]:
    n_values: np.ndarray = np.arange(1, MAX_N + 1, 100)
    time_complexity: np.ndarray = n_values * np.log2(n_values)
    space_complexity: np.ndarray = n_values
    return n_values, time_complexity, space_complexity

def render_plot(n_vals: np.ndarray, t_vals: np.ndarray, s_vals: np.ndarray, is_dark: bool) -> None:
    fig, ax_time = plt.subplots(figsize=(10, 6))
    ax_time.plot(n_vals, t_vals, color='tab:cyan', label="T(n) = n×log₂n", linewidth=1.6)
    ax_time.set_xlabel("n (입력 크기)")
    ax_time.set_ylabel("시간 복잡도", color="tab:cyan")
    ax_time.tick_params(axis="y", labelcolor="tab:cyan")

    ax_space = ax_time.twinx()
    ax_space.plot(n_vals, s_vals, color="tab:orange", linestyle="--", label="S(n) = n", linewidth=1.6)
    ax_space.set_ylabel("공간 복잡도", color="tab:orange")
    ax_space.tick_params(axis="y", labelcolor="tab:orange")

    ax_time.set_xscale("log")
    ax_time.set_yscale("log")
    ax_space.set_yscale("log")

    lines, labels = ax_time.get_legend_handles_labels()
    lines2, labels2 = ax_space.get_legend_handles_labels()
    ax_time.legend(lines + lines2, labels + labels2, loc="upper left", framealpha=0.8)

    plt.title("스프링클러 알고리즘 시간/공간 복잡도 (로그 스케일)")
    ax_time.grid(which="both", linestyle=":", linewidth=0.6, alpha=0.5)

    if is_dark:
        fig.patch.set_facecolor("#222222")

    plt.tight_layout()
    plt.show()

def parse_cli() -> bool:
    """CLI 플래그 / 환경변수를 읽어 다크모드 여부 판단."""
    parser = argparse.ArgumentParser(
        description="스프링클러 복잡도 그래프 (다크/라이트 모드 전환)")
    parser.add_argument("--dark", action="store_true",
                        help="다크모드 강제 활성화")
    args = parser.parse_args()
    env_dark: bool = os.environ.get("DARK", "0") == "1"
    return args.dark or env_dark

def main() -> None:
    """스크립트 메인."""
    dark_mode: bool = parse_cli()
    apply_global_style(dark_mode)

    n_vals, t_vals, s_vals = build_complexity_data()
    render_plot(n_vals, t_vals, s_vals, dark_mode)

if __name__ == "__main__":
    main()