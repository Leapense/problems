import matplotlib.pyplot as plt
import numpy as np
import matplotx

m_values = np.linspace(1, 10000, 100)
time_complexity = m_values
space_complexity = m_values

plt.style.use(matplotx.styles.onedark)
plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(m_values, time_complexity, label="Time Complexity")
plt.title("Time Complexity vs Number of Mowers")
plt.xlabel("Number of Mowers (m)")
plt.ylabel("Operations")
plt.legend()
plt.grid(True)

plt.subplot(1, 2, 2)
plt.plot(m_values, space_complexity, label="Space Complexity")
plt.title("Space Complexity vs Number of Mowers")
plt.xlabel("Number of Mowers (m)")
plt.ylabel("Memory Units")
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()