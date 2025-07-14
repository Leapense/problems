import matplotlib.pyplot as plt
import matplotx
import numpy as np

def plot_complexity():
    with plt.style.context(matplotx.styles.onedark):
        n_values = np.linspace(10, 2000, 200)
        time_complexity = n_values ** 2
        space_complexity = n_values
        fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 12))
        ax1.plot(n_values, time_complexity, label='O(n^2)', linewidth=2.5, color='orangered')
        ax1.set_title('Time Complexity Analysis', fontsize=16)
        ax1.set_xlabel('Number of Stations (n)', fontsize=12)
        ax1.set_ylabel('Number of Operations (Proportional)', fontsize=12)
        ax1.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
        ax1.legend()
        ax1.grid(True, which='both', linestyle='--', linewidth=0.5)

        ax2.plot(n_values, space_complexity, label='O(n)', linewidth=2.5, color='dodgerblue')
        ax2.set_title('Space Complexity Analysis', fontsize=16)
        ax2.set_xlabel('Number of Stations (n)', fontsize=12)
        ax2.set_ylabel('Memory Usage (Proportional)', fontsize=12)
        ax2.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
        ax2.legend()
        ax2.grid(True, which='both', linestyle='--', linewidth=0.5)

        fig.suptitle('Complexity Analysis for Sink Station Finder', fontsize=20, y=1.02)
        plt.tight_layout(rect=[0, 0, 1, 0.98])
        plt.show()

if __name__ == '__main__':
    try:
        import matplotx
    except ImportError:
        print("matplotx 라이브러리가 설치되지 않았습니다.")
        print("설치 명령어: pip install matplotx")
    else:
        plot_complexity()