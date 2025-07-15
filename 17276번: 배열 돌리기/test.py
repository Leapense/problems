import matplotlib.pyplot as plt
import matplotx

def plot_complexity(max_n: int = 2000, step: int = 100) -> None:
    ns = list(range(1, max_n + 1, step))
    algo_time = [n for n in ns]
    io_time = [n ** 2 for n in ns]

    plt.style.use(matplotx.styles.onedark)
    fig, ax = plt.subplots()
    ax.plot(ns, algo_time, marker='o', label='Rotation algorithm O(n)')
    ax.plot(ns, io_time, marker='s', label='I/O & memory O(n^2)')
    ax.set_xlabel('n   (matrix dimension)')
    ax.set_ylabel('Operations (arb. units)')
    ax.set_title('Time & Space Complexity of the Rotation Program')
    ax.legend()
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    plot_complexity()