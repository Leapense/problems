import numpy as np
import matplotlib.pyplot as plt
import matplotx

def plot_complexity():
    plt.style.use(matplotx.styles.onedark)
    n_range = np.linspace(1, 100, 50)
    m_range = np.linspace(1, 100000, 50)
    N, M = np.meshgrid(n_range, m_range)
    Operations = N * M
    fig = plt.figure(figsize=(12,9))
    ax = fig.add_subplot(111, projection='3d')
    surf = ax.plot_surface(N, M, Operations, cmap='plasma', edgecolor='none')

    plt.rcParams['font.family'] = 'Apple SD Gothic Neo'
    plt.rcParams['axes.unicode_minus'] = False

    ax.set_xlabel('후임의 수 (N)', labelpad=15)
    ax.set_ylabel('목표 포만감 (M)', labelpad=15)
    ax.set_zlabel('총 연산 횟수 (비례)', labelpad=10)
    ax.set_title('시간 복잡도 O(N * M) 시각화', pad=20, fontsize=16)

    ax.ticklabel_format(style='sci', axis='z', scilimits=(0, 0))
    fig.colorbar(surf, shrink=0.5, aspect=10, pad=0.1)
    plt.show()

if __name__ == '__main__':
    try:
        import matplotx
    except ImportError:
        print("시각화를 위해 'matplotx' 라이브러리가 필요합니다.")
        print("pip install matplotx")
    else:
        plot_complexity()