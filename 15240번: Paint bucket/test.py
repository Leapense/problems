import numpy as np
import matplotlib.pyplot as plt

def main():
    N = np.linspace(0, 1_000_000, 500)
    a = 1e-6
    b = 1e-7
    time_curve = a * N
    space_curve = b * N

    plt.figure(figsize=(8, 5))
    plt.plot(N, time_curve, label="Time Complexity T(N) = a * N", color="C0", linewidth=2)
    plt.plot(N, space_curve, label="Space Complexity S(N) = b * N", color="C1", linewidth=2)
    plt.title("Flood-Fill Algorithm Complexity (C/C++ Implementation)")
    plt.xlabel("Input size N = R * C (number of pixels)")
    plt.ylabel("Cost (seconds | megabytes)")
    plt.legend()
    plt.grid(True, linestyle='--', alpha=0.5)

    plt.xlim(0, N.max())
    ymax = max(time_curve.max(), space_curve.max())
    plt.ylim(0, ymax * 1.05)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()