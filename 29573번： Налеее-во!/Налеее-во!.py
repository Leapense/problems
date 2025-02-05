def solve():
    import sys
    input_data = sys.stdin.read().splitlines()
    if not input_data: 
        return
    # 1. 입력 파싱
    N, M, K = map(int, input_data[0].split())
    grid = [list(line) for line in input_data[1:N+1]]
    commands = input_data[N+1:N+1+K]
    
    # 2. 초기 군인 찾기 (중심이 '-' 또는 '|'인 셀)
    pivot = None
    direction = None  # 0: up, 1: right, 2: down, 3: left
    for i in range(N):
        for j in range(M):
            if grid[i][j] == '-' or grid[i][j] == '|':
                pivot = (i, j)
                # 수평인지 수직인지 판단
                if grid[i][j] == '-':  # 수평
                    # 왼쪽, 오른쪽 문자 확인
                    left_char = grid[i][j-1] if j-1 >= 0 else None
                    right_char = grid[i][j+1] if j+1 < M else None
                    # 규칙에 따라:
                    # 만약 left가 '\'이고 right가 '/'이면 -> 방향 0 (위)
                    # 만약 left가 '/'이고 right가 '\'이면 -> 방향 2 (아래)
                    if left_char == '\\' and right_char == '/':
                        direction = 0  # up
                    elif left_char == '/' and right_char == '\\':
                        direction = 2  # down
                    else:
                        # 예외 상황 – 문제조건에 따라 발생하지 않음
                        pass
                else:  # grid[i][j] == '|' -> 수직
                    # 위, 아래 문자 확인
                    up_char = grid[i-1][j] if i-1 >= 0 else None
                    down_char = grid[i+1][j] if i+1 < N else None
                    # 규칙에 따라:
                    # 만약 up가 '/'이고 down이 '\'이면 -> 방향 1 (오른쪽)
                    # 만약 up가 '\'이고 down이 '/'이면 -> 방향 3 (왼쪽)
                    if up_char == '/' and down_char == '\\':
                        direction = 1  # right
                    elif up_char == '\\' and down_char == '/':
                        direction = 3  # left
                    else:
                        pass
                break
        if pivot is not None:
            break

    # 3. 명령 수행
    # 이동 벡터: (dr, dc) for 각 방향
    move = {
        0: (-1, 0),  # up
        1: (0, 1),   # right
        2: (1, 0),   # down
        3: (0, -1)   # left
    }
    
    for cmd in commands:
        cmd = cmd.strip()
        if cmd == "Left turn":
            direction = (direction - 1) % 4
        elif cmd == "Right turn":
            direction = (direction + 1) % 4
        elif cmd == "About turn":
            direction = (direction + 2) % 4
        elif cmd == "Forward step":
            dr, dc = move[direction]
            pivot = (pivot[0] + dr, pivot[1] + dc)
        else:
            # 잘못된 명령은 없다고 가정.
            pass

    # 4. 최종 격자 구성 (모두 '.'으로 채움)
    final_grid = [['.' for _ in range(M)] for _ in range(N)]
    r, c = pivot
    # 군인의 모양을 그리기: 방향에 따라 다름
    if direction in (0, 2):  # 수평 모양
        # 피벗 좌표를 중심으로 좌우 1칸씩 사용
        # (r, c-1), (r, c), (r, c+1)
        if direction == 0:  # up → 그림: "\-/"
            final_grid[r][c-1] = '\\'
            final_grid[r][c]   = '-'
            final_grid[r][c+1] = '/'
        else:  # direction == 2 (down) → 그림: "/-\"
            final_grid[r][c-1] = '/'
            final_grid[r][c]   = '-'
            final_grid[r][c+1] = '\\'
    else:  # direction in (1, 3): 수직 모양
        # 피벗을 중심으로 위아래 1칸씩 사용: (r-1, c), (r, c), (r+1, c)
        if direction == 1:  # right → 그림: 위 '/', 중 '|', 아래 '\' 
            final_grid[r-1][c] = '/'
            final_grid[r][c]   = '|'
            final_grid[r+1][c] = '\\'
        else:  # direction == 3 (left) → 그림: 위 '\', 중 '|', 아래 '/'
            final_grid[r-1][c] = '\\'
            final_grid[r][c]   = '|'
            final_grid[r+1][c] = '/'
    
    # 5. 결과 출력
    out_lines = [''.join(row) for row in final_grid]
    sys.stdout.write('\n'.join(out_lines))
    
if __name__ == '__main__':
    solve()