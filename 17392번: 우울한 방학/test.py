import matplotlib.pyplot as plt
import numpy as np
import matplotx

def plot_complexity_analysis():
    """
    O(N * M * log(M)) 시간 복잡도를 시각화하는 그래프를 생성합니다.
    matplotx의 'onedark' 테마를 사용합니다.
    """
    # matplotx의 onedark 스타일 적용
    with plt.style.context(matplotx.styles.onedark):
        fig, ax = plt.subplots()
        plt.rcParams['axes.unicode_minus'] = False
        plt.rcParams['font.family'] = 'Apple SD Gothic Neo'
        # --- 시나리오 1: N 고정, M 변화 ---
        N_fixed = 100
        M_range = np.arange(10, 1001, 10)
        # M * log(M) 계산 (M이 0 또는 1일 경우 log(M)이 음수/0이 되므로 M_range[M_range > 1] 사용)
        complexity1 = N_fixed * M_range * np.log2(M_range)
        
        ax.plot(M_range, complexity1, label=f'N = {N_fixed} (고정), M 변화')

        # --- 시나리오 2: M 고정, N 변화 ---
        M_fixed = 1000
        N_range = np.arange(1, M_fixed, 10)
        complexity2 = N_range * M_fixed * np.log2(M_fixed)
        
        ax.plot(N_range, complexity2, label=f'M = {M_fixed} (고정), N 변화')

        # 그래프 제목 및 축 레이블 설정
        ax.set_title("시간 복잡도 분석: O(N * M log M)", fontsize=16, pad=20)
        ax.set_xlabel("N 또는 M의 크기", fontsize=12)
        ax.set_ylabel("이론적 연산 횟수 (로그 스케일)", fontsize=12)
        
        # Y축을 로그 스케일로 변경하여 값의 큰 변화를 잘 보이게 함
        ax.set_yscale('log')
        
        # 그리드 추가
        ax.grid(True, which="both", linestyle='--', linewidth=0.5)
        
        # matplotx의 라인 레이블 기능으로 범례를 깔끔하게 표시
        matplotx.line_labels()
        
        fig.tight_layout()
        plt.show()

if __name__ == '__main__':
    # matplotx가 설치되어 있지 않다면 설치 안내 메시지를 출력합니다.
    try:
        import matplotx
    except ImportError:
        print("이 코드를 실행하려면 'matplotx' 라이브러리가 필요합니다.")
        print("터미널에서 'pip install matplotx'를 실행하여 설치해주세요.")
    else:
        plot_complexity_analysis()