import numpy as np
import matplotlib.pyplot as plt
import matplotx

n = np.logspace(2, 6, num=5, dtype=int)

time_ops = n
space_cells = np.full_like(n, 1)

plt.style.use(matplotx.styles.onedark)

fig, ax = plt.subplots()
ax.loglog(n, time_ops, marker="o", label="Time O(n)")
ax.loglog(n, space_cells, marker="s", label="Extra space O(1)")

ax.set_title("Time and Extra-Space Complexity of the Java algorithm")
ax.set_xlabel("Input size n")
ax.set_ylabel("Operations / Cells (log scale)")
ax.legend()
plt.tight_layout()
plt.show()