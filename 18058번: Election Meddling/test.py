import numpy as np
import matplotlib.pyplot as plt

try:
    import matplotx as mpt
    plt.style.use(mpt.styles.onedark)
except ImportError:
    plt.style.use("dark_background")

max_p = 100
ps = np.arange(1, max_p + 1)
V = 100

time_ops = ps + V * np.log(ps)
space_usage = ps + 1

plt.figure()
plt.plot(ps, time_ops, label="O(p + V·log p)")
plt.title("Time Complexity vs Number of Opponents (p)")
plt.xlabel("Number of Opponents (p)")
plt.ylabel("Approx. Operation Count")
plt.legend()
plt.tight_layout()

plt.figure()
plt.plot(ps, space_usage, label="O(p)", linestyle="--")
plt.title("Space Complexity vs Number of Opponents (p)")
plt.xlabel("Number of Opponents (p)")
plt.ylabel("Approx. Memory Units")
plt.legend()
plt.tight_layout()

plt.show()