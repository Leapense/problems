#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Secret Number 입력 생성기 (경계값 포함)
- 출력 형식: 여러 데이터셋 + 마지막 줄 "0 0"
- 옵션:
    --seed SEED           재현 가능한 난수 시드
    --random-cases N      추가 랜덤 케이스 개수 (기본 10)
    --skip-heavy          35x35 최대형 케이스 제외
    --max-WH 70           W+H 최대 합(기본 70; 원문 제약 유지)
사용 예:
    python gen_secret_number_cases.py --seed 42 --random-cases 20 > input.txt
"""
import argparse
import random
import string
from typing import List, Tuple

LETTERS = string.ascii_uppercase  # 'A'..'Z'
DIGITS  = '0123456789'

def ensure_at_least_one_nonzero_digit(grid: List[List[str]]) -> None:
    H, W = len(grid), len(grid[0])
    # 이미 있으면 패스
    for i in range(H):
        for j in range(W):
            if grid[i][j] in DIGITS and grid[i][j] != '0':
                return
    # 없다면 임의 위치 하나를 1..9로 바꾼다
    i = random.randrange(H)
    j = random.randrange(W)
    grid[i][j] = random.choice('123456789')

def make_random_grid(W: int, H: int, p_digit: float = 0.55, p_zero: float = 0.35) -> List[str]:
    """
    무작위 격자 생성.
    - p_digit: 셀을 '숫자'로 뽑을 확률
    - p_zero : 숫자일 때 '0'이 될 확률 (리딩 제로/0 연장 상황을 자주 만들기 위함)
    """
    grid = []
    for _ in range(H):
        row = []
        for _ in range(W):
            if random.random() < p_digit:
                if random.random() < p_zero:
                    row.append('0')
                else:
                    row.append(random.choice('123456789'))
            else:
                row.append(random.choice(LETTERS))
        grid.append(row)
    ensure_at_least_one_nonzero_digit(grid)
    return [''.join(r) for r in grid]

def make_single_cell_case() -> Tuple[int, int, List[str]]:
    # 최소 크기 + 비영(非0) 숫자
    W, H = 1, 1
    grid = [['5']]
    return W, H, [''.join(grid[0])]

def make_line_case_horizontal(W: int) -> Tuple[int,int,List[str]]:
    # 1행 W열, 숫자/문자/0 섞기 + 길게 이어지는 숫자 구간 포함
    H = 1
    row = []
    # 앞쪽은 0들, 중간은 숫자 경로, 뒤는 문자 혼합
    for j in range(W):
        if j < max(1, W//6):
            row.append('0')
        elif j < max(2, W//6*3):
            row.append(random.choice(DIGITS))
        else:
            row.append(random.choice(LETTERS))
    if not any(c in '123456789' for c in row):
        row[max(0, W//3)] = '7'
    return W, H, [''.join(row)]

def make_line_case_vertical(H: int) -> Tuple[int,int,List[str]]:
    # H행 1열, 각 행은 길이 1인 문자열이어야 한다.
    W = 1
    col = []
    for i in range(H):
        if i < max(1, H//6):
            col.append('0')
        elif i < max(2, H//6*3):
            col.append(random.choice(DIGITS))
        else:
            col.append(random.choice(LETTERS))
    if not any(c in '123456789' for c in col):
        col[max(0, H//3)] = '8'
    # 세로 라인: H개의 줄, 각 줄 길이 W(=1)
    return W, H, col

def make_path_case(W: int, H: int) -> Tuple[int,int,List[str]]:
    """
    오른쪽/아래로만 이동하는 경로를 하나 만들고 그 경로에 숫자를 채워
    긴 숫자열이 반드시 존재하도록 만든다. 나머지는 문자/숫자 랜덤.
    """
    grid = [[random.choice(LETTERS) for _ in range(W)] for _ in range(H)]
    # (0,0)→(H-1,W-1) 경로 생성 (Right/Down 랜덤 순열)
    steps = ['R']*(W-1) + ['D']*(H-1)
    random.shuffle(steps)
    i = j = 0
    path = [(i, j)]
    for s in steps:
        if s == 'R':
            j += 1
        else:
            i += 1
        path.append((i, j))
    # 경로에 숫자 채우기: 선두 0 포함 가능, 중간에 0 다수 포함
    for (r, c) in path:
        grid[r][c] = random.choice(DIGITS)
    ensure_at_least_one_nonzero_digit(grid)
    return W, H, [''.join(row) for row in grid]

def make_zero_heavy_with_nonzero_tail(W: int, H: int) -> Tuple[int,int,List[str]]:
    """
    0이 매우 많고 간혹 비영 숫자가 붙는 케이스.
    0으로 시작하는 연장이 최대값 선택에 영향을 주는지 검증.
    """
    grid = []
    for i in range(H):
        row = []
        for j in range(W):
            if random.random() < 0.75:
                row.append('0')
            else:
                # 드물게 비영 숫자나 문자
                row.append(random.choice('123456789' + LETTERS))
        grid.append(row)
    ensure_at_least_one_nonzero_digit(grid)
    return W, H, [''.join(r) for r in grid]

def make_competition_equal_length(W: int, H: int) -> Tuple[int,int,List[str]]:
    """
    동일 길이의 두 '큰 수'가 경쟁하는 상황.
    - 좌상단에서 오른쪽으로 이어지는 수 A
    - 좌상단에서 아래쪽으로 이어지는 수 B
    길이는 같지만 사전식 비교로 승부가 갈리게 설계.
    """
    W = max(W, 5)
    H = max(H, 5)
    grid = [[random.choice(LETTERS) for _ in range(W)] for _ in range(H)]
    L = min(W, H, 6)
    # 가로로 L자리: 9,9,3,0,0,7 처럼
    horiz = list("993007")[:L]
    for j in range(L):
        grid[0][j] = horiz[j]
    # 세로로 L자리: 9,9,2,9,9,9 처럼 (동일 길이지만 비교 시 하나가 이기도록)
    vert = list("992999")[:L]
    for i in range(L):
        grid[i][0] = vert[i]
    ensure_at_least_one_nonzero_digit(grid)
    return W, H, [''.join(r) for r in grid]

def make_all_letters_but_one_digit(W: int, H: int) -> Tuple[int,int,List[str]]:
    """
    거의 전부 문자인데 숫자가 고립된 케이스.
    연장 불가(길이 1) 최대값 판별 확인.
    """
    grid = [[random.choice(LETTERS) for _ in range(W)] for _ in range(H)]
    r = random.randrange(H)
    c = random.randrange(W)
    grid[r][c] = random.choice('123456789')
    return W, H, [''.join(row) for row in grid]

def sample_WH(max_WH_sum: int) -> Tuple[int,int]:
    """
    제약 W+H <= max_WH_sum 을 만족하는 무작위 (W,H) 샘플러 (W,H>=1).
    """
    H = random.randint(1, max_WH_sum - 1)
    W = random.randint(1, max_WH_sum - H)
    return W, H

def emit_case(W: int, H: int, lines: List[str]) -> str:
    assert len(lines) == H
    assert all(len(r) == W for r in lines)
    return '\n'.join([f"{W} {H}", *lines])

def main():
    ap = argparse.ArgumentParser(description="Secret Number 입력 생성기")
    ap.add_argument("--seed", type=int, default=None, help="난수 시드")
    ap.add_argument("--random-cases", type=int, default=10, help="추가 랜덤 케이스 개수")
    ap.add_argument("--skip-heavy", action="store_true", help="35x35 최대형 케이스 생략")
    ap.add_argument("--max-WH", type=int, default=70, help="W+H 최대 합(문제 제약 기본=70)")
    args = ap.parse_args()
    if args.seed is not None:
        random.seed(args.seed)

    outputs = []

    # 1) 최소형: 1x1
    W, H, g = make_single_cell_case()
    outputs.append(emit_case(W, H, g))

    # 2) 1xH 세로 라인 (경계)
    W, H, g = make_line_case_vertical(H=random.randint(10, 30))
    outputs.append(emit_case(W, H, g))

    # 3) Wx1 가로 라인 (경계)
    W, H, g = make_line_case_horizontal(W=random.randint(10, 30))
    outputs.append(emit_case(W, H, g))

    # 4) 경로 강제 케이스: 긴 숫자열 보장
    W, H = 12, 12
    if W + H > args.max_WH:
        W, H = sample_WH(args.max_WH)
    W, H, g = make_path_case(W, H)
    outputs.append(emit_case(W, H, g))

    # 5) 0이 많은 케이스 (리딩 제로/연장)
    W, H = 20, 20
    if W + H > args.max_WH:
        W, H = sample_WH(args.max_WH)
    W, H, g = make_zero_heavy_with_nonzero_tail(W, H)
    outputs.append(emit_case(W, H, g))

    # 6) 동일 길이 경쟁 케이스 (사전식 비교)
    W, H = 8, 8
    if W + H > args.max_WH:
        W, H = sample_WH(args.max_WH)
    W, H, g = make_competition_equal_length(W, H)
    outputs.append(emit_case(W, H, g))

    # 7) 거의 전부 문자 + 고립 숫자
    W, H = 17, 19
    if W + H > args.max_WH:
        W, H = sample_WH(args.max_WH)
    W, H, g = make_all_letters_but_one_digit(W, H)
    outputs.append(emit_case(W, H, g))

    # 8) 최대형(부하) 케이스: 35x35 (W+H=70)
    if not args.skip_heavy:
        W, H = 35, 35
        # 안전장치: 사용자가 max_WH를 낮췄다면 스킵
        if W + H <= args.max_WH:
            g = make_random_grid(W, H, p_digit=0.6, p_zero=0.35)
            outputs.append(emit_case(W, H, g))

    # 9) 사용자 지정 개수만큼 랜덤 케이스 추가
    for _ in range(max(0, args.random_cases)):
        W, H = sample_WH(args.max_WH)
        # 경계 근처를 자주 뽑도록 약간의 치우침
        if random.random() < 0.3:
            # 큰 쪽 선호
            H = random.randint(max(1, args.max_WH // 2 - 5), args.max_WH - 1)
            W = random.randint(1, args.max_WH - H)
        grid = make_random_grid(W, H, p_digit=random.uniform(0.4, 0.7), p_zero=random.uniform(0.25, 0.5))
        outputs.append(emit_case(W, H, grid))

    # 출력 + 종료 표시
    print('\n'.join(outputs))
    print("0 0")

if __name__ == "__main__":
    main()
