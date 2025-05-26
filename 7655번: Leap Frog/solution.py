import sys
from collections import deque

def solve():
    data = sys.stdin.read().split()
    idx = 0

    while True:
        n = int(data[idx]); idx += 1
        if n == 0:
            break

        # 1-based 인덱스 편의를 위해 앞에 0을 추가
        pos = [0] + list(map(int, data[idx:idx+n]))
        idx += n

        # 초기 상태에서 이미 앞 플레이어가 목표에 있다면
        if 2 == n:
            print(0)
            continue

        visited = set()
        queue = deque()
        # (뒤쪽 인덱스, 앞쪽 인덱스, 점프 횟수)
        queue.append((1, 2, 0))
        visited.add((1, 2))

        answer = -1
        while queue:
            i, j, jumps = queue.popleft()
            limit = pos[i] + 10
            k = j + 1

            # pos[i]에서 최대 10 이내, k > j
            while k <= n and pos[k] <= limit:
                # 목표 도달
                if k == n:
                    answer = jumps + 1
                    queue.clear()
                    break

                state = (j, k)
                if state not in visited:
                    visited.add(state)
                    queue.append((j, k, jumps + 1))
                k += 1

            if answer != -1:
                break

        print(answer)

if __name__ == "__main__":
    solve()