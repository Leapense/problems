import time
import tracemalloc
import matplotlib.pyplot as plt
import numpy as np
from typing import List, Tuple

def simulate_c23_algorithm(n: int, f: List[int], f_inv: List[int]) -> int:
    f_a, f_b = n, n
    a_digits = [0] * 8
    b_digits = [0] * 8
    a_len, b_len = 0, 0

    while f_a > 0:
        a_digits[a_len] = f_inv[f_a % 10]
        f_a //= 10
        a_len += 1
    while f_b > 0:
        b_digits[b_len] = f_inv[f_b % 10]
        f_b //= 10
        b_len += 1

    a = 0
    for i in range(a_len - 1, -1, -1):
        a = a * 10 + a_digits[i]
    b = 0
    for i in range(b_len - 1, -1, -1):
        b = b * 10 + b_digits[i]

    sum_ab = a + b
    sum_digits = [0] * 8
    sum_len = 0
    while sum_ab > 0:
        sum_digits[sum_len] = f[sum_ab % 10]
        sum_ab //= 10
        sum_len += 1
    result = 0
    for i in range(sum_len - 1, -1, -1):
        result = result * 10 + sum_digits[i]

    return result

def simulate_cpp26_algorithm(n: int, f: List[int], f_inv: List[int]) -> int:
    f_a, f_b = n, n
    a_digits, b_digits = [], []

    while f_a > 0:
        a_digits.append(f_inv[f_a % 10])
        f_a //= 10
    while f_b > 0:
        b_digits.append(f_inv[f_b % 10])
        f_b //= 10

    a = 0
    for digit in reversed(a_digits):
        a = a * 10 + digit
    b = 0
    for digit in reversed(b_digits):
        b = b * 10 + digit

    sum_ab = a + b
    sum_digits = []
    while sum_ab > 0:
        sum_digits.append(f[sum_ab % 10])
        sum_ab //= 10

    result = 0
    for digit in reversed(sum_digits):
        result = result * 10 + digit

    return result

def measure_performance(input_sizes: List[int], f: List[int], f_inv: List[int]) -> Tuple[List[float], List[float], List[float], List[float]]:
    c23_times, cpp26_times = [], []
    c23_memory, cpp26_memory = [], []

    for n in input_sizes:
        # Measure C23 performance
        tracemalloc.start()
        start_time = time.perf_counter()
        simulate_c23_algorithm(n, f, f_inv)
        c23_times.append(time.perf_counter() - start_time)
        current, peak = tracemalloc.get_traced_memory()
        c23_memory.append(peak / 1024)  # Convert to KB
        tracemalloc.stop()

        # Measure C++26 performance
        tracemalloc.start()
        start_time = time.perf_counter()
        simulatesure = simulate_cpp26_algorithm(n, f, f_inv)
        cpp26_times.append(time.perf_counter() - start_time)
        current, peak = tracemalloc.get_traced_memory()
        cpp26_memory.append(peak / 1024)  # Convert to KB
        tracemalloc.stop()

    return c23_times, cpp26_times, c23_memory, cpp26_memory

def plot_complexity(input_sizes: List[int], c23_times: List[float], cpp26_times: List[float], c23_memory: List[float], cpp26_memory: List[float]) -> None:
    plt.figure(figsize=(12, 5))

    # Time complexity plot
    plt.subplot(1, 2, 1)
    plt.plot(input_sizes, c23_times, label='C23 (Fixed Arrays)', marker='o')
    plt.plot(input_sizes, cpp26_times, label='C++26 (Dynamic Vectors)', marker='s')
    plt.xscale('log')
    plt.yscale('linear')
    plt.xlabel('Input Size (n)')
    plt.ylabel('Execution Time (seconds)')
    plt.title('Time Complexity: O(log n)')
    plt.legend()
    plt.grid(True)

    # Space complexity plot
    plt.subplot(1, 2, 2)
    plt.plot(input_sizes, c23_memory, label='C23 (Fixed Arrays)', marker='o')
    plt.plot(input_sizes, cpp26_memory, label='C++26 (Dynamic Vectors)', marker='s')
    plt.xscale('log')
    plt.yscale('linear')
    plt.xlabel('Input Size (n)')
    plt.ylabel('Peak Memory Usage (KB)')
    plt.title('Space Complexity: O(1) vs O(log n)')
    plt.legend()
    plt.grid(True)

    plt.tight_layout()
    plt.show()

def main() -> None:
    f = [6, 5, 4, 0, 1, 3, 8, 9, 2, 7]
    f_inv = [0] * 10
    for i in range(10):
        f_inv[f[i]] = i

    input_sizes = [10 ** i for i in range(1, 8)]
    c23_times, cpp26_times, c23_memory, cpp26_memory = measure_performance(input_sizes, f, f_inv)
    plot_complexity(input_sizes, c23_times, cpp26_times, c23_memory, cpp26_memory)

if __name__ == "__main__":
    main()