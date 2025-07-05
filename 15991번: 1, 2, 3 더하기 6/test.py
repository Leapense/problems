import numpy as np
import matplotlib.pyplot as plt

n = np.arange(1, 1001)

time_complexity = n
space_complexity = n

plt.figure()
plt.plot(n, time_complexity, label='Time Complexity: O(n)')
plt.plot(n, space_complexity, label='Space Complexity: O(n)')
plt.xlabel('Input Size n')
plt.ylabel('Operations / Memory Units')
plt.title('Time / Space Complexity Graph')
plt.legend()
plt.grid(True)
plt.show()