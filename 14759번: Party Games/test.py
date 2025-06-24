import time
import random
import string
import tracemalloc
import matplotlib.pyplot as plt
import numpy as np

def generate_names(n, max_len=30):
    names_set = set()
    uppercase_chars = string.ascii_uppercase
    while len(names_set) < n:
        name_len = random.randint(1, max_len)
        name = ''.join(random.choices(uppercase_chars, k=name_len))
        names_set.add(name)
    return list(names_set)

def solve_for_benchmark(names):
    n = len(names)
    if n == 0:
        return None

    names.sort()
    n1 = names[n // 2 - 1]
    n2 = names[n // 2]

    candidates = []
    if n1 < n2:
        pass

    best_s = n2
    for i in range(len(n1) + 1):
        if i == len(n1):
            candidate = n1
        else:
            if n1[i] >= 'Z':
                continue

            prefix = n1[:i]
            char = n1[i]
            new_char = chr(ord(char) + 1)
            candidate = prefix + new_char
        
        if candidate >= n2:
            continue
        
        if len(candidate) < len(best_s):
            best_s = candidate
        elif len(candidate) == len(best_s) and candidate < best_s:
            best_s = candidate

    if len(n1) < len(best_s):
        best_s = n1
    elif len(n1) == len(best_s) and n1 < best_s:
        best_s = n1
    
    return best_s

def run_benchmark():
    n_values = list(range(10, 1001, 40))
    times = []
    memories = []

    print("복잡도 분석을 시작합니다. (n=10 to 1000)")
    for n in n_values:
        print(f"테스트 중... n = {n}")
        names = generate_names(n)

        start_time = time.perf_counter()
        solve_for_benchmark(names)
        end_time = time.perf_counter()
        times.append(end_time - start_time)

        tracemalloc.start()
        solve_for_benchmark(names)
        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()
        memories.append(peak / 1024)

    return n_values, times, memories

def plot_results(n_values, times, memories):
    plt.rc('font', family='Apple SD Gothic Neo')
    plt.rcParams['axes.unicode_minus'] = False
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12,16))
    ax1.plot(n_values, times, 'bo-', label='실제 측정 시간')
    n_log_n = [n * np.log(n) for n in n_values]
    scale_factor = times[0] / n_log_n[0]
    theoretical_time = [val * scale_factor for val in n_log_n]
    ax1.plot(n_values, theoretical_time, 'r--', label='이론적 시간 복잡도 (O(n log n))')

    ax1.set_title('시간 복잡도 분석', fontsize=16)
    ax1.set_xlabel('입력 크기 (n: 이름의 수)', fontsize=12)
    ax1.set_ylabel('실행 시간 (초)', fontsize=12)
    ax1.legend()
    ax1.grid(True)

    ax2.plot(n_values, memories, 'go-', label='실제 측정 메모리')
    scale_factor_mem = memories[0] / n_values[0]
    theoretical_mem = [n * scale_factor_mem for n in n_values]
    ax2.plot(n_values, theoretical_mem, 'r--', label='이론적 공간 복잡도 (O(n))')
    ax2.set_title('공간 복잡도 분석', fontsize=16)
    ax2.set_xlabel('입력 크기 (n: 이름의 수)', fontsize=12)
    ax2.set_ylabel('최대 메모리 사용량 (KiB)', fontsize=12)
    ax2.legend()
    ax2.grid(True)
    
    plt.tight_layout(pad=3.0)
    plt.show()

if __name__ == "__main__":
    n_data, time_data, mem_data = run_benchmark()
    plot_results(n_data, time_data, mem_data)