import math
import matplotlib.pyplot as plt
import matplotx

ns = list(range(10, 10001, 1000))

time_complexity = [n * math.log(math.log(n)) for n in ns]
space_complexity = [n for n in ns]

plt.style.use(matplotx.styles.onedark)
plt.figure()
plt.plot(ns, time_complexity)
plt.xlabel('n')
plt.ylabel('T(n) ~ n log log n')
plt.title('Time Complexity vs n')
plt.show()

plt.figure()
plt.plot(ns, space_complexity)
plt.xlabel('n')
plt.ylabel('S(n) ~ n')
plt.title('Space Complexity vs n')
plt.show()