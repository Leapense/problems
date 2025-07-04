import numpy as np
import matplotlib.pyplot as plt
import matplotlib.style as style
from matplotlib.ticker import FuncFormatter

# 한글 폰트 설정 (Windows, Mac, Linux 환경에 맞게 주석 해제)
# plt.rcParams['font.family'] = 'Malgun Gothic'  # Windows
# plt.rcParams['font.family'] = 'AppleGothic'    # Mac
plt.rcParams['font.family'] = 'Apple SD Gothic Neo'   # Linux (나눔고딕 설치 필요)
plt.rcParams['axes.unicode_minus'] = False      # 마이너스 폰트 깨짐 방지

def format_number(x, pos):
    """숫자를 천 단위 콤마로 포맷팅하는 함수"""
    return f'{int(x):,}'

# 그래프 스타일 설정
style.use('seaborn-v0_8-whitegrid')

# 1. 입력 크기(N) 정의
# 문제의 제약 조건에 따라 N은 1부터 200,000까지 가능합니다.
N = np.linspace(1, 200000, 400)

# 2. 복잡도 계산
# 시간 복잡도: O(N) - 경로를 한 번 순회하므로 연산 횟수는 N에 비례합니다.
time_complexity = N

# 공간 복잡도: O(K) ≈ O(N) - 도시 K개의 정보를 저장하며, K는 N에 비례할 수 있습니다.
space_complexity = N

# 3. 그래프 생성
# 2개의 서브플롯 (시간, 공간)을 가진 Figure 생성
fig, (ax1, ax2) = plt.subplots(
    nrows=2, 
    ncols=1, 
    figsize=(12, 16)
)

# Figure 전체 제목 설정
fig.suptitle(
    '트리 나라 관광 가이드 - 알고리즘 복잡도 분석',
    fontsize=20,
    fontweight='bold'
)

# --- 첫 번째 그래프: 시간 복잡도 ---
ax1.plot(
    N, 
    time_complexity, 
    label='시간 복잡도 O(N) - 선형 시간', 
    color='dodgerblue', 
    linewidth=3
)
ax1.set_title('시간 복잡도 (Time Complexity)', fontsize=16)
ax1.set_xlabel('입력 크기 (N - 경로 길이)', fontsize=12)
ax1.set_ylabel('수행 연산 수 (임의 단위)', fontsize=12)
ax1.legend(fontsize=12)
ax1.tick_params(axis='both', which='major', labelsize=10)

# 축 포맷터 설정
ax1.xaxis.set_major_formatter(FuncFormatter(format_number))
ax1.yaxis.set_major_formatter(FuncFormatter(format_number))

ax1.text(
    N[-1] * 0.98, time_complexity[0] * 1.02,
    '입력(N)이 커질수록\n연산 수가 정비례하여 증가',
    ha='right', va='bottom', fontsize=11, style='italic',
    bbox=dict(boxstyle='round,pad=0.5', fc='aliceblue', ec='lightsteelblue', lw=1)
)


# --- 두 번째 그래프: 공간 복잡도 ---
ax2.plot(
    N, 
    space_complexity, 
    label='공간 복잡도 O(K) ≈ O(N) - 선형 공간', 
    color='orangered', 
    linewidth=3
)
ax2.set_title('공간 복잡도 (Space Complexity)', fontsize=16)
ax2.set_xlabel('입력 크기 (N - 경로 길이)', fontsize=12)
ax2.set_ylabel('필요 메모리 (임의 단위)', fontsize=12)
ax2.legend(fontsize=12)
ax2.tick_params(axis='both', which='major', labelsize=10)

# 축 포맷터 설정
ax2.xaxis.set_major_formatter(FuncFormatter(format_number))
ax2.yaxis.set_major_formatter(FuncFormatter(format_number))

ax2.text(
    N[-1] * 0.98, space_complexity[0] * 1.02,
    '도시 수(K)가 N에 비례할 수 있으므로\n필요 공간도 선형적으로 증가',
    ha='right', va='bottom', fontsize=11, style='italic',
    bbox=dict(boxstyle='round,pad=0.5', fc='seashell', ec='sandybrown', lw=1)
)


# 레이아웃 조정 및 그래프 출력
plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.show()