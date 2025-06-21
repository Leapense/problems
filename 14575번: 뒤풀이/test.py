import numpy as np
import matplotlib.pyplot as plt
import platform

plt.rc('font', family='Apple SD Gothic Neo')
plt.rcParams['axes.unicode_minus'] = False

N_max = 1000
K_range = 10**9

N = np.linspace(1, N_max, 100)
log_K = np.log2(K_range)
time_complexity = N * log_K
space_complexity = N

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 7))

ax1.plot(N, time_complexity, label=f'T(N) = N * log₂({K_range:.0e})', color='dodgerblue', linewidth=2)
ax1.set_title('시간 복잡도 (Time Complexity)', fontsize=16, pad=15)
ax1.set_xlabel('참가자 수 (N)', fontsize=12)
ax1.set_ylabel('추정 연산 횟수 (Operations)', fontsize=12)
ax1.legend(fontsize=12)
ax1.grid(True, linestyle='--', alpha=0.6)
ax1.text(N_max * 0.98, time_complexity[-1], 'O(N * log K)', 
         verticalalignment='top', horizontalalignment='right',
         fontsize=14, color='red', bbox=dict(facecolor='white',
                                             alpha=0.8, edgecolor='none'))

ax2.plot(N, space_complexity, label='S(N) = N', color='coral', linewidth=2)
ax2.set_title('공간 복잡도 (Space Complexity)', fontsize=16, pad=15)
ax2.set_xlabel('참가자 수 (N)', fontsize=12)
ax2.set_ylabel('추정 메모리 사용량 (Units)', fontsize=12)
ax2.legend(fontsize=12)
ax2.grid(True, linestyle='--', alpha=0.6)
ax2.text(N_max * 0.98, space_complexity[-1], 'O(N)', 
         verticalalignment='top', horizontalalignment='right', 
         fontsize=14, color='red', bbox=dict(facecolor='white', alpha=0.8, edgecolor='none'))

plt.suptitle('뒤풀이 문제 (백준 14575) 복잡도 분석', fontsize=20, y=1.02)
plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.show()