import matplotlib.pyplot as plt
import matplotx as mptx

plt.style.use(mptx.styles.onedark)

n = list(range(1, 11))

time_complexity = [i * 2 ** i for i in n]
space_complexity = [i + f for i, f in zip(n, n)]

plt.figure()
plt.plot(n, time_complexity)
plt.title('Time Complexity: O(n * 2^n)')
plt.xlabel('n (num_datasets)')
plt.ylabel('Operations Count')
plt.grid(True)
plt.show()

plt.figure()
plt.plot(n, space_complexity)
plt.title('Space Complexity: O(n + f)')
plt.xlabel('n (num_datasets)')
plt.ylabel('Memory usage units')
plt.grid(True)
plt.show()