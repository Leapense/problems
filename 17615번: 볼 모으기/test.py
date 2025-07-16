import matplotlib.pyplot as plt
import matplotx as mptx

plt.style.use(mptx.styles.onedark)

n = list(range(0, 101))

time_complexity = n
space_complexity = [1] * len(n)

plt.figure()
plt.plot(n, time_complexity, label='Time Complexity $O(n)$')
plt.plot(n, space_complexity, label='Space Complexity $O(1)$')
plt.xlabel('Input Size $n$')
plt.ylabel('Operations / Auxiliary Space')
plt.title('Time and Space Complexity of the Algorithm')
plt.legend()
plt.tight_layout()
plt.show()