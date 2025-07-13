import matplotlib.pyplot as plt

try:
    import matplotx as mpt
    plt.style.use(mpt.styles.onedark)
except ImportError:
    print("Warning: matplotx not found. Proceeding with default Matplotlib style.")

N = list(range(1000, 10001, 1000))
time_complexity = [n for n in N]
space_complexity = [n for n in N]

plt.figure()
plt.plot(N, time_complexity, label='Time O(h*w)')
plt.plot(N, space_complexity, label='Space O(h*w)')
plt.xlabel('Input Size (h*w)')
plt.ylabel('Relative Cost')
plt.title('Time and Space Complexity of the Given Algorithm')
plt.legend()
plt.tight_layout()
plt.show()