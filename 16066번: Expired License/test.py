import math
import matplotlib.pyplot as plt
import matplotx

plt.style.use(matplotx.styles.onedark)

def precompute_ops(limit: int) -> float:
    if limit < 3:
        return 0.0
    return limit * math.log(math.log(limit))

def total_ops(limit: int, t: int) -> float:
    return precompute_ops(limit) + t

def bits_to_mb(bits: int) -> float:
    return bits / 8 / (1024 ** 2)

limit_values = [int(x) for x in (1e4, 3e4, 1e5, 3e5, 1e6, 3e6, 1e7)]
t_values = [1, 10, 100, 1_000, 10_000]

fixed_t = 1_000
time_curve_limit = [total_ops(L, fixed_t) for L in limit_values]

plt.figure()
plt.plot(limit_values, time_curve_limit, marker='o')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('LIMIT')
plt.ylabel('Estimated operations')
plt.title(f'Time Complexity vs LIMIT (T = {fixed_t})')
plt.grid(True)

fixed_limit = 10_000_000
time_curve_t = [total_ops(fixed_limit, t) for t in t_values]

plt.figure()
plt.plot(t_values, time_curve_t, marker='s')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Number of test cases (T)')
plt.ylabel('Estimated operations')
plt.title(f'Time Complexity vs T (LIMIT = {fixed_limit})')
plt.grid(True)

space_curve = [bits_to_mb(L + 1) for L in limit_values]

plt.figure()
plt.plot(limit_values, space_curve, marker='^')
plt.xscale('log')
plt.xlabel('LIMIT')
plt.ylabel('Memory (MiB)')
plt.title('Space Complexity vs LIMIT')
plt.grid(True)

plt.show()