import numpy as np
import matplotlib.pyplot as plt
import matplotx as mplt

plt.style.use(mplt.styles.onedark)

N = np.linspace(1, 1000, 1000)

time_complexity = N
space_complexity = N

plt.figure(figsize=(8,5))
plt.plot(N, time_complexity, label="Time Complexity: O(N)")
plt.plot(N, space_complexity, label="Space Complexity: O(N)", linestyle="--")
plt.xlabel("Input Size N")
plt.ylabel("Relative Cost")
plt.title("Time and Space Complexity Analysis")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()