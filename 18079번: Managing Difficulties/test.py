import matplotlib.pyplot as plt
import numpy as np
import matplotx

plt.style.use(matplotx.styles.onedark)

def time_complexity(n):
    return n * (n - 1) / 2

def space_complexity(n):
    return n

n_values = np.arange(1, 1001, 10)
time_values = [time_complexity(n) for n in n_values]
space_values = [space_complexity(n) for n in n_values]

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

ax1.plot(n_values, time_values, linewidth=2.5)
ax1.scatter(n_values[::5], time_values[::5], s=30)
ax1.set_xlabel('Input Size (n)', fontsize=12)
ax1.set_ylabel('Time Complexity (operations)', fontsize=12)
ax1.set_title('Time Complexity: O(n^2)', fontsize=14, fontweight='bold')
ax1.grid(True, alpha=0.3)
ax1.set_xlim(0, 1000)
ax1.set_ylim(0, max(time_values)*1.1)

ax2.plot(n_values, space_values, linewidth=2.5)
ax2.scatter(n_values[::5], space_values[::5], s=30)
ax2.set_xlabel('Input Size (n)', fontsize=12)
ax2.set_ylabel('Space Complexity (elements)', fontsize=12)
ax2.set_title('Space Complexity: O(n)', fontsize=14, fontweight='bold')
ax2.grid(True, alpha=0.3)
ax2.set_xlim(0, 1000)
ax2.set_ylim(0, max(space_values)*1.1)

plt.tight_layout()
plt.show()