def solve():
    import sys
    input_data = sys.stdin.read().strip().split()
    # input_data에 순서대로 T, m, n, 격자들이 들어 있음

    t = int(input_data[0])
    idx = 1  # input_data에서 현재 읽을 위치

    outputs = []
    for _ in range(t):
        m = int(input_data[idx]); idx += 1
        n = int(input_data[idx]); idx += 1

        # 격자 읽기 (문자열 형태)
        grid = []
        for _ in range(m):
            row_str = input_data[idx]
            idx += 1
            # '0'/'1' 로 구성된 문자열 -> 정수 리스트(0/1)로 변환
            grid.append([int(ch) for ch in row_str])

        # 레이저 쏜 횟수
        shot_count = 0

        # 위에서 아래로, 각 행은 오른쪽에서 왼쪽으로 순회
        for i in range(m):
            for j in range(n-1, -1, -1):
                # 현재 (i, j)가 0이면, 레이저를 쏴서 켜준다.
                if grid[i][j] == 0:
                    shot_count += 1
                    # 1) 행 i의 [0..j] 토글
                    for c in range(j+1):
                        grid[i][c] ^= 1
                    # 2) 열 j의 [i..m-1] 토글
                    for r in range(i, m):
                        grid[r][j] ^= 1
                    # 3) (i, j)를 한 번 더 토글 (이중 토글 보정)
                    grid[i][j] ^= 1

        # shot_count가 모든 전구를 켜기 위해 쏜 최소 횟수
        outputs.append(str(shot_count))

    print("\n".join(outputs))


if __name__ == "__main__":
    solve()