import matplotlib.pyplot as plt
import matplotx
import numpy as np

n = np.arange(1, 501)
m = n

t_prefix = n
t_queries = m * np.log2(n)
t_total = t_prefix + t_queries

plt.style.use(matplotx.styles.onedark)

plt.figure()
plt.plot(n, t_prefix, label='Prefix sum: O(n)')
plt.plot(n, t_queries, label='Queries: O(m log n)')
plt.plot(n, t_total, label='Total: O(n + m log n)')
plt.xlabel('n (with m = n)')
plt.ylabel('Operations (≈)')
plt.legend()
plt.title('Time Complexity of the Java Program')
plt.show()

s_space = n

plt.figure()
plt.plot(n, s_space, label='Space: O(n)')
plt.xlabel('n')
plt.ylabel('Memory Units (≈)')
plt.legend()
plt.title('Space Complexity of the Java Program')
plt.show()