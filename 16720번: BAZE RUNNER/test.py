import matplotlib.pyplot as plt
import matplotx

n_values = list(range(0, 1001, 10))
time_complexity = [n for n in n_values]
space_complexity = [n for n in n_values]

plt.style.use(matplotx.styles.onedark)
plt.figure()
plt.plot(n_values, time_complexity)
plt.title("Time Complexity: O(n)")
plt.xlabel("n (number of rows)")
plt.ylabel("Operations")
plt.grid(True)
plt.show()

plt.figure()
plt.plot(n_values, space_complexity)
plt.title("Space Complexity: O(n)")
plt.xlabel("n (number of rows)")
plt.ylabel("Space (units)")
plt.grid(True)
plt.show()