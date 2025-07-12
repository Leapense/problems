import numpy as np
import matplotlib.pyplot as plt

def ops(R, C, N):
    return R * C * N

def plot_vs_N(R=100, C=100, N_max=1000):
    N_vals = np.arange(1, N_max + 1)
    plt.figure()
    plt.plot(N_vals, ops(R, C, N_vals))
    plt.xlabel("Seconds (N)")
    plt.ylabel("Operations ~ R * C * N")
    plt.title(f"Time Complexity vs N  (R={R}, C={C})")
    plt.grid(True)
    plt.tight_layout()
    plt.show()

def plot_vs_area(N=100, side_max=200):
    side = np.arange(1, side_max + 1)
    area = side ** 2
    plt.figure()
    plt.plot(area, ops(side, side, N))
    plt.xlabel("Grid area R * C")
    plt.ylabel("Operations ~ R * C * N")
    plt.title(f"Time Complexity vs board area (N={N})")
    plt.grid(True)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    plot_vs_N(R=60, C=60, N_max=50)
    plot_vs_area(N=200, side_max=150)