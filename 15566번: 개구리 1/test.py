import math
import matplotlib.pyplot as plt
import numpy as np

def time_complexity(n):
    return n * (1 << n)

def space_complexity(n):
    return n * n

n_values = np.arange(1, 16)
time_values = np.array([time_complexity(n) for n in n_values], dtype=float)
space_values = np.array([space_complexity(n) for n in n_values], dtype=float)

fig, (ax_time, ax_space) = plt.subplots(1, 2, figsize=(12, 4))

ax_time.plot(n_values, time_values, marker='o', color='royalblue')
ax_time.set_yscale('log')
ax_time.set_xlabel('N (frogs / lilies)')
ax_time.set_ylabel('operations (log scale)')
ax_time.set_title('Time Complexity:  N · 2^N')

ax_space.plot(n_values, space_values, marker='s', color='darkorange')
ax_space.set_xlabel('N (frogs / lilies)')
ax_space.set_ylabel('memory units')
ax_space.set_title('Space Complexity:  Θ(N²)')

fig.suptitle('Complexity Growth of the Frog-Placement Algorithm', fontsize=14, fontweight='bold')
fig.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.show()
