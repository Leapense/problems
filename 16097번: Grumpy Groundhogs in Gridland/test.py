import matplotlib.pyplot as plt
import matplotx
import numpy as np

n = np.linspace(1, 1000, 1000)

time_complexity = n * np.log2(n)
space_complexity = n

plt.style.use(matplotx.styles.onedark)

plt.figure()
plt.plot(n, time_complexity)
plt.title('Time Complexity: O(n log n)')
plt.xlabel('Input Size (n)')
plt.ylabel('Operation ~ n log n')
plt.grid(True)
plt.show()

plt.figure()
plt.plot(n, space_complexity)
plt.title('Space Complexity: O(n)')
plt.xlabel('Input Size (n)')
plt.ylabel('Memory ~ n')
plt.grid(True)
plt.show()