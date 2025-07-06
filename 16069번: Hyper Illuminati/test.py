import matplotlib.pyplot as plt
import matplotx
import numpy as np

plt.style.use(matplotx.styles.onedark)

def estimate_operations(m, n=3):
    return int(m**(1/(n-1)))

ms = np.logspace(2, 8, num=30)
ops = [estimate_operations(m, n=3) for m in ms]

plt.figure(figsize=(8,5))
plt.plot(ms, ops, marker='o')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Input m')
plt.ylabel('Operations (s candidates, n=3)')
plt.title('Time Complexity for n=3: O(sqrt(m))')
plt.grid(True, which='both', ls='--')
plt.show()

ms = np.logspace(2, 8, num=30)
for n in [3, 4, 5, 6]:
    ops = [int(m**(1/(n-1))) for m in ms]
    plt.plot(ms, ops, label=f"n={n}")

plt.xscale('log')
plt.yscale('log')
plt.xlabel('Input m')
plt.ylabel('Max s to check')
plt.title('Time Complexity vs m for Various n')
plt.legend()
plt.grid(True, which='both', ls='--')
plt.show()