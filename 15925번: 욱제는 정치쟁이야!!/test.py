import matplotlib.pyplot as plt
import numpy as np

ns = np.arange(10, 210, 10)

time_complexity = ns ** 3
space_complexity = ns ** 2

plt.figure()
plt.plot(ns, time_complexity, label='Time Complexity (O(n^3))')
plt.plot(ns, space_complexity, label='Space Complexity (O(n^2))')
plt.xlabel('n (Grid Dimension)')
plt.ylabel('Operations / Memory Units')
plt.title('Time and Space Complexity of the Java Algorithm')
plt.legend()
plt.tight_layout()
plt.show()