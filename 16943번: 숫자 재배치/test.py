import matplotlib.pyplot as plt
import numpy as np
import math

try:
    import matplotx as mpx
    plt.style.use(mpx.styles.onedark)
except ImportError:
    plt.style.use('dark_background')

n_values = np.arange(1, 8)
t_sort = n_values * np.log2(n_values)
t_compare = n_values
t_permutation = [n * math.factorial(n) for n in n_values]

s_linear = n_values

plt.figure(figsize=(10, 6))
plt.plot(n_values, t_sort, marker='o', label='O(n log n)')
plt.plot(n_values, t_compare, marker='s', label='O(n)')
plt.plot(n_values, t_permutation, marker='^', label='O(n * n!)')
plt.xlabel('Input Size (n)')
plt.ylabel('Operations')
plt.title('Time Complexity of the C++ Algorithm')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

plt.figure(figsize=(10, 6))
plt.plot(n_values, s_linear, marker='o', label='O(n)')
plt.xlabel('Input Size (n)')
plt.ylabel('Memory Usage (units)')
plt.title('Space Complexity of the C++ Algorithm')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
