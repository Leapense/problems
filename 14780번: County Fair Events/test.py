import numpy as np
import matplotlib.pyplot as plt

def generate_complexity_data(max_n: int) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    n_values = np.arange(1, max_n + 1)
    time_complexity = n_values * np.log2(n_values)
    space_complexity = n_values
    return n_values, time_complexity, space_complexity

def plot_complexity(n_values: np.ndarray, time_complexity: np.ndarray, space_complexity: np.ndarray) -> None:
    plt.style.use('dark_background')
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    ax1.plot(n_values, time_complexity, label='O(N log N)', color='cyan')
    ax1.set_title('Time Complexity')
    ax1.set_xlabel('Input Size (N)')
    ax1.set_ylabel('Operations')
    ax1.grid(True, linestyle='--', alpha=0.7)
    ax1.legend()

    ax2.plot(n_values, space_complexity, label='O(N)', color='magenta')
    ax2.set_title('Space Complexity')
    ax2.set_xlabel('Input Size (N)')
    ax2.set_ylabel('Maximum Memory Usage (KiB)', fontsize=12)
    ax2.legend()
    ax2.grid(True)

    plt.tight_layout(pad=3.0)
    plt.show()

def main() -> None:
    try:
        max_n = 10000
        n_values, time_complexity, space_complexity = generate_complexity_data(max_n)
        plot_complexity(n_values, time_complexity, space_complexity)
    except ImportError as e:
        print(f"Error: Required library not found - {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()