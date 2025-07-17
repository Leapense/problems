import numpy as np
import matplotlib.pyplot as plt
import matplotx as mptx

plt.style.use(mptx.styles.onedark)

n = np.arange(1, 1001)
time_complexity = n
space_complexity = np.ones_like(n)

plt.figure()
plt.plot(n, time_complexity, label='Time Complexity O(n)')
plt.plot(n, space_complexity, label='Space Complexity O(1)')
plt.xlabel('Input Size n')
plt.ylabel('Operations / Memory Units')
plt.title('Time and Space Complexity Analysis')
plt.legend()
plt.tight_layout()
plt.show()