import numpy as np
import matplotlib.pyplot as plt

max_n = 500_000
points = 1_000
n = np.linspace(1, max_n, points)

time_complexity = n
space_complexity = n

plt.figure()
plt.plot(n, time_complexity)
plt.title("Time Complexity O(N)")
plt.xlabel("N (number of vertices)")
plt.ylabel("Operations (arbitrary units)")
plt.grid(True)

plt.figure()
plt.plot(n, space_complexity)
plt.title("Space Complexity O(N)")
plt.xlabel("N (number of vertices)")
plt.ylabel("Memory (arbitrary units)")
plt.grid(True)

plt.show()