import time
import random
import string
import tracemalloc
import matplotlib.pyplot as plt
import numpy as np

def generate_test_data(n: int) -> tuple[list[str], list[str]]:
    """
    Generates random test data for the Tunel problem.

    Args:
        n: The number of cars.

    Returns:
        A tuple containing the entrance list and a shuffled exit list.
    """
    # Generate N unique license plates
    # e.g., 'CAR_0001', 'CAR_0002', ...
    entrance_list = [f"CAR_{i:04d}" for i in range(n)]
    
    # The exit list is a permutation of the entrance list
    exit_list = entrance_list[:]  # Create a copy
    random.shuffle(exit_list)
    
    return entrance_list, exit_list

def analyze_overtakes(entrance_list: list[str], exit_list: list[str]) -> int:
    """
    The core logic of the Tunel problem solution, refactored for analysis.
    This function has an O(N^2) time complexity and O(N) space complexity.
    """
    n = len(entrance_list)
    if n == 0:
        return 0

    # O(N) space and O(N) time to build the map
    entrance_positions = {plate: i for i, plate in enumerate(entrance_list)}

    # O(N) space for the set in the worst case
    violators = set()

    # O(N^2) time for the nested loops
    for i in range(n):
        for j in range(i + 1, n):
            car_that_exited_earlier = exit_list[i]
            car_that_exited_later = exit_list[j]

            # If the car that exited earlier entered LATER, it must have overtaken.
            if entrance_positions[car_that_exited_earlier] > entrance_positions[car_that_exited_later]:
                violators.add(car_that_exited_earlier)
    
    return len(violators)

def main():
    """
    Main function to run the complexity analysis and plot the results.
    """
    # Define the range of N to test
    n_values = np.arange(100, 1001, 100)
    measured_times = []
    measured_peak_mems = []

    print("Starting complexity analysis...")
    print(f"Testing for N values: {list(n_values)}")

    for n in n_values:
        # 1. Generate data for the current N
        entrance_data, exit_data = generate_test_data(n)

        # 2. Measure execution time
        start_time = time.perf_counter()
        analyze_overtakes(entrance_data, exit_data)
        end_time = time.perf_counter()
        measured_times.append(end_time - start_time)

        # 3. Measure peak memory usage
        tracemalloc.start()
        analyze_overtakes(entrance_data, exit_data)
        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()
        # Convert bytes to megabytes (MB)
        measured_peak_mems.append(peak / 1024**2)
        
        print(f"  N = {n:4d}: Time = {measured_times[-1]:.6f}s, Peak Memory = {measured_peak_mems[-1]:.4f} MB")

    print("Analysis complete. Generating plots...")

    # --- Plotting ---

    plt.style.use('seaborn-v0_8-whitegrid')
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

    # --- Time Complexity Plot (O(N^2)) ---
    ax1.plot(n_values, measured_times, 'bo-', label='Measured Execution Time')
    
    # Fit a theoretical O(N^2) curve to the measured data
    # We find a constant 'c' such that c * N^2 matches the trend
    # A simple way is to match the last point: c = last_time / last_n^2
    c_time = measured_times[-1] / (n_values[-1]**2)
    theoretical_time = c_time * (n_values**2)
    ax1.plot(n_values, theoretical_time, 'r--', label='Theoretical O(N^2) Curve')
    
    ax1.set_title('Time Complexity Analysis')
    ax1.set_xlabel('Input Size (N)')
    ax1.set_ylabel('Execution Time (seconds)')
    ax1.legend()
    ax1.grid(True)

    # --- Space Complexity Plot (O(N)) ---
    ax2.plot(n_values, measured_peak_mems, 'go-', label='Measured Peak Memory')

    # Fit a theoretical O(N) curve to the measured data
    # We find a constant 'c' such that c * N matches the trend
    c_mem = measured_peak_mems[-1] / n_values[-1]
    theoretical_space = c_mem * n_values
    ax2.plot(n_values, theoretical_space, 'y--', label='Theoretical O(N) Curve')

    ax2.set_title('Space Complexity Analysis')
    ax2.set_xlabel('Input Size (N)')
    ax2.set_ylabel('Peak Memory Usage (MB)')
    ax2.legend()
    ax2.grid(True)

    fig.suptitle('Performance Analysis of the "Tunel" Problem Solution', fontsize=16)
    plt.tight_layout(rect=[0, 0, 1, 0.96])
    plt.show()


if __name__ == "__main__":
    main()