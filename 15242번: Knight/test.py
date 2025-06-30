import time
import collections
import tracemalloc
import matplotlib.pyplot as plt
import numpy as np

def knight_shortest_path(board_size, start, end):
    """
    N x N 보드에서 나이트의 최단 경로를 BFS로 계산합니다.
    """
    # 나이트의 8가지 이동 방향
    dx = [-2, -2, -1, -1, 1, 1, 2, 2]
    dy = [-1, 1, -2, 2, -2, 2, -1, 1]

    # 시작점과 끝점이 같으면 0을 반환
    if start == end:
        return 0

    # BFS를 위한 큐와 방문 기록
    queue = collections.deque([(start, 0)])  # ((x, y), moves)
    visited = {start}

    while queue:
        (current_x, current_y), moves = queue.popleft()

        if (current_x, current_y) == end:
            return moves

        for i in range(8):
            next_x, next_y = current_x + dx[i], current_y + dy[i]

            # 보드 경계 내에 있고 아직 방문하지 않았다면
            if 0 <= next_x < board_size and 0 <= next_y < board_size:
                if (next_x, next_y) not in visited:
                    visited.add((next_x, next_y))
                    queue.append(((next_x, next_y), moves + 1))
    
    return -1 # 경로가 없는 경우 (이 문제에서는 발생하지 않음)

def analyze_complexity():
    """
    보드 크기를 늘려가며 시간 및 공간 복잡도를 측정하고 그래프로 시각화합니다.
    """
    board_sizes = list(range(10, 101, 10)) # 10x10부터 100x100까지 10씩 증가
    execution_times = []
    peak_memories = []

    print("보드 크기별 성능 분석 시작...")
    
    tracemalloc.start()

    for n in board_sizes:
        print(f"분석 중: {n}x{n} 보드")
        
        # 최악의 경우를 가정 (보드의 양 끝)
        start_node = (0, 0)
        end_node = (n - 1, n - 1)

        # 시간 측정
        start_time = time.perf_counter()
        knight_shortest_path(n, start_node, end_node)
        end_time = time.perf_counter()
        execution_times.append(end_time - start_time)

        # 메모리 측정 (최대 사용량)
        # tracemalloc은 누적된 값을 보여주므로, 각 실행 전에 초기화
        current, peak = tracemalloc.get_traced_memory()
        peak_memories.append(peak / 1024) # KB 단위로 저장
        tracemalloc.clear_traces()

    tracemalloc.stop()
    print("분석 완료.")

    # 그래프 생성
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
    
    # 이론적 복잡도 O(N^2) 곡선 계산 (데이터에 맞게 스케일링)
    n_squared = np.array(board_sizes) ** 2
    time_scale_factor = execution_times[-1] / n_squared[-1]
    mem_scale_factor = peak_memories[-1] / n_squared[-1]
    
    theoretical_time = time_scale_factor * n_squared
    theoretical_mem = mem_scale_factor * n_squared

    # 1. 시간 복잡도 그래프
    ax1.plot(board_sizes, execution_times, 'bo-', label='Empirical Time')
    ax1.plot(board_sizes, theoretical_time, 'r--', label='Theoretical O(N^2)')
    ax1.set_xlabel('Board Size (N)')
    ax1.set_ylabel('Execution Time (seconds)')
    ax1.set_title('Time Complexity Analysis')
    ax1.legend()
    ax1.grid(True)

    # 2. 공간 복잡도 그래프
    ax2.plot(board_sizes, peak_memories, 'go-', label='Empirical Memory')
    ax2.plot(board_sizes, theoretical_mem, 'r--', label='Theoretical O(N^2)')
    ax2.set_xlabel('Board Size (N)')
    ax2.set_ylabel('Peak Memory Usage (KB)')
    ax2.set_title('Space Complexity Analysis')
    ax2.legend()
    ax2.grid(True)

    plt.suptitle('Performance Analysis of Knight\'s Shortest Path (BFS)', fontsize=16)
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.show()

if __name__ == '__main__':
    analyze_complexity()