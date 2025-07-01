#!/usr/bin/env python3
"""
Visualise theoretical vs. empirical complexity for the ‘friends palindrome’
solver.

Usage
-----
$ python3 complexity_plot.py                       # only theory curves
$ python3 complexity_plot.py --exe ./solver.bin    # theory + measurements
$ python3 complexity_plot.py --exe ./solver.bin --n-max 18 --runs 5
"""
from __future__ import annotations

import argparse
import itertools
import math
import os
import random
import subprocess
import sys
import tempfile
import textwrap
import time
from pathlib import Path
from typing import Final, List, Tuple

try:
    import psutil  # type: ignore
except ModuleNotFoundError:  # pragma: no cover
    psutil = None  # pylint: disable=invalid-name

import matplotlib.pyplot as plt

# ──────────────────────────────────────────────────────────────────────────────
# helper functions
# ──────────────────────────────────────────────────────────────────────────────


def theoretical_time(n: int) -> float:
    """Return an unscaled operation count for N ≤ 20."""
    return (2 ** n) * (n**2)


def theoretical_space(n: int) -> float:
    """Return bytes assuming uint32_t per DP entry."""
    return (2 ** n) * 4  # four bytes per table slot


def random_graph(n: int, p: float = 0.5) -> List[Tuple[int, int]]:
    """
    Generate an undirected graph with edge probability *p*.

    The graph is encoded as a list of 1-based edge tuples (u, v).
    """
    edges: list[tuple[int, int]] = []
    for u, v in itertools.combinations(range(1, n + 1), 2):
        if random.random() < p:
            edges.append((u, v))
    return edges


def write_instance(n: int, edges: List[Tuple[int, int]]) -> str:
    """
    Convert *n* and *edges* into the input format and return as a string.
    """
    header = f"{n} {len(edges)}\n"
    body = "\n".join(f"{u} {v}" for u, v in edges)
    return header + body + ("\n" if edges else "")


def run_binary(exe: Path, instance: str, timeout: float = 5.0) -> Tuple[float, int]:
    """
    Run *exe* with *instance* fed via STDIN.

    Returns
    -------
    (elapsed seconds, peak RSS in bytes or -1 if unavailable)
    """
    if not exe.exists():
        raise FileNotFoundError(exe)

    with tempfile.NamedTemporaryFile(delete=False) as tmp:
        tmp.write(instance.encode())
        tmp.flush()

        start = time.perf_counter()
        try:
            proc = subprocess.Popen(
                [exe],
                stdin=open(tmp.name, "rb"),
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )
            mem_max = -1
            if psutil:
                p = psutil.Process(proc.pid)
                while proc.poll() is None:
                    # poll every 10 ms
                    time.sleep(0.01)
                    mem_max = max(mem_max, p.memory_info().rss)
            proc.wait(timeout=timeout)
        finally:
            elapsed = time.perf_counter() - start
            os.unlink(tmp.name)
    return elapsed, mem_max


# ──────────────────────────────────────────────────────────────────────────────
# plotting
# ──────────────────────────────────────────────────────────────────────────────


def plot_curves(
    n_max: int,
    exe: Path | None,
    runs_per_n: int,
    prob: float,
) -> None:
    n_values: list[int] = list(range(2, n_max + 1))
    time_theory = [theoretical_time(n) for n in n_values]
    space_theory = [theoretical_space(n) for n in n_values]

    fig, (ax_time, ax_space) = plt.subplots(
        1,
        2,
        figsize=(14, 5),
        sharex=True,
        constrained_layout=True,
    )

    ax_time.set_title("Time complexity")
    ax_time.set_xlabel("N")
    ax_time.set_ylabel("Operations (arb. scale)")
    ax_time.set_yscale("log")
    ax_time.plot(n_values, time_theory, label="2ⁿ·N²", color="tab:blue")

    ax_space.set_title("Space complexity")
    ax_space.set_xlabel("N")
    ax_space.set_ylabel("Bytes (log scale)")
    ax_space.set_yscale("log")
    ax_space.plot(n_values, space_theory, label="4·2ⁿ", color="tab:green")

    # empirical overlay
    if exe is not None:
        rng = random.Random(0xC0FFEE)  # reproducible
        time_emp: list[float] = []
        space_emp: list[int] = []

        for n in n_values:
            for _ in range(runs_per_n):
                edges = random_graph(n, prob)
                instance = write_instance(n, edges)
                elapsed, mem = run_binary(exe, instance)
                time_emp.append((n, elapsed))
                space_emp.append((n, mem))

        n_emp, t_emp = zip(*time_emp)
        ax_time.scatter(
            n_emp,
            t_emp,
            label="Measured wall-clock [s]",
            color="tab:red",
            marker="x",
        )

        n_emp, m_emp = zip(*space_emp)
        m_emp_filtered = [v for v in m_emp if v > 0]
        if m_emp_filtered:
            ax_space.scatter(
                n_emp,
                m_emp,
                label="Peak RSS [bytes]",
                color="tab:orange",
                marker="x",
            )

    ax_time.legend()
    ax_space.legend()
    plt.suptitle("Friends-Palindrome Solver: Complexity Overview")
    plt.show()


# ──────────────────────────────────────────────────────────────────────────────
# main
# ──────────────────────────────────────────────────────────────────────────────


def positive_int(value: str) -> int:
    """argparse type helper."""
    ivalue = int(value)
    if ivalue <= 0:
        raise argparse.ArgumentTypeError(f"{value!r} must be > 0")
    return ivalue


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=textwrap.dedent(
            """\
            Plot theoretical and empirical (optional) complexity for the
            C/C++ ‘maximum matching’ solver with N ≤ 20.
            """
        ),
    )
    parser.add_argument(
        "--exe",
        type=Path,
        help="Path to compiled C/C++ solver binary (optional).",
    )
    parser.add_argument(
        "--n-max",
        type=positive_int,
        default=20,
        help="Largest N to evaluate (2…N). Default: 20",
    )
    parser.add_argument(
        "--runs",
        type=positive_int,
        default=3,
        help="Independent random instances per N for empirical runs.",
    )
    parser.add_argument(
        "--prob",
        type=float,
        default=0.5,
        help="Edge probability for random graphs (0..1).",
    )
    return parser


def main() -> None:
    parser = build_parser()
    opts = parser.parse_args()

    if opts.exe and not opts.exe.exists():
        parser.error(f"Executable not found: {opts.exe}")

    plot_curves(opts.n_max, opts.exe, opts.runs, opts.prob)


if __name__ == "__main__":
    main()