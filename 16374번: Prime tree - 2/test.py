import numpy as np
import matplotlib.pyplot as plt
import matplotx

n = np.linspace(0, 20000, 500)
time_complexity = n
space_complexity = n

plt.style.use(matplotx.styles.onedark)
plt.figure()
plt.plot(n, time_complexity, label="Time complexity")
plt.plot(n, space_complexity, label="Space complexity")
plt.xlabel('Input size n')
plt.ylabel('Operations / Memory Units')
plt.title('Time / Space Complexity')
plt.legend()
plt.grid(True)
plt.show()