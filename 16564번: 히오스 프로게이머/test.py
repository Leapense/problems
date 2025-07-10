import numpy as np
import matplotlib.pyplot as plt
import matplotx

# Define a range of n values
n_values = np.linspace(100, 10000, 100)

# Compute complexity functions
time_n_log_n = n_values * np.log2(n_values)
space_n = n_values

plt.style.use(matplotx.styles.onedark)
plt.figure()
plt.plot(n_values, time_n_log_n, label='Time: O(n log n)')
plt.plot(n_values, space_n, label='Space: O(n)')
plt.xlabel('n (number of characters)')
plt.ylabel('Operation Count / Memory Size')
plt.title('Time vs Space Complexity')
plt.legend()
plt.grid(True)
plt.show()

