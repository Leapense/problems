import numpy as np
import matplotlib.pyplot as plt
import matplotx

plt.style.use(matplotx.styles.onedark)

Ns = np.logspace(3, 6, num=100)
time_ops = Ns
space_usage = Ns

fig_time, ax_time = plt.subplots()
ax_time.plot(Ns, time_ops, label='Time O(n)')
ax_time.set_xlabel('Input size n')
ax_time.set_ylabel('Operations (arb. units)')
ax_time.set_title('Java Algorithm\nTime Complexity', loc='left')
ax_time.legend()

fig_space, ax_space = plt.subplots()
ax_space.plot(Ns, space_usage, label='Space O(n)')
ax_space.set_xlabel('Input size n')
ax_space.set_ylabel('Memory units (arb.)')
ax_space.set_title('Java Algorithm\nSpace Complexity', loc='left')
ax_space.legend()

plt.show()