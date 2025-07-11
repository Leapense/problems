import matplotlib.pyplot as plt
import numpy as np
import matplotx

n_values = np.array([10, 100, 1000, 10000, 100000, 1000000])

time_complexity = np.log2(n_values)
space_complexity = np.ones_like(n_values)

plt.style.use(matplotx.styles.onedark)
plt.figure()
plt.plot(n_values, time_complexity, marker='o')
plt.xlabel('n')
plt.ylabel('Operations ~ log2(n)')
plt.title('Time Complexity: O(log n)')
plt.xscale('log')
plt.show()

plt.figure()
plt.plot(n_values, space_complexity, marker='o')
plt.xlabel('n')
plt.ylabel('Memory Units')
plt.title('Space Complexity: O(1)')
plt.xscale('log')
plt.show()