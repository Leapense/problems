import numpy as np
import matplotlib.pyplot as plt
import matplotx

def plot_complexity_analysis():
    plt.rcParams['font.family'] = 'Apple SD Gothic Neo'
    plt.style.use(matplotx.styles.onedark)
    n_values = np.linspace(1, 300, 100)
    time_values = n_values ** 3
    space_values = n_values ** 2

    fig, ax1 = plt.subplots(figsize=(12, 7))
    color1 = '#61AFEF'
    ax1.set_xlabel('입력 크기 (N)', fontsize=12)
    ax1.set_ylabel('예상 연산 횟수 (Time)', color=color1, fontsize=12)
    line1, = ax1.plot(n_values, time_values, color=color1, linewidth=2.5, label='시간 복잡도 O(N^3)')
    ax1.tick_params(axis='y', labelcolor=color1)
    ax1.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
    ax2 = ax1.twinx()
    color2 = '#E5C07B'
    ax2.set_ylabel('예상 메모리 사용량 (Space)', color=color2, fontsize=12)
    line2, = ax2.plot(n_values, space_values, color=color2, linestyle='--', linewidth=2.5, label='공간 복잡도 O(N^2)')
    ax2.tick_params(axis='y', labelcolor=color2)
    ax2.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
    plt.title('무한부스터 알고리즘 복잡도 분석 (N=M 가정)', fontsize=16, pad=20)

    lines = [line1, line2]
    fig.legend(lines, [l.get_label() for l in lines], loc='upper center', bbox_to_anchor=(0.5, 0.95), ncol=2, fontsize=11)
    fig.tight_layout(rect=[0, 0, 1, 0.9])
    matplotx.line_labels()
    plt.show()

if __name__ == '__main__':
    plot_complexity_analysis()