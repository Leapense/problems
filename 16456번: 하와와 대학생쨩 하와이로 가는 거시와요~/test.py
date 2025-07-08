import matplotlib.pyplot as plt
import numpy as np
import matplotx

n = np.arange(1, 1001)

time_complexity = n
space_complexity = n

plt.style.use(matplotx.styles.onedark)

plt.figure()
plt.plot(n, time_complexity)
plt.title('Time complexity: O(n)')
plt.xlabel('Input Size n')
plt.ylabel('Operations')
plt.grid(True)

plt.figure()
plt.plot(n, space_complexity)
plt.title('Space complexity: O(n)')
plt.xlabel('Input Size n')
plt.ylabel('Memory Usage')
plt.grid(True)

plt.show()