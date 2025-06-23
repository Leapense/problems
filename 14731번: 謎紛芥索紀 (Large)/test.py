import matplotlib.pyplot as plt
import numpy as np

# --- 1. 시뮬레이션 함수 정의 ---

def simulated_power_operations(exp):
    """
    Java 코드의 power 함수의 시뮬레이션된 연산 횟수를 반환합니다.
    실제 연산 횟수는 log2(exp)에 비례합니다.
    exp가 0 이하일 경우, 로그는 정의되지 않으므로 0을 반환합니다.
    power(base, 0)은 0회 반복으로 1을 반환하므로, 이는 정확한 시뮬레이션입니다.
    """
    if exp <= 0:
        return 0
    # np.log2(exp + 1)은 exp=0일 때 0, exp=1일 때 1을 반환하여
    # 실제 power 함수의 루프 횟수와 유사하게 동작하도록 근사합니다.
    return np.log2(exp + 1)

def simulated_total_operations(N, K_val):
    """
    Java 코드의 총 연산 횟수를 시뮬레이션합니다.
    N개의 항 각각에 대해 power 함수가 호출됩니다.
    K_val은 해당 시뮬레이션에서 사용될 K 값입니다.
    """
    if N <= 0:
        return 0
    # 각 항에 대한 연산은 주로 power(2, K-1)에 의해 결정됩니다.
    # K가 0인 경우(상수항)는 미분 시 0이므로 기여도가 없습니다.
    # K가 1인 경우(Cx^1) K-1=0이 되어 simulated_power_operations(0)은 0을 반환합니다.
    # 이는 log(1)을 0으로 보는 것이므로, asymptotic하게는 O(log K)가 맞습니다.
    # N * (power_op_per_term + constant_ops_per_term)
    # 우리는 O(N log K)의 지배적인 부분을 시각화하므로, N * log(K)에 집중합니다.
    return N * simulated_power_operations(max(0, K_val - 1))


def simulated_space_complexity(N, K):
    """
    Java 코드의 공간 복잡도를 시뮬레이션합니다.
    N과 K에 관계없이 상수 공간을 사용하므로, 고정된 작은 값을 반환합니다.
    """
    return 1 # 상수 공간 복잡도를 나타내기 위한 임의의 값

# --- 2. Matplotlib 스타일 설정 (MacOS 다크 테마) ---

plt.style.use('dark_background')

# 사용자 정의 색상 팔레트
COLORS = {
    'line_n': '#00FFFF',      # N-의존성을 위한 청록색
    'line_k': '#FF00FF',     # K-의존성을 위한 마젠타색
    'line_space': '#00FF00', # 공간 복잡도를 위한 녹색
    'text': '#FFFFFF',      # 흰색
    'grid': '#404040',      # 그리드를 위한 어두운 회색
    'title': '#FFFFFF',     # 제목을 위한 흰색
    'facecolor': '#1E1E1E'  # 다크 테마 배경색
}

plt.rcParams.update({
    'text.color': COLORS['text'],
    'axes.labelcolor': COLORS['text'],
    'axes.edgecolor': COLORS['grid'],
    'xtick.color': COLORS['text'],
    'ytick.color': COLORS['text'],
    'figure.facecolor': COLORS['facecolor'],
    'axes.facecolor': COLORS['facecolor'],
    'grid.color': COLORS['grid'],
    'grid.linestyle': '--',
    'grid.alpha': 0.7,
    'font.family': 'sans-serif',
    'font.sans-serif': ['Apple SD Gothic Neo'],
    'axes.titlecolor': COLORS['title']
})

# --- 3. 데이터 생성 및 플로팅 ---

# 3개의 서브플롯 생성: 시간 복잡도 vs N, 시간 복잡도 vs K, 공간 복잡도
fig, axes = plt.subplots(1, 3, figsize=(24, 7))

# --- 3.1. 시간 복잡도 vs N 그래프 (K 고정) ---
N_values = np.linspace(1, 100000, 100, dtype=int) # 1부터 100,000까지 N 값
fixed_K_time_N = 10**9 # K를 최대값으로 고정하여 N에 대한 영향을 명확히 보여줍니다.
time_complexity_vs_N = [simulated_total_operations(n, fixed_K_time_N) for n in N_values]

axes[0].plot(N_values, time_complexity_vs_N, color=COLORS['line_n'], linewidth=2)
axes[0].set_title(f"시간 복잡도 (N 의존성)\n($K = {fixed_K_time_N}$ 고정)", fontsize=16)
axes[0].set_xlabel("항의 개수 (N)", fontsize=12)
axes[0].set_ylabel("시뮬레이션된 연산 횟수", fontsize=12)
axes[0].grid(True)
axes[0].ticklabel_format(style='plain', axis='y') # y축 지수 표기법 해제

# --- 3.2. 시간 복잡도 vs K 그래프 (N 고정) ---
K_values_time_K = np.logspace(0, 9, 50, dtype=int) # 1부터 10^9까지 K 값 (로그 스케일)
fixed_N_time_K = 100000 # N을 최대값으로 고정하여 K에 대한 영향을 명확히 보여줍니다.
# K-1이 음수가 되지 않도록 K_values_time_K를 1 이상으로 필터링
K_values_time_K = np.array([k for k in K_values_time_K if k >= 1])
time_complexity_vs_K = [simulated_total_operations(fixed_N_time_K, k) for k in K_values_time_K]

axes[1].plot(K_values_time_K, time_complexity_vs_K, color=COLORS['line_k'], linewidth=2)
axes[1].set_title(f"시간 복잡도 (K 의존성)\n($N = {fixed_N_time_K}$ 고정)", fontsize=16)
axes[1].set_xlabel("항의 차수 (K)", fontsize=12)
axes[1].set_xscale('log') # K는 로그 스케일로 증가하므로 x축도 로그 스케일로 표시합니다.
axes[1].set_ylabel("시뮬레이션된 연산 횟수", fontsize=12)
axes[1].grid(True)
axes[1].ticklabel_format(style='plain', axis='y') # y축 지수 표기법 해제


# --- 3.3. 공간 복잡도 그래프 ---
# N과 K의 범위를 설정하여 공간 복잡도가 변화하지 않음을 보여줍니다.
# 공간 복잡도는 상수이므로 입력 크기 변화에 무관하게 일정한 값을 가집니다.
range_for_space = np.linspace(1, 100000, 100, dtype=int)
space_complexity_values = [simulated_space_complexity(n, k) for n, k in zip(range_for_space, np.logspace(0, 9, 100, dtype=int))]

axes[2].plot(range_for_space, space_complexity_values, color=COLORS['line_space'], linewidth=2)
axes[2].set_title("공간 복잡도 (상수 $O(1)$)", fontsize=16)
axes[2].set_xlabel("입력 크기 (N 또는 K의 스케일)", fontsize=12)
axes[2].set_ylabel("시뮬레이션된 공간 사용량", fontsize=12)
axes[2].set_ylim(0.5, 1.5) # 상수 공간임을 명확히 보여주기 위해 y축 범위 설정
axes[2].set_yticks([1]) # y축 틱을 1로 고정
axes[2].grid(True)


# --- 4. 그래프 레이아웃 조정 및 출력 ---
plt.tight_layout(rect=[0, 0.03, 1, 0.95]) # 서브플롯 간 간격 및 제목 공간 조절
plt.suptitle("Java 다항함수 미분 프로그램 복잡도 분석 (MacOS 다크 테마)", color=COLORS['title'], fontsize=20, y=0.98)
plt.show()
