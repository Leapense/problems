import matplotlib.pyplot as plt
import matplotx
import numpy as np

n_values = np.linspace(1, 1_000_000, 100, dtype=int)
time_complexity = n_values
space_complexity = n_values

plt.figure(figsize=(10, 6))
with plt.style.context(matplotx.styles.onedark):
    plt.plot(n_values, time_complexity, label="Time Complexity O(n)")
    plt.plot(n_values, space_complexity, label="Space Complexity O(n)", linestyle='--')
    plt.title("Time and Space Complexity of BFS-based Generator Search")
    plt.xlabel("Input Size (n)")
    plt.ylabel("Operations / Memory Usage")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()