import matplotlib.pyplot as plt
import matplotx
import numpy as np

def plot_complexity():
    with plt.style.context(matplotx.styles.onedark):
        input_size = np.linspace(1000, 1_000_000, 200)
        complexity_values = input_size
        fig, ax = plt.subplots(figsize=(10, 7))
        ax.plot(input_size, complexity_values, label='O((n + m) * α(n)) (Near-Linear)', linewidth=2.5)
        ax.set_title('Time Complexity Analysis: DSU with Path Compression', fontsize=16)
        ax.set_xlabel('Input Size (n + m)', fontsize=12)
        ax.set_ylabel('Number of Operations (Proportional)', fontsize=12)
        ax.ticklabel_format(style='sci', axis='y', scilimits=(0, 0))
        ax.legend(fontsize=11)
        ax.grid(True, which='both', linestyle='--', linewidth=0.5)
        text_content = (
            "The complexity is O((n + m) * α(n)), where α(n) is the Inverse Ackermann function.\n"
            "Since α(n) is a very slowly growing function (α(n) < 5 for all practical inputs),\n"
            "the overall complexity is quasi-linear and behaves almost identically to O(n + m)."
        )
        ax.text(0.05, 0.75, text_content, transform=ax.transAxes, fontsize=10, verticalalignment='top',
                bbox=dict(boxstyle='round,pad=0.5', fc='gray', alpha=0.2))

        plt.tight_layout()
        plt.show()

if __name__ == "__main__":
    try:
        import matplotx
    except ImportError:
        print("matplotx 라이브러리가 설치되지 않았습니다.")
        print("설치 명령어: pip install matplotx")
    else:
        plot_complexity()