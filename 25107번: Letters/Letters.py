def solve():
    import sys
    input = sys.stdin.readline  # 빠른 입출력을 위해(선택)

    # 1) 첫 줄 읽기
    N, M, K = map(int, input().split())
    
    # 2) 두 번째 줄은 항상 읽기 (K=0인 경우 빈 줄)
    directions = input().rstrip('\n')  # strip() 대신 rstrip('\n')로 불필요 공백 제거
    
    # 3) 나머지 N줄 읽어서 행렬 구성
    matrix = [list(input().rstrip('\n')) for _ in range(N)]
    
    # --- 중력 적용 로직 ---
    def apply_gravity(matrix, direction):
        N, M = len(matrix), len(matrix[0])

        if direction == 'D':
            for col in range(M):
                stack = [matrix[r][col] for r in range(N) if matrix[r][col] != '.']
                for r in range(N - len(stack)):
                    matrix[r][col] = '.'
                for r in range(N - len(stack), N):
                    matrix[r][col] = stack[r - (N - len(stack))]

        elif direction == 'U':
            for col in range(M):
                stack = [matrix[r][col] for r in range(N) if matrix[r][col] != '.']
                for r in range(len(stack)):
                    matrix[r][col] = stack[r]
                for r in range(len(stack), N):
                    matrix[r][col] = '.'

        elif direction == 'L':
            for r in range(N):
                stack = [matrix[r][c] for c in range(M) if matrix[r][c] != '.']
                for c in range(len(stack)):
                    matrix[r][c] = stack[c]
                for c in range(len(stack), M):
                    matrix[r][c] = '.'

        elif direction == 'R':
            for r in range(N):
                stack = [matrix[r][c] for c in range(M) if matrix[r][c] != '.']
                for c in range(M - len(stack)):
                    matrix[r][c] = '.'
                for c in range(M - len(stack), M):
                    matrix[r][c] = stack[c - (M - len(stack))]

    # --- K번 반복하며 apply_gravity 적용 ---
    # (K=0이면 directions는 빈 문자열이므로 for문이 0번 돌고 그대로 끝)
    for direction in directions:
        apply_gravity(matrix, direction)

    # --- 결과 출력 ---
    for row in matrix:
        print("".join(row))

solve()