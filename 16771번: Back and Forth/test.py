import matplotlib.pyplot as plt
import numpy as np
import matplotx

D_values = np.arange(1, 11)

def calculate_nodes(D):
    level0 = 1
    level1 = D
    level2 = D * (D + 1)
    level3 = level2 * D
    level4 = level3 * (D + 1)
    total_nodes = sum([level0, level1, level2, level3, level4])
    return total_nodes

operations = [calculate_nodes(D) * 100 for D in D_values]

plt.style.use(matplotx.styles.onedark)
plt.plot(D_values, operations, marker='o', linestyle='-', color='b', label='Worst case Operations')
plt.title('Time Complexity: Operations vs. Distinct Bucket Sizes (D)')
plt.xlabel('Distinct Bucket Sizes per Barn (D)')
plt.ylabel('Approximate Total Operations')
plt.grid(True)
plt.legend()
plt.yscale('log')
plt.xticks(D_values)
plt.show()