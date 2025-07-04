import time
import random
import sys
import matplotlib.pyplot as plt
import numpy as np

# --- 여기에 문제 풀이 알고리즘을 포함합니다 ---

def count_pairs_for_target(arr, size, target):
    """
    정렬된 배열에서 합이 특정 타겟이 되는 쌍의 개수를 계산합니다.
    (시간 복잡도: O(n))
    """
    count = 0
    left, right = 0, size - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum < target:
            left += 1
        elif current_sum > target:
            right -= 1
        else:
            if arr[left] == arr[right]:
                num_equal = right - left + 1
                count += num_equal * (num_equal - 1) // 2
                break
            
            l_val = arr[left]
            r_val = arr[right]
            l_count = 0
            r_count = 0
            
            temp_l = left
            while temp_l < right and arr[temp_l] == l_val:
                l_count += 1
                temp_l += 1
            
            temp_r = right
            while temp_r > left and arr[temp_r] == r_val:
                r_count += 1
                temp_r -= 1
            
            count += l_count * r_count
            left = temp_l
            right = temp_r
            
    return count

def solve_algorithm(a, v):
    """
    메인 알고리즘을 실행합니다.
    (전체 시간 복잡도: O(n log n))
    """
    n = len(a)
    if n < 2:
        return 0

    # 1. 정렬 (O(n log n))
    a.sort()

    # 2. 최소 차이 찾기 (O(n))
    min_diff = float('inf')
    left, right = 0, n - 1
    while left < right:
        current_sum = a[left] + a[right]
        diff = abs(current_sum - v)
        
        if diff < min_diff:
            min_diff = diff
        
        if current_sum < v:
            left += 1
        elif current_sum > v:
            right -= 1
        else:
            min_diff = 0
            break
    
    # 3. 타겟 합계에 대한 쌍의 개수 세기 (O(n))
    total_count = 0
    target1 = v - min_diff
    target2 = v + min_diff

    total_count += count_pairs_for_target(a, n, target1)
    if target1 != target2:
        total_count += count_pairs_for_target(a, n, target2)

    return total_count

# --- 복잡도 측정 및 시각화 ---

def run_experiment():
    """
    다양한 입력 크기에 대해 알고리즘의 성능을 측정하고 그래프로 시각화합니다.
    """
    # 테스트할 입력 크기(n)의 범위
    # 너무 크게 잡으면 실행 시간이 오래 걸릴 수 있습니다.
    n_values = np.linspace(1000, 100000, 20, dtype=int)
    
    # 측정 결과를 저장할 리스트
    execution_times = []
    space_usages = []

    print("Running complexity analysis...")
    for n in n_values:
        print(f"Testing with n = {n}...")
        
        # 문제 제약 조건에 맞는 랜덤 테스트 데이터 생성
        # -10^4 <= a_i <= 10^4
        # -10^4 <= v <= 10^4
        test_array = [random.randint(-10000, 10000) for _ in range(n)]
        test_v = random.randint(-10000, 10000)
        
        # 공간 사용량 측정 (주로 입력 배열의 크기에 의해 결정됨)
        # sys.getsizeof는 객체 자체의 크기만 반환하므로, 리스트의 경우 전체 크기를 더 정확히 추정합니다.
        space = sys.getsizeof(test_array) + sum(sys.getsizeof(x) for x in test_array)
        space_usages.append(space)

        # 시간 측정
        start_time = time.perf_counter()
        solve_algorithm(test_array, test_v)
        end_time = time.perf_counter()
        
        execution_times.append(end_time - start_time)

    # 이론적 복잡도 곡선 생성 (시각적 비교를 위해 스케일 조정)
    # 시간: O(n log n)
    # 마지막 측정값을 기준으로 상수 c를 추정하여 곡선을 맞춥니다.
    # c * n * log(n)
    last_n = n_values[-1]
    log_last_n = np.log2(last_n) if last_n > 1 else 1 # log(1) is 0
    c_time = execution_times[-1] / (last_n * log_last_n)
    theoretical_times = c_time * n_values * np.log2(n_values)

    # 공간: O(n)
    # c' * n
    c_space = space_usages[-1] / last_n
    theoretical_spaces = c_space * n_values

    # 그래프 그리기
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))

    # 1. 시간 복잡도 그래프
    ax1.plot(n_values, execution_times, 'o-', label='Empirical Time (Measured)')
    ax1.plot(n_values, theoretical_times, 'r--', label='Theoretical O(n log n)')
    ax1.set_title('Time Complexity Analysis')
    ax1.set_xlabel('Input Size (n)')
    ax1.set_ylabel('Execution Time (seconds)')
    ax1.legend()
    ax1.grid(True)

    # 2. 공간 복잡도 그래프
    ax2.plot(n_values, space_usages, 'o-', label='Empirical Space (Measured)')
    ax2.plot(n_values, theoretical_spaces, 'r--', label='Theoretical O(n)')
    ax2.set_title('Space Complexity Analysis')
    ax2.set_xlabel('Input Size (n)')
    ax2.set_ylabel('Space Usage (bytes)')
    ax2.legend()
    ax2.grid(True)

    plt.suptitle('Algorithm Complexity Visualization', fontsize=16)
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.show()

if __name__ == '__main__':
    run_experiment()