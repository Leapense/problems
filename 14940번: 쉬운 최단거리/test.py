import os
import random
import subprocess
import time
import psutil
import matplotlib.pyplot as plt
import numpy as np

# --- Configuration ---
# Set the name of your compiled C/C++ executable
EXECUTABLE_NAME = "solver.exe" if os.name == 'nt' else "solution"

# Define the range of grid sizes (N x N) to test
# The total input size will be N*N
MIN_GRID_DIM = 50      # Start with a 50x50 grid
MAX_GRID_DIM = 100     # Go up to an 100x100 grid
STEP_GRID_DIM = 5     # Increment the dimension by 5 each time

# Number of runs to average for each size to get smoother results
RUNS_PER_SIZE = 3

# --- Helper Functions ---

def generate_input_file(n: int, m: int, filename: str = "temp_input.in"):
    """Generates a random grid input file for the problem."""
    with open(filename, "w") as f:
        f.write(f"{n} {m}\n")
        
        # Create a flat grid, mostly passable land (1)
        grid = [1] * (n * m)
        # Sprinkle in some impassable terrain (0)
        num_walls = int(n * m * 0.1) # 10% walls
        for _ in range(num_walls):
            idx = random.randint(0, n * m - 1)
            grid[idx] = 0
            
        # Place the single target (2)
        target_idx = random.randint(0, n * m - 1)
        grid[target_idx] = 2
        
        # Write the grid to the file
        for i in range(n):
            row = grid[i*m : (i+1)*m]
            f.write(" ".join(map(str, row)) + "\n")

def run_and_measure(input_filename: str) -> tuple[float, float]:
    """
    Runs the compiled executable and measures its execution time and peak memory usage.
    Returns (elapsed_time_sec, peak_memory_mb).
    """
    elapsed_time = 0
    peak_memory_mb = 0
    
    try:
        with open(input_filename, "r") as stdin_file:
            # Start the process
            start_time = time.perf_counter()
            process = subprocess.Popen(
                [os.path.join('.', EXECUTABLE_NAME)],
                stdin=stdin_file,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE
            )

            # Monitor memory usage while the process is running
            p_psutil = psutil.Process(process.pid)
            peak_memory_bytes = 0
            while process.poll() is None:
                try:
                    # memory_info().rss is Resident Set Size
                    mem_info = p_psutil.memory_info().rss
                    if mem_info > peak_memory_bytes:
                        peak_memory_bytes = mem_info
                except psutil.NoSuchProcess:
                    # Process finished between poll() and memory check
                    break
                time.sleep(0.001) # Sleep briefly to avoid busy-waiting

            end_time = time.perf_counter()
            
            # Final check on memory after process completion
            try:
                 mem_info = p_psutil.memory_info().rss
                 if mem_info > peak_memory_bytes:
                     peak_memory_bytes = mem_info
            except psutil.NoSuchProcess:
                pass

            # Check for errors
            stdout, stderr = process.communicate()
            if process.returncode != 0:
                print(f"  -> Error running executable (exit code {process.returncode}):")
                print(f"  -> Stderr: {stderr.decode(errors='ignore')}")
                return (0, 0)

            elapsed_time = end_time - start_time
            peak_memory_mb = peak_memory_bytes / (1024 * 1024)

    except FileNotFoundError:
        print(f"Error: Executable '{EXECUTABLE_NAME}' not found.")
        print("Please compile your C/C++ code and place the executable in the same directory.")
        exit(1)
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return (0, 0)
        
    return elapsed_time, peak_memory_mb

def plot_results(sizes: list[int], times: list[float], memories: list[float]):
    """Plots the collected performance data."""
    
    # Fit a line to the data to visualize the linear trend (O(N))
    time_coeffs = np.polyfit(sizes, times, 1)
    time_fit = np.poly1d(time_coeffs)
    
    mem_coeffs = np.polyfit(sizes, memories, 1)
    mem_fit = np.poly1d(mem_coeffs)

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 12))
    fig.suptitle(f'Performance Analysis of "{EXECUTABLE_NAME}"', fontsize=16)

    # --- Time Complexity Plot ---
    ax1.plot(sizes, times, 'o', label='Measured Data')
    ax1.plot(sizes, time_fit(sizes), 'r--', label=f'Linear Fit (O(N))')
    ax1.set_title('Time Complexity')
    ax1.set_xlabel('Input Size (N = n * m)')
    ax1.set_ylabel('Execution Time (seconds)')
    ax1.legend()
    ax1.grid(True)

    # --- Space Complexity Plot ---
    ax2.plot(sizes, memories, 'o', label='Measured Data')
    ax2.plot(sizes, mem_fit(sizes), 'r--', label=f'Linear Fit (O(N))')
    ax2.set_title('Space Complexity')
    ax2.set_xlabel('Input Size (N = n * m)')
    ax2.set_ylabel('Peak Memory Usage (MB)')
    ax2.legend()
    ax2.grid(True)
    
    plt.tight_layout(rect=[0, 0, 1, 0.96])
    plt.show()


# --- Main Execution ---
if __name__ == "__main__":
    input_sizes = []
    avg_times = []
    avg_mems = []

    print("Starting performance analysis...")
    
    # Check if executable exists before starting
    if not os.path.exists(EXECUTABLE_NAME):
        print(f"Error: Executable '{EXECUTABLE_NAME}' not found in the current directory.")
        exit(1)

    for dim in range(MIN_GRID_DIM, MAX_GRID_DIM + 1, STEP_GRID_DIM):
        total_input_size = dim * dim
        print(f"Testing grid size: {dim}x{dim} (N = {total_input_size})...")
        
        run_times, run_mems = [], []
        for i in range(RUNS_PER_SIZE):
            print(f"  Run {i+1}/{RUNS_PER_SIZE}...", end="", flush=True)
            generate_input_file(dim, dim)
            elapsed_time, peak_mem = run_and_measure("temp_input.in")
            if elapsed_time > 0: # Only record successful runs
                run_times.append(elapsed_time)
                run_mems.append(peak_mem)
            print(f" done ({elapsed_time:.4f}s, {peak_mem:.2f}MB)")

        if run_times: # If there were any successful runs
            input_sizes.append(total_input_size)
            avg_times.append(sum(run_times) / len(run_times))
            avg_mems.append(sum(run_mems) / len(run_mems))

    # Clean up the temporary file
    if os.path.exists("temp_input.in"):
        os.remove("temp_input.in")

    if not input_sizes:
        print("\nNo data was collected. Exiting.")
    else:
        print("\nAnalysis complete. Generating plots...")
        plot_results(input_sizes, avg_times, avg_mems)