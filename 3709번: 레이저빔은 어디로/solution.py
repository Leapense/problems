import sys
from typing import List, Set, Tuple

def _turn_right(dx : int, dy : int) -> Tuple[int, int]:
    """시계 방향으로 90도 회전"""
    return dy, -dx

def _simulate(
        n : int,
        gadgets : Set[Tuple[int, int]],
        laser_x : int,
        laser_y : int,
) -> Tuple[int, int]:
    """
    반환값은 튜플 형식으로 된 (X, Y)로, 그 값은 board에서 레이저빔이 어디에 쏘고 있는 위치임.
    만약 (0, 0) 이면, 그 상황은 갇힌 상태라고 정의함.
    """
    if laser_y == 0:
        dx, dy = 0, 1
    elif laser_y == n + 1:
        dx, dy = 0, -1
    elif laser_x == 0:
        dx, dy = 1, 0
    elif laser_x == n + 1:
        dx, dy = -1, 0
    else:
        raise ValueError("Laser not on the border")
    
    x, y = laser_x, laser_y
    visited: Set[Tuple[int, int, int, int]] = set()

    while True:
        x += dx
        y += dy

        if x == 0 or y == 0 or x == n + 1 or y == n + 1:
            return x, y
        
        state = (x, y, dx, dy)

        if state in visited:
            return 0, 0
        visited.add(state)

        if (x, y) in gadgets:
            dx, dy = _turn_right(dx, dy)

def solve(data : str) -> str:
    """
    메인 함수 시작
    """
    it = iter(data.strip().split())
    t = int(next(it))
    out_lines: List[str] = []
    for _ in range(t):
        n = int(next(it))
        r = int(next(it))
        gadgets = {(int(next(it)), int(next(it))) for _ in range(r)}
        lx, ly = int(next(it)), int(next(it))
        res_x, res_y = _simulate(n, gadgets, lx, ly)
        out_lines.append(f"{res_x} {res_y}")

    return "\n".join(out_lines)


if __name__ == "__main__":
    sys.setrecursionlimit(10000) # x와 y는 각각 1 이상 50 이하의 정수, dir은 4가지 방향으로 설정하므로, 50×50×4 = 10,000 가지의 상태로 나오므로, recursionlimit를 10,000 으로 설정
    print(solve(sys.stdin.read()))