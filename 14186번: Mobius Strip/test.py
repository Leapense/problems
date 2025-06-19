import numpy as np
import matplotlib.pyplot as plt

def plot_complexity_analysis():
    try:
        plt.rcParams['font.family'] = 'Apple SD Gothic Neo'
    except:
        print("Font not found")
    
    plt.rcParams['axes.unicode_minus'] = False
    N = np.linspace(1, 1000, 400)
    time_complexity = N
    SPACE_CONSTANT = 414
    space_complexity = np.full_like(N, SPACE_CONSTANT)

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
    fig.suptitle('뫼비우스 띠 문제 알고리즘 복잡도 분석', fontsize=16)

    ax1.plot(N, time_complexity, label='시간 복잡도 O(N)', color='royalblue', linewidth=2)
    ax1.set_title('시간 복잡도 (Time Complexity)')
    ax1.set_xlabel('입력 크기 (N = 총 띠의 개수)')
    ax1.set_ylabel('추정 연산 횟수')
    ax1.legend()
    ax1.grid(True, linestyle='--', alpha=0.6)
    ax1.text(0.5, 0.4,
             '입력 데이터(N)이 증가함에 따라\n연산량이 선형적으로 증가합니다.\n(주요 원인: 입력 루프)',
             horizontalalignment='center',
             verticalalignment='center',
             transform=ax1.transAxes,
             fontsize=10,
             bbox=dict(boxstyle="round,pad=0.5", fc='wheat', alpha=0.5))
    
    ax2.plot(N, space_complexity, label='공간 복잡도 O(1)', color='crimson', linewidth=2)
    ax2.set_title('공간 복잡도 (Space Complexity)')
    ax2.set_xlabel('입력 크기 (N = 총 띠의 개수)')
    ax2.set_ylabel('사용 메모리 (단위)')
    ax2.set_ylim(0, SPACE_CONSTANT * 1.5)
    ax2.legend()
    ax2.grid(True, linestyle='--', alpha=0.6)
    ax2.text(0.5, 0.6,
             '입력 데이터(N)가 아무리 커져도\n메모리 사용량은 일정합니다.\n(원인: 고정 크기 배열 사용)',
             horizontalalignment='center',
             verticalalignment='center',
             transform=ax2.transAxes,
             fontsize=10,
             bbox=dict(boxstyle="round,pad=0.5", fc='wheat', alpha=0.5))
    
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.show()

if __name__ == "__main__":
    plot_complexity_analysis()