import numpy as np
import matplotlib.pyplot as plt
import matplotx as mpt

plt.style.use(mpt.styles.onedark)

T = 100
maxN = 10000

N = np.linspace(100, maxN, 200)
f_sieve = N * np.log(np.log(N))
f_query = T * N

plt.figure(figsize=(8, 5))
plt.plot(N, f_sieve, label=r'$O(N \log\log N)$')
plt.plot(N, f_query, label=r'$O(T \cdot N)$', linestyle='--')
plt.xlabel('N')
plt.ylabel('Operations (arbitrary units)')
plt.title('Time Complexity Comparison')
plt.legend()
plt.tight_layout()
plt.show()

plt.figure(figsize=(8, 5))
g_queries = np.full_like(N, T)
g_prime = N
plt.plot(N, g_queries, label=r'$O(T)$')
plt.plot(N, g_prime, label=r'$O(N)$', linestyle='--')
plt.xlabel('N')
plt.ylabel('Memory Units (arbitrary units)')
plt.title('Space Complexity Comparison')
plt.legend()
plt.tight_layout()
plt.show()