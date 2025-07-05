import matplotlib.pyplot as plt

# Define input sizes
ns = list(range(1, 101))

# Time and space complexity values (O(1) = constant)
time_values = [1] * len(ns)
space_values = [1] * len(ns)

# Plot time complexity
plt.figure()
plt.plot(ns, time_values)
plt.title('Time Complexity: O(1)')
plt.xlabel('Input Size (n)')
plt.ylabel('Operations')
plt.grid(True)

# Plot space complexity
plt.figure()
plt.plot(ns, space_values)
plt.title('Space Complexity: O(1)')
plt.xlabel('Input Size (n)')
plt.ylabel('Memory Units')
plt.grid(True)

plt.show()
