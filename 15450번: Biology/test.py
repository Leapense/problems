import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def choose3(n: np.ndarray) -> np.ndarray:
    return n * (n - 1) * (n - 2) // 6

def build_matrices(a_min: int = 5, a_max: int = 25, b_min: int = 1, b_max: int = 4):
    a_vals = np.arange(a_min, a_max + 1)
    b_vals = np.arange(b_min, b_max + 1)
    A, B = np.meshgrid(a_vals, b_vals)
    n = A * B - 2
    return A, B, choose3(n), n

def main() -> None:
    A, B, time_c, space_c = build_matrices()
    fig = plt.figure(figsize=(12, 6))
    ax1 = fig.add_subplot(1, 2, 1, projection='3d')
    ax1.plot_surface(A, B, np.log10(time_c), cmap='viridis')
    ax1.set_title('log10(Time complexity: C(n, 3))')
    ax1.set_xlabel('A (ranks)')
    ax1.set_ylabel('B (suits)')
    ax1.set_zlabel('log10 operations')

    ax2 = fig.add_subplot(1, 2, 2, projection='3d')
    ax2.plot_surface(A, B, space_c, cmap='plasma')
    ax2.set_title('Space complexity: n = A·B − 2')
    ax2.set_xlabel('A (ranks)')
    ax2.set_ylabel('B (suits)')
    ax2.set_zlabel('cards stored')

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()