import time, random, tracemalloc
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import font_manager, rc

def setup_korean_font():
    try:
        font_name = font_manager.FontProperties(fname="c:/Windows/Fonts/malgun.ttf").get_name()
        rc('font', family=font_name)
    except FileNotFoundError:
        try:
            rc('font', family='Apple SD Gothic Neo')
        except:
            print("Cannot found the korean font. The label of graph can be break.")
    plt.rcParams['axes.unicode_minus'] = False

def run_convex_sequence_algorithm(n, a):
    if n <= 2:
        return 0

    x = list(a)
    iteration_count = 0
    while True:
        iteration_count += 1
        changed = False
        for i in range(1, n - 1):
            if 2 * x[i] > x[i-1] + x[i+1]:
                required_val = (x[i-1] + x[i+1]) // 2
                x[i] = required_val
                changed = True

        if not changed:
            break

    return iteration_count

def analyze_complexity():
    n_values = range(2, 51)
    time_results = []
    space_results_kb = []
    iteration_results = []

    max_val = 10000
    print("복잡도 분석 시작 (N=2 to 50)...")

    for n in n_values:
        a = [random.randint(0, max_val) for _ in range(n)]
        start_time = time.perf_counter()
        iterations = run_convex_sequence_algorithm(n, a)
        end_time = time.perf_counter()

        time_results.append(end_time - start_time)
        iteration_results.append(iterations)

        tracemalloc.start()
        measured_a = [random.randint(0, max_val) for _ in range(n)]
        run_convex_sequence_algorithm(n, measured_a)
        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()
        space_results_kb.append(peak / 1024)

        if n % 5 == 0:
            print(f"  N={n} 완료. 시간: {end_time - start_time:.6f}초, 반복: {iterations}, 메모리: {peak/1024:.2f}KB")

    print("분석 완료.")
    return list(n_values), time_results, space_results_kb, iteration_results

def plot_results(n_values, time_results, space_results, iteration_results):
    setup_korean_font()
    fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(12, 22))
    fig.suptitle('볼록 수열 알고리즘 복잡도 분석', fontsize=16)

    n_values_np = np.array(n_values)

    ax1.plot(n_values_np, time_results, 'o-', label="실제 측정 시간", markersize=4)
    time_fit = np.polyfit(n_values_np ** 3, time_results, 1)[0]
    theoretical_time = time_fit * (n_values_np ** 3)
    ax1.plot(n_values_np, theoretical_time, 'r--', label="경험적 비교 곡선 (O(N^3))")
    ax1.set_title("N에 따른 시간 복잡도")
    ax1.set_xlabel("수열의 크기 (N)")
    ax1.set_ylabel("실행 시간 (초)")
    ax1.legend()
    ax1.grid(True)

    ax2.plot(n_values_np, space_results, 'o-', color='green', label="실제 측정 메모리(KB)", markersize=4)
    space_fit = np.polyfit(n_values_np, space_results, 1)
    theoretical_space = space_fit[0] * n_values_np + space_fit[1]
    ax2.plot(n_values_np, theoretical_space, 'r--', label="이론적 복잡도 (O(N))")
    ax2.set_title("N에 따른 공간 복잡도")
    ax2.set_xlabel("수열의 크기 (N)")
    ax2.set_ylabel("최대 메모리 사용량 (KB)")
    ax2.legend()
    ax2.grid(True)

    ax3.plot(n_values_np, iteration_results, 'o-', color='purple', label="실제 반복 횟수", markersize=4)
    iter_fit = np.polyfit(n_values_np ** 2, iteration_results, 1)[0]
    theoretical_iter = iter_fit * (n_values_np ** 2)
    ax3.plot(n_values_np, theoretical_iter, 'r--', label="경험적 비교 곡선 (O(N^2))")
    ax3.set_title("N에 따른 `while` 루프 반복 횟수")
    ax3.set_xlabel("수열의 크기 (N)")
    ax3.set_ylabel("반복 횟수")
    ax3.legend()
    ax3.grid (True)
    plt.tight_layout(rect=[0, 0, 1, 0.96])
    plt.show()

if __name__ == "__main__":
    n_data, time_data, space_data, iter_data = analyze_complexity()
    plot_results(n_data, time_data, space_data, iter_data)
