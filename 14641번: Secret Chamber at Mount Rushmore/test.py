import matplotlib.pyplot as plt
import numpy as np

def plot_complexity():
    plt.style.use('dark_background')
    plt.rcParams.update({
        'figure.facecolor': '#1c1c1e',
        'axes.facecolor': '#2c2c2e',
        'text.color': '#e5e5e7',
        'axes.labelcolor': '#c7c7cc',
        'xtick.color': '#8e8e93',
        'ytick.color': '#8e8e93',
        'axes.edgecolor': '#545458',
        'grid.color': '#3a3a3c',
        'font.family': 'sans-serif',
        'font.sans-serif': ['Apple SD Gothic Neo', 'SF Pro Display'],
        'figure.dpi': 100
    })

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 7))
    fig.suptitle('시간 복잡도 분석: O(m + n * L + C^3)', fontsize=20, weight='bold', color='#ffffff')

    C = 26
    SETUP_COST = C ** 3
    m_range = np.linspace(1, 500, 100)
    nl_const = 50 * 50
    nl_range = np.linspace(1, 50 * 50, 100)
    m_const = 500

    time1 = m_range + nl_const + SETUP_COST
    time2 = nl_range + m_const + SETUP_COST

    ax1.plot(m_range, time1, color='#00aaff', linewidth=2.5, label='연산량 (m 변화)')
    # 글로우 효과 추가
    ax1.plot(m_range, time1, color='#00aaff', linewidth=5, alpha=0.3)
    ax1.fill_between(m_range, time1, 0, color='#00aaff', alpha=0.1)
    
    ax1.set_title('Time vs. 번역 규칙 수 (m)', fontsize=14, color='#e5e5e7')
    ax1.set_xlabel('m (번역 규칙 수)', fontsize=12)
    ax1.set_ylabel('상대적 연산량', fontsize=12)
    ax1.grid(True, linestyle='--', linewidth=0.5)
    ax1.legend()
    ax1.text(50, 1.2e4, f'전처리 비용 (C³)\n{SETUP_COST} 연산', color='#ffcc00', ha='left')

    ax2.plot(nl_range, time2, color='#33ccff', linewidth=2.5, label='연산량 (n*L 변화)')
    # 글로우 효과 추가
    ax2.plot(nl_range, time2, color='#33ccff', linewidth=5, alpha=0.3)
    ax2.fill_between(nl_range, time2, 0, color='#33ccff', alpha=0.1)

    ax2.set_title('Time vs. 총 단어 길이 (n * L)', fontsize=14, color='#e5e5e7')
    ax2.set_xlabel('n * L (총 단어 길이)', fontsize=12)
    ax2.set_ylabel('상대적 연산량', fontsize=12)
    ax2.grid(True, linestyle='--', linewidth=0.5)
    ax2.legend()
    ax2.text(250, 1.2e4, f'전처리 비용 (C³)\n{SETUP_COST} 연산', color='#ffcc00', ha='left')

    plt.tight_layout(rect=[0, 0, 1, 0.95])
    plt.show()

    fig_space, ax_space = plt.subplots(figsize=(8, 6))
    fig_space.suptitle('공간 복잡도 분석: O(C^2 + L)', fontsize=20, weight='bold', color='#ffffff')

    space_c_sq = C ** 2
    space_l = 50

    labels = ['reachable 행령 (C^2)', '단어 저장 공간 (L)']
    sizes = [space_c_sq, space_l]
    colors = ['#5856d6', '#ff9500']

    bars = ax_space.bar(labels, sizes, color=colors, width=0.5)

    for bar in bars:
        yval = bar.get_height()
        ax_space.text(bar.get_x() + bar.get_width()/2.0, yval + 15, int(yval), 
                      ha='center', va='bottom', color='#e5e5e7', fontsize=12)

    ax_space.set_ylabel('사용 공간 (단위)', fontsize=12)
    ax_space.set_title('공간 사용량 구성 요소', fontsize=14, color='#e5e5e7')
    ax_space.set_yticks([]) # y축 눈금 제거
    
    plt.tight_layout(rect=[0, 0, 1, 0.93])
    plt.show()

if __name__ == "__main__":
    plot_complexity()