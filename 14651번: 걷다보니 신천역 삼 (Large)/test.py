import numpy as np
import matplotlib.pyplot as plt

def plot_complexity_analysis():
    n_values = np.logspace(1, np.log10(33333), 400)
    time_complexity = np.log2(n_values)
    space_complexity = np.ones_like(n_values)

    plt.style.use('dark_background')
    plt.rcParams.update({
        'figure.facecolor': '#2d2d2d',
        'axes.facecolor': '#2d2d2d',
        'text.color': '#f0f0f0',
        'axes.labelcolor': '#d0d0d0',
        'xtick.color': '#c0c0c0',
        'ytick.color': '#c0c0c0',
        'grid.color': '#4a4a4a',
        'font.family': 'sans-serif',
        'font.sans-serif': ['Apple SD Gothic Neo'],
    })

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 14))
    fig.suptitle('알고리즘 복잡도 분석: 걷다보니 신천역 삼 (Large)', fontsize=20, weight='bold', color='white')

    ax1.plot(n_values, time_complexity, color='#34c759', linewidth=2.5)
    ax1.set_title('시간 복잡도 (Time Complexity)', fontsize=16, color='white')
    ax1.set_xlabel('입력 크기 (N)', fontsize=12)
    ax1.set_ylabel('상대적 연산 횟수', fontsize=12)
    ax1.grid(True, linestyle='--', alpha=0.5)
    ax1.legend(['O(log N)'], loc='upper left', frameon=False, fontsize=12)
    ax1.set_xscale('log')
    ax1.text(n_values[50], time_complexity[-50], 'N이 커져도 연산 횟수는\n매우 완만하게 증가', fontsize=12, style='italic', color='#d0d0d0')

    ax2.plot(n_values, space_complexity, color='#ff9500', linewidth=2.5)
    ax2.set_title('공간 복잡도 (Space Complexity)', fontsize=16, color='white')
    ax2.set_xlabel('입력 크기 (N)', fontsize=12)
    ax2.set_ylabel('상대적 메모리 사용량', fontsize=12)
    ax2.grid(True, linestyle='--', alpha=0.5)
    ax2.set_ylim(0, 2)
    ax2.legend(['O(1)'], loc='upper left', frameon=False, fontsize=12)
    ax2.text(n_values[100], 1.2, '입력 크기(N)에 상관없이\n메모리 사용량은 항상 일정', fontsize=12, style='italic', color='#d0d0d0')
    plt.tight_layout(rect=[0, 0, 1, 0.96])
    plt.show()

if __name__ == '__main__':
    plot_complexity_analysis()