import matplotlib.pyplot as plt

n_values = list(range(100, 2001, 100))
m_fixed = 500

time_nm = [n * m_fixed for n in n_values]
time_n2 = [n * n for n in n_values]
time_linear = [n for n in n_values]

space_linear = [n for n in n_values]

plt.figure()
plt.plot(n_values, time_nm, label="O(n * m), m=500")
plt.plot(n_values, time_n2, label="O(n^2)")
plt.plot(n_values, time_linear, label="O(n)")
plt.xlabel("n (prefectures)")
plt.ylabel("Operation Count")
plt.title("Time Complexity Comparison")
plt.legend()
plt.tight_layout()
plt.show()

plt.figure()
plt.plot(n_values, space_linear, label="O(n)")
plt.xlabel("n (prefectures)")
plt.ylabel("Memory Units")
plt.title("Space Complexity")
plt.legend()
plt.tight_layout()
plt.show()