import matplotlib.pyplot as plt
import matplotx
import numpy as np

N = np.arange(1, 1001)
time_build = N ** 2
time_queries = N
time_total = time_build + time_queries

plt.style.use(matplotx.styles.onedark)
plt.figure()
plt.plot(N, time_build, label='Build Prefix Sum (O(N²))')
plt.plot(N, time_queries, label='Queries (O(Q), Q=N)')
plt.plot(N, time_total, label='Total (O(N² + N))')
plt.title('Time Complexity')
plt.xlabel('N (rows = columns)')
plt.ylabel('Operation Count')
plt.legend()
plt.show()

plt.figure()
plt.plot(N, N ** 2)
plt.title('Space Complexity (O(N²))')
plt.xlabel('N (rows = columns)')
plt.ylabel('Memory Cells Allocated')
plt.show()
