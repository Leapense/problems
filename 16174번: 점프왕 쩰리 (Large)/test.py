import numpy as np
import matplotlib.pyplot as plt
import matplotx

Ns = np.arange(10, 510, 10)

times = Ns ** 2
spaces = Ns ** 2

plt.style.use(matplotx.styles.onedark)

plt.figure()
plt.plot(Ns, times,  label='Time  T(N) = Θ(N²)')
plt.plot(Ns, spaces, label='Space S(N) = Θ(N²)', linestyle='--')

plt.yscale('log')
plt.xlabel('Board size N')
plt.ylabel('Asymptotic cost (log scale)')
plt.title('Time and Space Complexity of BFS in Jumping Jelly')
plt.legend()
plt.grid(True, which='both', ls=':')
plt.tight_layout()
plt.show()