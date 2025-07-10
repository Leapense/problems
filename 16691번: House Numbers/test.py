import math
import matplotlib.pyplot as plt
import matplotx

def iterations(m: int) -> int:
    a = (m - 1) * m // 2
    x = m + 1
    steps = 0
    while True:
        rhs = x * x - a
        if rhs > 0:
            root = math.isqrt(8 * rhs + 1)
            n = (root - 1) // 2
            if n >= x + 1 and n * (n + 1) // 2 == rhs:
                return steps + 1

        x += 1
        steps += 1

MAX_M = 400
ms = list(range(2, MAX_M + 1))
iters = [iterations(m) for m in ms]

plt.style.use(matplotx.styles.onedark)
plt.plot(ms, iters, marker='.', linestyle='none')
plt.xlabel('m')
plt.ylabel('Iterations (steps)')
plt.title(f"Number of Iterations vs m (2 <= m <= {MAX_M})")
plt.grid(True)
plt.show()