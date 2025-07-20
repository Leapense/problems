import matplotlib.pyplot as plt
import matplotx as mptx

plt.style.use(mptx.styles.onedark)

ns = [100, 200, 500, 1000, 2000, 5000, 10000]

time_complexity = [n for n in ns]
space_complexity = [n for n in ns]

plt.figure(figsize=(8,5))
plt.plot(ns, time_complexity, marker='o', label='Time Complexity $O(n)$')
plt.plot(ns, space_complexity, marker='s', label='Space Complexity $O(n)$')

plt.xlabel("Input Size $n$")
plt.ylabel("Cost (operations or memory units)")
plt.title("Time & Space Complexity of the Given Algorithm")
plt.legend()
plt.tight_layout()
plt.show()