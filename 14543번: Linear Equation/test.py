import matplotlib.pyplot as plt
import numpy as np
import platform

# 운영체제에 맞는 한글 폰트 설정
if platform.system() == 'Windows':
    plt.rc('font', family='Malgun Gothic')
elif platform.system() == 'Darwin': # MacOS
    plt.rc('font', family='Apple SD Gothic Neo')
else: # Linux
    # 나눔고딕 폰트가 설치되어 있어야 합니다.
    # sudo apt-get install fonts-nanum*
    plt.rc('font', family='Apple SD Gothic Neo')

# 그래프의 마이너스 기호 깨짐 방지
plt.rcParams['axes.unicode_minus'] = False

def plot_complexity_analysis():
    """
    제시된 Java 코드의 시간 및 공간 복잡도를 분석하고 그래프로 시각화합니다.
    - 시간 복잡도: O(P)
    - 공간 복잡도: O(1)
    """
    # P: 데이터 세트의 수 (문제 제약 조건: 1 <= P <= 100)
    p_values = np.arange(1, 101)

    # --- 시간 복잡도 시뮬레이션 ---
    # O(P)이므로 시간에 비례하는 그래프가 생성됩니다.
    # time_per_equation은 각 방정식을 처리하는 데 걸리는 임의의 상수 시간입니다.
    time_per_equation = 0.005  # 예: 5ms
    # 실제 측정 시 발생할 수 있는 약간의 노이즈를 추가하여 현실감을 더합니다.
    time_noise = np.random.rand(len(p_values)) * 0.05
    
    # 시뮬레이션된 시간 = P * (단위 시간) + 노이즈
    simulated_time = p_values * time_per_equation + time_noise
    # 이론적인 시간 (이상적인 직선)
    theoretical_time = p_values * time_per_equation

    # --- 공간 복잡도 시뮬레이션 ---
    # O(1)이므로 P값에 관계없이 메모리 사용량은 거의 일정합니다.
    # constant_memory는 프로그램이 사용하는 임의의 상수 메모리량입니다.
    constant_memory = 10  # 예: 10MB
    # 약간의 노이즈 추가
    space_noise = np.random.rand(len(p_values)) * 0.2
    
    # 시뮬레이션된 공간 = 상수 메모리 + 노이즈
    simulated_space = np.full_like(p_values, constant_memory, dtype=float) + space_noise
    # 이론적인 공간 (이상적인 수평선)
    theoretical_space = np.full_like(p_values, constant_memory, dtype=float)

    # --- 그래프 그리기 ---
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))
    fig.suptitle('Java 선형 방정식 풀이 코드 복잡도 분석', fontsize=16)

    # 1. 시간 복잡도 그래프 (Time Complexity)
    ax1.scatter(p_values, simulated_time, alpha=0.6, label='측정된 시간 (시뮬레이션)')
    ax1.plot(p_values, theoretical_time, 'r--', label='이론적 복잡도 O(P)')
    ax1.set_title('시간 복잡도 (Time Complexity)')
    ax1.set_xlabel('데이터 세트의 수 (P)')
    ax1.set_ylabel('소요 시간 (임의 단위)')
    ax1.legend()
    ax1.grid(True, linestyle='--', alpha=0.6)

    # 2. 공간 복잡도 그래프 (Space Complexity)
    ax2.scatter(p_values, simulated_space, alpha=0.6, label='측정된 공간 (시뮬레이션)')
    ax2.plot(p_values, theoretical_space, 'r--', label='이론적 복잡도 O(1)')
    ax2.set_title('공간 복잡도 (Space Complexity)')
    ax2.set_xlabel('데이터 세트의 수 (P)')
    ax2.set_ylabel('메모리 사용량 (임의 단위)')
    ax2.set_ylim(bottom=0, top=constant_memory * 1.5) # y축 범위 설정
    ax2.legend()
    ax2.grid(True, linestyle='--', alpha=0.6)

    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.show()

if __name__ == '__main__':
    plot_complexity_analysis()