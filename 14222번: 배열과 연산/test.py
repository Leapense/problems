import time
import random
import tracemalloc
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import font_manager, rc

def setup_korean_font():
    """
    Matplotlib에서 한글을 지원하기 위한 폰트 설정 함수입니다.
    시스템에 맞는 폰트를 찾아 설정합니다.
    """
    try:
        # Windows
        font_name = font_manager.FontProperties(fname="c:/Windows/Fonts/malgun.ttf").get_name()
        rc('font', family=font_name)
    except FileNotFoundError:
        try:
            # macOS
            rc('font', family='Apple SD Gothic Neo')
        except:
            # Linux/Colab (나눔고딕 폰트 설치 필요)
            # !sudo apt-get -qq -y install fonts-nanum
            # font_manager._rebuild()
            try:
                rc('font', family='NanumBarunGothic')
            except:
                print("한글 폰트를 찾을 수 없습니다. 그래프의 제목과 축 레이블이 깨질 수 있습니다.")
    plt.rcParams['axes.unicode_minus'] = False # 마이너스 기호 깨짐 방지


def dfs(u, graph, match, visited):
    """
    DFS를 이용해 u번째 소스 노드에 대한 증가 경로를 찾습니다.
    """
    for v in graph[u]:
        if not visited[v]:
            visited[v] = True
            if match[v] == -1 or dfs(match[v], graph, match, visited):
                match[v] = u
                return True
    return False

def run_bipartite_matching(n, k, a):
    """
    분석을 위해 I/O를 제거하고 순수 로직만 남긴 알고리즘 함수입니다.
    :param n: 배열의 크기
    :param k: 더할 수 있는 수
    :param a: 입력 배열
    """
    graph = [[] for _ in range(n)]
    for i in range(n):
        for j in range(1, n + 1):
            if j >= a[i] and (j - a[i]) % k == 0:
                graph[i].append(j - 1)

    match = [-1] * n
    match_count = 0
    for i in range(n):
        visited = [False] * n
        if dfs(i, graph, match, visited):
            match_count += 1

    # 분석 스크립트에서는 결과값을 사용하지 않으므로 반환은 생략합니다.

def analyze_complexity():
    """
    N을 1부터 50까지 변화시키며 시간 및 공간 복잡도를 측정합니다.
    """
    n_values = range(1, 51)  # N의 범위: 1부터 50까지
    time_results = []
    space_results_kb = []

    print("복잡도 분석 시작 (N=1 to 50)...")

    for n in n_values:
        # 현실적인 무작위 입력 데이터 생성
        k = random.randint(1, 10)
        a = [random.randint(1, 50) for _ in range(n)]

        # 1. 시간 복잡도 측정
        start_time = time.perf_counter()
        run_bipartite_matching(n, k, a)
        end_time = time.perf_counter()
        elapsed_time = end_time - start_time
        time_results.append(elapsed_time)

        # 2. 공간 복잡도 측정
        tracemalloc.start()
        run_bipartite_matching(n, k, a)
        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()
        # 결과를 KB 단위로 저장
        space_results_kb.append(peak / 1024)
        
        if n % 5 == 0:
            print(f"  N={n} 완료. 시간: {elapsed_time:.6f}초, 최대 메모리: {peak/1024:.2f}KB")

    print("분석 완료.")
    return n_values, time_results, space_results_kb

def plot_results(n_values, time_results, space_results):
    """
    측정된 결과를 Matplotlib을 사용하여 그래프로 시각화합니다.
    """
    setup_korean_font()

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 16))
    fig.suptitle('배열과 연산 알고리즘 복잡도 분석', fontsize=16)

    # --- 시간 복잡도 그래프 ---
    ax1.plot(n_values, time_results, 'o-', label="실제 측정 시간", markersize=4)

    # 이론적 시간 복잡도 O(N^3) 곡선과 비교
    # 상수를 곱하여 실제 값과 스케일을 맞춥니다.
    time_fit = np.polyfit(np.array(n_values)**3, time_results, 1)[0]
    theoretical_time = time_fit * (np.array(n_values)**3)
    ax1.plot(n_values, theoretical_time, 'r--', label="이론적 복잡도 (O(N³))")

    ax1.set_title("N에 따른 시간 복잡도")
    ax1.set_xlabel("배열의 크기 (N)")
    ax1.set_ylabel("실행 시간 (초)")
    ax1.legend()
    ax1.grid(True)

    # --- 공간 복잡도 그래프 ---
    ax2.plot(n_values, space_results, 'o-', color='green', label="실제 측정 메모리", markersize=4)

    # 이론적 공간 복잡도 O(N^2) 곡선과 비교
    # 상수를 곱하여 실제 값과 스케일을 맞춥니다.
    space_fit = np.polyfit(np.array(n_values)**2, space_results, 1)[0]
    theoretical_space = space_fit * (np.array(n_values)**2)
    ax2.plot(n_values, theoretical_space, 'r--', label="이론적 복잡도 (O(N²))")

    ax2.set_title("N에 따른 공간 복잡도")
    ax2.set_xlabel("배열의 크기 (N)")
    ax2.set_ylabel("최대 메모리 사용량 (KB)")
    ax2.legend()
    ax2.grid(True)
    
    plt.tight_layout(rect=[0, 0, 1, 0.96]) # suptitle과 겹치지 않게 조정
    plt.show()

if __name__ == "__main__":
    n_data, time_data, space_data = analyze_complexity()
    plot_results(n_data, time_data, space_data)
