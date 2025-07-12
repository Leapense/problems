import math
import matplotlib.pyplot as plt

n_vals = list(range(1, 21))

time_ops = [(2**n) * (n**2) for n in n_vals]
space_ops = [n**2 for n in n_vals]

plt.figure()
plt.plot(n_vals, time_ops, marker="o")
plt.xlabel("n")
plt.ylabel("Estimated Operation Count")
plt.title("Theoretical Time Complexity: O(2^n * n^2)")
plt.grid(True)
plt.show()

plt.figure()
plt.plot(n_vals, space_ops, marker="o")
plt.xlabel("n")
plt.ylabel("Estimated Memory Units")
plt.title("Theoretical Space Complexity: O(n^2)")
plt.grid(True)
plt.show()