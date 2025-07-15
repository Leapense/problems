import matplotlib.pyplot as plt
import numpy as np
import matplotx
import math

def simulate_algorithm_runtime(p_values, q, a, b, c, d):
    sell_ops = p_values / a
    initial_coins = (q / c) * d
    search_space_size = initial_coins / b if b > 0 else 1
    buy_ops = np.log2(np.maximum(1, search_space_size))
    total_ops = sell_ops + buy_ops
    return total_ops

plt.style.use(matplotx.styles.onedark)
Q_fixed = 8000
A_fixed = 2
B_fixed = 3
C_fixed = 4
D_fixed = 5

p_range = np.linspace(1, 10000, 400)

simulated_time = simulate_algorithm_runtime(p_range, Q_fixed, A_fixed, B_fixed, C_fixed, D_fixed)

linear_reference = p_range / A_fixed

plt.figure(figsize=(12, 7))
plt.plot(p_range, simulated_time, label='Simulated Algorithm Time (O(P) + O(log(N)))')
plt.plot(p_range, linear_reference, label='Theoretical Complexity O(P) Reference', linestyle='--', alpha=0.8)

plt.title('Time Complexity Analysis of BitBerry Solution', fontsize=16)
plt.xlabel('Input Size P (Number of Bits)', fontsize=12)
plt.ylabel('Relative Computational Cost', fontsize=12)
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.tight_layout()

plt.show()