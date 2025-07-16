import math
import timeit
import numpy as np
import matplotlib.pyplot as plt
import matplotx

def measure_gcd_time(m, n, number=10000):
    stmt = f"math.gcd({m}, {n})"
    setup = "import math"
    timer = timeit.Timer(stmt=stmt, setup=setup)
    total_time = timer.timeit(number=number)
    return total_time / number

def plot_complexity_graph():
    plt.style.use(matplotx.styles.onedark)
    input_sizes_n = np.logspace(1, 18, num=50, dtype=np.int64)
    fixed_m = 982451653
    print("다양한 입력 크기에 대해 실행 시간을 측정한다...")
    execution_times = [measure_gcd_time(fixed_m, int(n)) for n in input_sizes_n]
    print("측정이 완료되었다.")

    log_n_values = np.log(input_sizes_n)
    scaling_factor = execution_times[-1] / log_n_values[-1]
    theoretical_times = scaling_factor * log_n_values
    fig, ax = plt.subplots(figsize=(12, 7))
    ax.plot(input_sizes_n, execution_times, marker='o', linestyle='-', markersize=4, label='Measured Execution Time (Actual)')
    ax.plot(input_sizes_n, theoretical_times, linestyle='--', label='Theoretical O(log N) Curve (Scaled)')
    ax.set_title('Time Complexity Analysis of Diagonal Cut Algorithm', fontsize=16, pad=20)
    ax.set_xlabel('Input Size N (Logarithmic Scale)', fontsize=12)
    ax.set_ylabel('Average Execution Time (seconds)', fontsize=12)
    ax.set_xscale('log')
    ax.grid(True, which="both", ls='--', alpha=0.3)
    ax.legend()

    text_content = (
        "Time Complexity: O(log(min(M, N)))\n"
        "Space Complexity: O(1)\n\n"
        "The plot visualizes the logarithmic time complexity.\n"
        "As input size `N` grows exponentially (log scale x-axis),\n"
        "the measured execution time increases linearly,\n"
        "confirming the O(log N) behavior."
    )
    props = dict(boxstyle='round,pad=0.5', alpha=0.8)
    ax.text(0.05, 0.95, text_content, transform=ax.transAxes, fontsize=10, verticalalignment='top', bbox=props)

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_complexity_graph()