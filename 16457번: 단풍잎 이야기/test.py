import matplotlib.pyplot as plt
import math
import matplotx

m = 50
k = 5
n_values = list(range(1, 11))

time_complexity = [math.comb(2 * n, n) * m * k for n in n_values]
space_complexity = [m * k + n for n in n_values]

plt.style.use(matplotx.styles.onedark)

plt.figure()
plt.plot(n_values, time_complexity)
plt.xlabel('n (number of skills chosen)')
plt.ylabel('Operations ~ C(2n, n) × m × k')
plt.title('Theoretical Time Complexity')
plt.grid(True)
plt.show()

plt.figure()
plt.plot(n_values, space_complexity)
plt.xlabel('n (number of skills chosen)')
plt.ylabel('Memory ~ m × k + n')
plt.title('Theoretical Space Complexity')
plt.grid(True)
plt.show()
