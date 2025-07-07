import math
import matplotlib.pyplot as plt
import matplotx

ns = list(range(2, 13))
fact = [math.factorial(n - 2) for n in ns]
n_fact = [n * f for n, f in zip(ns, fact)]

plt.style.use(matplotx.styles.onedark)
plt.figure()
plt.plot(ns, fact, label='(n-2)!')
plt.plot(ns, n_fact, label='n * (n-2)!')
plt.yscale('log')
plt.xlabel('n (number of beads)')
plt.ylabel('Estimated operations (log scale)')
plt.title('Growth of Time Complexity for gather() Algorithm')
plt.legend()
plt.grid(True)
plt.show()