import numpy as np
import matplotlib.pyplot as plt
import matplotx

start, stop, step = 100, 2000, 100
bytes_per_int = 4

N = np.arange(start, stop + step, step)
M = N
ops = 3 * N * M
mem_mb = (N * M * bytes_per_int) / (1024 ** 2)

plt.style.use(matplotx.styles.onedark)
fig, ax1 = plt.subplots()
ax1.plot(N, ops, marker='o', label='Operations: 3*n*m')
ax1.set_xlabel('n (assuming m = n)')
ax1.set_ylabel('Operation count')
ax1.set_title('Time & Space Complexity of the C Program')

ax2 = ax1.twinx()
ax2.plot(N, mem_mb, 'r--', marker='x', label='Memory (MB)')
ax2.set_ylabel('Memory usage (MB)')

fig.legend(loc='upper left', bbox_to_anchor=(0.1, 0.9))
fig.tight_layout()
plt.show()