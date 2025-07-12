import matplotlib.pyplot as plt
import numpy as np

n = np.arange(1, 101)

time_complexity = n ** 2
space_complexity = n ** 2

plt.figure()
plt.plot(n, time_complexity)
plt.title('Worst-case Time Complexity: O(n^2)')
plt.xlabel('n')
plt.ylabel('Operations')
plt.grid(True)
plt.show()

plt.figure()
plt.plot(n, space_complexity)
plt.title('Worst-case Space Complexity: O(n^2)')
plt.xlabel('n')
plt.ylabel('Memory Units')
plt.grid(True)
plt.show()