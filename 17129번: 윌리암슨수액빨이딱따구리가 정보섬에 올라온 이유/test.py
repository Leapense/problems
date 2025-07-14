import matplotlib.pyplot as plt
import matplotx
import numpy as np

def plot_complexity():
    with plt.style.context(matplotx.styles.onedark):
        n_values = np.linspace(10, 1000, 100)
        complexity_values = n_values * n_values
        fig, ax = plt.subplots(figsize=(10, 6))
        ax.plot(n_values, complexity_values, label='O(N * M) or O(N²)', linewidth=2.5)
        ax.set_title('Time/Space Complexity Analysis: O(N * M)', fontsize=16)
        ax.set_xlabel('Input Size (N, for an N x N grid)', fontsize=12)
        ax.set_ylabel('Number of Operations (Proportional)', fontsize=12)
        ax.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
        ax.legend()
        ax.grid(True, which='both', linestyle='--', linewidth=0.5)
        plt.tight_layout()
        plt.show()

if __name__ == '__main__':
    try:
        import matplotx
    except ImportError:
        print("matplotx 라이브러리가 설치되지 않았습니다.")
        print("설치 명령어: pip install matplotx")
    else:
        plot_complexity()