import matplotlib.pyplot as plt
import numpy as np
import matplotx

def time_complexity(n, k):
    return (n + k) * np.log2(n + 1)

n_values = np.arange(1000, 100001, 1000)
k_ratio = 0.5
k_values = n_values * k_ratio

times = time_complexity(n_values, k_values)

plt.style.use(matplotx.styles.onedark)
plt.figure(figsize=(10, 6))
plt.plot(n_values, times, label=f'k = {k_ratio} * n')
plt.xlabel('n (Number of stars)')
plt.ylabel('Estimated Time Complexity (arbitrary units)')
plt.title('Time Complexity O((n + k) log n)')
plt.legend()
plt.grid(True)
plt.show()

space = n_values

plt.figure(figsize=(10, 6))
plt.plot(n_values, space, label='Space Complexity O(n)')
plt.xlabel('n (Number of stars)')
plt.ylabel('Space Complexity (arbitrary units)')
plt.title('Space Complexity O(n)')
plt.legend()
plt.grid(True)
plt.show()
