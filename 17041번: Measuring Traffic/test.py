import matplotlib.pyplot as plt
import matplotx as mptx

plt.style.use(mptx.styles.onedark)

N = list(range(1, 101))

time_complexity = [n for n in N]
space_complexity = [n for n in N]

plt.figure()
plt.plot(N, time_complexity, label='Time Complexity O(N)')
plt.plot(N, space_complexity, label='Space Complexity O(N)')
plt.xlabel('Segment Count (N)')
plt.ylabel('Operations / Memory Units')
plt.title('Time / Space Complexity')
plt.legend()
plt.tight_layout()
plt.show()