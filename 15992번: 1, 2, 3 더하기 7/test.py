import matplotlib.pyplot as plt
import numpy as np

def plot_time_space_complexity():
    ns = np.linspace(100, 2000, 20, dtype=int)
    ms = np.linspace(100, 2000, 20, dtype=int)

    time_complexities = []
    space_complexities = []

    for n, m in zip(ns, ms):
        time_complexities.append(n * m)
        space_complexities.append(n * m)

    plt.figure(figsize=(12, 5))
    plt.plot(ns, time_complexities, 'o-', label='O(n*m)')
    plt.xlabel('max_n')
    plt.ylabel('Time Complexity')
    plt.title('Time Complexity vs. max_n')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(ms, space_complexities, 's-', label='O(n*m)', color='orange')
    plt.xlabel('max_m')
    plt.ylabel('Space Complexity')
    plt.title('Space Complexity vs. max_m')
    plt.legend()
    
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_time_space_complexity()