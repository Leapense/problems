import matplotlib.pyplot as plt
import matplotx
import numpy as np

n = np.linspace(1, 1000, 1000)

time_n_log_n = n * np.log2(n)
time_n = n
space_n = n

plt.style.use(matplotx.styles.onedark)

plt.figure()
plt.plot(n, time_n_log_n, label='O(n log n)')
plt.plot(n, time_n, label='O(n)')
plt.title('Time Complexity')
plt.xlabel('Input size n')
plt.ylabel('Operations')
plt.legend()
plt.grid(True)
plt.show()

plt.figure()
plt.plot(n, space_n, label='O(n)')
plt.title('Space Complexity')
plt.xlabel('Input size n')
plt.ylabel('Memory Usage')
plt.legend()
plt.grid(True)
plt.show()