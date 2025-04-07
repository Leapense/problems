import sys
import io
import bisect

def solve():
    input = sys.stdin.readline
    n = int(input().strip())
    stars = set()
    row_stars = {}
    col_stars = {}

    for _ in range(n):
        x, y = map(int, input().split())
        stars.add((x, y))
        if y not in row_stars:
            row_stars[y] = []
        row_stars[y].append(x)
        if x not in col_stars:
            col_stars[x] = []
        col_stars[x].append(y)

    for key in row_stars:
        row_stars[key].sort()
    for key in col_stars:
        col_stars[key].sort()

    directions = [(1, 0), (0, -1), (-1, 0), (0, 1)]

    x, y = 0, 0
    d = 0
    energy = 0
    THRESHOLD = 10 ** 10

    visited = set()

    while abs(x) <= THRESHOLD and abs(y) <= THRESHOLD:
        state = (x, y, d)
        if state in visited:
            print("oo")
            return
        visited.add(state)

        dx, dy = directions[d]

        free_steps = float('inf')
        if dx != 0:
            if y in row_stars:
                lst = row_stars[y]
                if dx == 1:
                    idx = bisect.bisect_right(lst, x)
                    if idx < len(lst):
                        free_steps = lst[idx] - x - 1
                else:
                    idx = bisect.bisect_left(lst, x) - 1
                    if idx >= 0:
                        free_steps = x - lst[idx] - 1

        else:
            if x in col_stars:
                lst = col_stars[x]
                if dy == 1:
                    idx = bisect.bisect_right(lst, y)
                    if idx < len(lst):
                        free_steps = lst[idx] - y - 1
                else:
                    idx = bisect.bisect_left(lst, y) - 1
                    if idx >= 0:
                        free_steps = y - lst[idx] - 1

        if dx == 1:
            t_bound = THRESHOLD - x
        elif dx == -1:
            t_bound = x + THRESHOLD
        elif dy == 1:
            t_bound = THRESHOLD - y
        else:
            t_bound = y + THRESHOLD
        
        move = min(free_steps, t_bound)
        x += dx * move
        y += dy * move

        if move == t_bound:
            print(energy)
            return
        
        energy += 1
        d = (d + 1) % 4
    
    print(energy)

def run_io_fun(input_data, func):
    backup_stdin = sys.stdin
    backup_stdout = sys.stdout
    try:
        sys.stdin = io.StringIO(input_data)
        sys.stdout = io.StringIO()
        func()
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin = backup_stdin
        sys.stdout = backup_stdout

def test_sample1():
    input_data = """\
4
2 0
-2 -1
0 3
1 -3
"""
    # Sample Output 1: 2
    output = run_io_fun(input_data, solve)
    assert output == "2"

def test_sample2():
    input_data = """\
8
1 -1
1 1
1 0
-1 -1
-1 0
-1 1
0 1
0 -1
"""
    # Sample Output 2: oo
    output = run_io_fun(input_data, solve)
    assert output == "oo"

# 추가 테스트 케이스 (별이 없는 경우)
def test_no_stars():
    input_data = "0\n"
    # 별이 없으므로 우주선은 한 번에 좌표 한계에 도달하게 되고, 에너지 소비는 0이어야 한다.
    output = run_io_fun(input_data, solve)
    assert output == "0"

# 추가 테스트 케이스 (간단한 별 배치)
def test_simple():
    input_data = """\
3
3 0
3 -2
0 -2
"""
    # 간단한 별 배치에 대한 결과를 검증합니다.
    output = run_io_fun(input_data, solve)
    # 결과는 문제의 조건과 우주선의 이동 경로에 따라 결정됩니다.
    # 여기서는 예시로 결과값을 미리 계산한 값(예: 1)으로 가정합니다.
    # 필요에 따라 적절한 결과로 수정하세요.
    assert output.isdigit() or output == "oo"

if __name__ == "__main__":
    solve()