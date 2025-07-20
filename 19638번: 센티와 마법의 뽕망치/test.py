import numpy as np
import matplotlib.pyplot as plt

try:
    import matplotx as mplt
    plt.style.use(mplt.styles.onedark)
except ImportError:
    plt.style.use('dark_background')

def time_complexity(N, T=None):
    if T is None:
        T = N
    return N + T * np.log2(N + T)

def space_complexity(N, T = None):
    if T is None:
        T = N
    return N + T

Ns = np.linspace(1_000, 100_000, 200)
Ts = Ns

times = time_complexity(Ns, Ts)
spaces = space_complexity(Ns, Ts)

plt.figure()
plt.plot(Ns, times, label='O(N + T·log₂(N+T)) (T=N)')
plt.plot(Ns, Ns * np.log2(2*Ns), linestyle='--', label='O(N·log₂N)')
plt.xlabel('N')
plt.ylabel('Operation Count')
plt.title('Time Complexity')
plt.legend()
plt.tight_layout()
plt.show()

plt.figure()
plt.plot(Ns, spaces, label='O(N + T) (T=N)')
plt.plot(Ns, 2*Ns, linestyle='--', label='O(2N)')
plt.xlabel('N')
plt.ylabel('Memory Footprint')
plt.title('Space Complexity')
plt.legend()
plt.tight_layout()
plt.show()