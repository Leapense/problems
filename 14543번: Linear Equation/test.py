import matplotlib.pyplot as plt
import numpy as np

def plot_complexity():
    P_values = np.arange(1, 101)
    time_complexity_O_P = P_values * 0.1
    space_complexity_O_1 = np.full_like(P_values, 10.0)
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(P_values, time_complexity_O_P, color='blue', marker='o', linestyle='-', markersize=4, label='Time Complexity: O(P)')
    plt.title('Time Complexity vs. Number of Data Sets (P)')
    plt.xlabel('Number of Data Sets (P)')
    plt.ylabel('Relative Time Units')
    plt.grid(True)
    plt.legend()
    plt.xticks(np.arange(0, 101, 10))
    plt.yticks(np.arange(0, 12, 1))

    plt.subplot(1, 2, 2)
    plt.plot(P_values, space_complexity_O_1, color='red', marker='s', linestyle='--', markersize=4, label='Space Complexity: O(1)')
    plt.title('Space Complexity vs. Number of Data Sets (P)')
    plt.xlabel('Number of Data Sets (P)')
    plt.ylabel('Relative Memory Units')
    plt.grid(True)
    plt.legend()
    plt.xticks(np.arange(0, 101, 10))
    plt.ylim(0, 20)

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_complexity()