import numpy as np
import matplotlib.pyplot as plt

try:
    import matplotx as mptx
    plt.style.use(mptx.styles.onedark)
except ImportError:
    plt.style.use('dark_background')
    print("matplotx not found. Proceeding with default Matplotlib style.")

n = np.arange(0, 1000, 10)

time_complexity = n
space_complexity = n

plt.figure()
plt.plot(n, time_complexity, label='Time Complexity O(n)')
plt.plot(n, space_complexity, label='Space Complexity O(n)')
plt.xlabel('Input Size (N)')
plt.ylabel('Operations / Memory Units')
plt.title('Time and Space Complexity (Linear)')
plt.legend()
plt.tight_layout()
plt.show()