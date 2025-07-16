import matplotlib.pyplot as plt
import numpy as np
import matplotx

plt.rcParams['font.family'] = 'Apple SD Gothic Neo'
plt.rcParams['axes.unicode_minus'] = False

# 1. matplotx의 'onedark' 스타일 적용
plt.style.use(matplotx.styles.onedark)

# 2. 데이터 생성 (문제의 제약 조건 K <= 200,000)
# k_values: 1,000부터 200,000까지 400개의 점으로 표현
k_values = np.linspace(1000, 200000, 400)

# 3. 복잡도 계산
# 시간 복잡도: O(K log K)
time_complexity = k_values * np.log2(k_values)
# 공간 복잡도: O(K)
space_complexity = k_values

# 4. 그래프 생성
# 2개의 서브플롯을 가진 Figure 생성
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 12))
fig.suptitle('알고리즘 복잡도 분석 (맥주 축제)', fontsize=18, fontweight='bold')

# 4-1. 시간 복잡도 그래프
ax1.plot(k_values, time_complexity, label='O(K log K)', linewidth=2.5)
ax1.set_title('시간 복잡도 (Time Complexity)', fontsize=14)
ax1.set_xlabel('K (맥주 종류의 수)', fontsize=12)
ax1.set_ylabel('예상 연산 횟수 (비례)', fontsize=12)
ax1.legend()
ax1.grid(True, which='both', linestyle=':', linewidth=0.6)
# y축 레이블을 과학적 표기법으로 변경하여 가독성 향상
ax1.ticklabel_format(style='sci', axis='y', scilimits=(0,0))

# 4-2. 공간 복잡도 그래프
ax2.plot(k_values, space_complexity, label='O(K)', color='cyan', linewidth=2.5)
ax2.set_title('공간 복잡도 (Space Complexity)', fontsize=14)
ax2.set_xlabel('K (맥주 종류의 수)', fontsize=12)
ax2.set_ylabel('예상 메모리 사용량 (비례)', fontsize=12)
ax2.legend()
ax2.grid(True, which='both', linestyle=':', linewidth=0.6)
# y축 레이블을 과학적 표기법으로 변경
ax2.ticklabel_format(style='sci', axis='y', scilimits=(0,0))

# 5. 레이아웃 조정 및 그래프 출력
plt.tight_layout(rect=[0, 0, 1, 0.95]) # 전체 제목과 겹치지 않도록 조정
plt.show()
