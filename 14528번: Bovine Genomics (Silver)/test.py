import numpy as np
import matplotlib.pyplot as plt

# --- 그래프 설정 ---
# N의 값을 몇 가지 대표값으로 고정합니다.
N_fixed_values = [10, 50, 100, 200] 
# M의 값은 x축으로 사용하기 위해 연속적인 범위로 생성합니다.
# 문제 제약 조건 M<=50에 맞춰 1부터 50까지의 범위를 사용합니다.
M_vals = np.linspace(1, 50, 100) # 1부터 50까지 100개의 점으로 부드럽게 표현

# --- 1. 시간 복잡도 O(N^2 * M^3) 2D 그래프 ---
fig_time, ax_time = plt.subplots(figsize=(10, 7))

# 고정된 N 값 각각에 대해 M에 따른 복잡도를 계산하고 그립니다.
for n_const in N_fixed_values:
    # 시간 복잡도 계산: T = n^2 * m^3
    time_complexity = (n_const**2) * (M_vals**3)
    ax_time.plot(M_vals, time_complexity, label=f'N = {n_const}')

# 그래프 제목과 축 레이블 설정
ax_time.set_title('Time Complexity: O(N^2 * M^3)', fontsize=16)
ax_time.set_xlabel('M (DNA Length)', fontsize=12)
ax_time.set_ylabel('Relative Operations (log scale)', fontsize=12)
ax_time.legend()  # 각 라인이 어떤 N 값에 해당하는지 범례 표시
ax_time.grid(True, linestyle='--', alpha=0.6)

# Y축 값이 매우 빠르게 커지므로 로그 스케일로 변경하여 가독성을 높입니다.
ax_time.set_yscale('log')


# --- 2. 공간 복잡도 O(N * M) 2D 그래프 ---
fig_space, ax_space = plt.subplots(figsize=(10, 7))

# 고정된 N 값 각각에 대해 M에 따른 복잡도를 계산하고 그립니다.
for n_const in N_fixed_values:
    # 공간 복잡도 계산: S = n * m
    space_complexity = n_const * M_vals
    ax_space.plot(M_vals, space_complexity, label=f'N = {n_const}')

# 그래프 제목과 축 레이블 설정
ax_space.set_title('Space Complexity: O(N * M)', fontsize=16)
ax_space.set_xlabel('M (DNA Length)', fontsize=12)
ax_space.set_ylabel('Relative Memory Usage', fontsize=12)
ax_space.legend()
ax_space.grid(True, linestyle='--', alpha=0.6)

# Y축 값의 포맷을 일반 숫자로 설정 (과학적 표기법 방지)
ax_space.ticklabel_format(style='plain', axis='y')


# 그래프를 화면에 표시합니다.
plt.tight_layout()
plt.show()
