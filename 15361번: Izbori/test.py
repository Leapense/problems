import math
import itertools
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter

n_values = range(1, 101, 5)
m_values = range(1, 16)

def time_complexity(n: int, m: int) -> float:
    return (2 ** (m - 1)) * n * m

def space_complexity(n: int, m: int) -> float:
    return n * m

def humanize(x: float, pos) -> str:
    units = ['', 'K', 'M', 'G', 'T']
    idx = 0
    while x >= 1000 and idx < len(units) - 1:
        x /= 1000.0
        idx += 1

    return f'{x:.1f}{units[idx]}'

formatter = FuncFormatter(humanize)

time_grid = np.zeros((len(n_values), len(m_values)))
space_grid = np.zeros((len(n_values), len(m_values)))

for i, n in enumerate(n_values):
    for j, m in enumerate(m_values):
        time_grid[i, j] = time_complexity(n, m)
        space_grid[i, j] = space_complexity(n, m)

plt.figure(figsize=(10, 6))
plt.title('Time complexity heat-map  $T = 2^{(M−1)}·N·M$')
plt.imshow(time_grid, origin='lower', aspect='auto',
           extent=[min(m_values), max(m_values), min(n_values), max(n_values)],
           cmap='viridis')
plt.colorbar(format=formatter, label='operations (log scale advisable)')
plt.xlabel('M  (candidates)')
plt.ylabel('N  (counties)')
plt.tight_layout()

plt.figure(figsize=(10, 6))
plt.title('Space complexity heat-map  $S = N·M$')
plt.imshow(space_grid, origin='lower', aspect='auto',
           extent=[min(m_values), max(m_values), min(n_values), max(n_values)],
           cmap='plasma')
plt.colorbar(format=formatter, label='cells')
plt.xlabel('M  (candidates)')
plt.ylabel('N  (counties)')
plt.tight_layout()

plt.figure(figsize=(10, 6))
for m in (1, 5, 10, 15):
    data = [time_complexity(n, m) for n in n_values]
    plt.plot(n_values, data, label=f'M={m}')
plt.gca().yaxis.set_major_formatter(formatter)
plt.title('Time complexity vs N  (multiple M lines)')
plt.xlabel('N  (counties)')
plt.ylabel('operations')
plt.legend()
plt.tight_layout()

plt.figure(figsize=(10, 6))
for n in (10, 50, 100):
    data = [time_complexity(n, m) for m in m_values]
    plt.plot(m_values, data, label=f'N={n}')
plt.gca().yaxis.set_major_formatter(formatter)
plt.title('Time complexity vs M  (multiple N lines)')
plt.xlabel('M  (candidates)')
plt.ylabel('operations')
plt.legend()
plt.tight_layout()

plt.show()