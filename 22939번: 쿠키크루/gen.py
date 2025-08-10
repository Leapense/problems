#!/usr/bin/env python3
import argparse
import os
import random
import sys
from itertools import permutations
from typing import List, Tuple, Dict

TOPS = ["W", "C", "B", "J"]
LABEL = {"J": "Assassin", "C": "Healer", "B": "Mage", "W": "Tanker"}
ORDER = ["J", "C", "B", "W"]  # 동률 타이브레이커 우선순위

# ---------- 공통 유틸 ----------
def dist(a: Tuple[int,int], b: Tuple[int,int]) -> int:
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def solve_label(grid: List[List[str]]) -> str:
    """주어진 사용자 코드와 동일한 규칙으로 정답 라벨을 계산"""
    n = len(grid)
    pos_h = None
    pos_hash = None
    tops: Dict[str, List[Tuple[int,int]]] = {k: [] for k in ["W","C","B","J"]}

    for i in range(n):
        for j in range(n):
            c = grid[i][j]
            if c == "H":
                pos_h = (i, j)
            elif c == "#":
                pos_hash = (i, j)
            elif c in tops:
                tops[c].append((i, j))

    best_cost = None
    best_key = None
    for k in ORDER:
        pts = tops[k]
        cur = None
        # 각 토핑은 정확히 3개이므로 3! = 6가지 순열
        for p1, p2, p3 in permutations(pts, 3):
            val = dist(pos_h, p1) + dist(p1, p2) + dist(p2, p3) + dist(p3, pos_hash)
            if cur is None or val < cur:
                cur = val
        if best_cost is None or cur < best_cost or (cur == best_cost and ORDER.index(k) < ORDER.index(best_key)):
            best_cost = cur
            best_key = k
    return LABEL[best_key]

def validate_grid(grid: List[List[str]]):
    n = len(grid)
    cnt = {"H":0, "#":0, "W":0, "C":0, "B":0, "J":0}
    for i in range(n):
        for j in range(n):
            ch = grid[i][j]
            if ch in cnt:
                cnt[ch] += 1
            elif ch != "X":
                raise AssertionError(f"허용되지 않은 문자 발견: {ch}")
    assert cnt["H"] == 1, f"H 개수 오류: {cnt['H']}"
    assert cnt["#"] == 1, f"# 개수 오류: {cnt['#']}"
    for t in TOPS:
        assert cnt[t] == 3, f"{t} 개수 오류: {cnt[t]}"

def empty_grid(n: int) -> List[List[str]]:
    return [["X"] * n for _ in range(n)]

def place_unique(grid: List[List[str]], r: int, c: int, ch: str):
    if grid[r][c] != "X":
        raise AssertionError(f"충돌 배치 시도 at {(r,c)} vs {grid[r][c]}")
    grid[r][c] = ch

def random_empty_cell(grid: List[List[str]], rnd: random.Random) -> Tuple[int,int]:
    n = len(grid)
    while True:
        r = rnd.randrange(n)
        c = rnd.randrange(n)
        if grid[r][c] == "X":
            return (r, c)

# ---------- 패턴별 생성기 ----------
def gen_random(n: int, rnd: random.Random) -> List[List[str]]:
    g = empty_grid(n)
    # 랜덤 H, #
    place_unique(g, *random_empty_cell(g, rnd), "H")
    place_unique(g, *random_empty_cell(g, rnd), "#")
    # 토핑 12개 무작위
    for t in TOPS:
        for _ in range(3):
            place_unique(g, *random_empty_cell(g, rnd), t)
    return g

def gen_cluster(n: int, rnd: random.Random) -> List[List[str]]:
    """토핑 종류별로 2x2 근방에 뭉쳐 배치(군집), H·#는 멀리 떨어뜨림"""
    g = empty_grid(n)
    # 모서리 양끝 H, #
    corners = [(0,0),(0,n-1),(n-1,0),(n-1,n-1)]
    h = rnd.choice(corners)
    others = [x for x in corners if x != h]
    sharp = rnd.choice(others)
    place_unique(g, *h, "H")
    place_unique(g, *sharp, "#")

    # 4개 구역에 토핑별 군집 배치
    centers = [
        (n//4, n//4),
        (n//4, 3*n//4),
        (3*n//4, n//4),
        (3*n//4, 3*n//4),
    ]
    rnd.shuffle(centers)
    for t, (cr, cc) in zip(TOPS, centers):
        cells = []
        for dr, dc in [(0,0),(0,1),(1,0),(1,1),(0,-1),(-1,0),(1,1),(-1,-1)]:
            rr, cc2 = cr+dr, cc+dc
            if 0 <= rr < n and 0 <= cc2 < n:
                cells.append((rr, cc2))
        rnd.shuffle(cells)
        for _ in range(3):
            r, c = next((x for x in cells if g[x[0]][x[1]]=="X"), None) or random_empty_cell(g, rnd)
            place_unique(g, r, c, t)
    return g

def gen_line(n: int, rnd: random.Random) -> List[List[str]]:
    """H 왼쪽 가장자리, # 오른쪽 가장자리. 각 토핑은 세 점을 거의 직선상에 배치해서 순서가 자연스럽게 정해지게."""
    g = empty_grid(n)
    h_r = rnd.randrange(n)
    place_unique(g, h_r, 0, "H")
    sharp_r = rnd.randrange(n)
    place_unique(g, sharp_r, n-1, "#")

    cols = rnd.sample(range(1, n-1), 3) if n >= 5 else [1,2, n-2][:3]
    cols.sort()
    rows = rnd.sample(range(n), 4)
    for t, r in zip(TOPS, rows):
        for c in cols:
            place_unique(g, r, c, t)
    return g

def gen_diag(n: int, rnd: random.Random) -> List[List[str]]:
    """대각선/지그재그형 배치로 맨해튼 비용 비교에 미묘한 차이를 줌"""
    g = empty_grid(n)
    place_unique(g, 0, 0, "H")
    place_unique(g, n-1, n-1, "#")

    # 각 토핑을 분산: 주대각/부대각/근방
    diag_cells = [(i, i) for i in range(1, n-1)]
    anti_cells = [(i, n-1-i) for i in range(1, n-1)]
    pool = list(set(diag_cells + anti_cells))
    rnd.shuffle(pool)

    for t in TOPS:
        for _ in range(3):
            r, c = pool.pop() if pool else random_empty_cell(g, rnd)
            if g[r][c] != "X":
                r, c = random_empty_cell(g, rnd)
            place_unique(g, r, c, t)
    return g

def gen_edge(n: int, rnd: random.Random) -> List[List[str]]:
    """경계값/가장자리 검증: 코너·엣지 위주 배치"""
    g = empty_grid(n)
    # 코너 네 곳에 H, #, 그리고 두 토핑 하나씩
    corners = [(0,0),(0,n-1),(n-1,0),(n-1,n-1)]
    rnd.shuffle(corners)
    place_unique(g, *corners[0], "H")
    place_unique(g, *corners[1], "#")
    place_unique(g, *corners[2], rnd.choice(TOPS))
    place_unique(g, *corners[3], rnd.choice(TOPS))

    # 나머지 토핑은 테두리(첫/끝 행·열)에 집중
    edge_cells = []
    for c in range(n):
        edge_cells.append((0,c))
        edge_cells.append((n-1,c))
    for r in range(1, n-1):
        edge_cells.append((r,0))
        edge_cells.append((r,n-1))
    rnd.shuffle(edge_cells)

    need = {t: 3 for t in TOPS}
    # 이미 코너에 놓인 토핑 반영
    for r in range(n):
        for c in range(n):
            if g[r][c] in need:
                need[g[r][c]] -= 1
    for t in TOPS:
        for _ in range(need[t]):
            while edge_cells and g[edge_cells[-1][0]][edge_cells[-1][1]] != "X":
                edge_cells.pop()
            if not edge_cells:
                r, c = random_empty_cell(g, rnd)
            else:
                r, c = edge_cells.pop()
            place_unique(g, r, c, t)
    return g

def gen_tie(n: int, rnd: random.Random) -> List[List[str]]:
    """
    동률(타이) 상황을 유도하여 'J ≺ C ≺ B ≺ W' 우선순위를 검증.
    전략: H를 (r,0), #을 (r,n-1)에 두고, 각 토핑의 세 점을 같은 열 집합에 다른 행으로 배치하여
    최소 경로가 '왼→오' 직선상의 동일 길이가 되도록 만듦.
    """
    g = empty_grid(n)
    r = rnd.randrange(n)
    place_unique(g, r, 0, "H")
    place_unique(g, r, n-1, "#")

    # 동일 열 3개 선택(가운데 쪽), 각 토핑마다 행만 다르게
    cols = sorted(rnd.sample(range(1, n-1), 3))
    base_rows = rnd.sample(range(n), 12)
    idx = 0
    for t in ORDER:  # 일부러 ORDER 순서로 깔아도 동률이면 Assassin이 선택되어야 함
        for c in cols:
            rr = base_rows[idx] if base_rows[idx] != r else (base_rows[idx]+1) % n
            idx += 1
            # 충돌 방지
            while g[rr][c] != "X":
                rr = (rr + 1) % n
            place_unique(g, rr, c, t)
    return g

# ---------- 메인 빌더 ----------
def build_grid(n: int, pattern: str, rnd: random.Random) -> List[List[str]]:
    if pattern == "random":
        return gen_random(n, rnd)
    if pattern == "cluster":
        return gen_cluster(n, rnd)
    if pattern == "line":
        return gen_line(n, rnd)
    if pattern == "diag":
        return gen_diag(n, rnd)
    if pattern == "edge":
        return gen_edge(n, rnd)
    if pattern == "tie":
        return gen_tie(n, rnd)
    raise ValueError(f"알 수 없는 패턴: {pattern}")

def dump_input(grid: List[List[str]]) -> str:
    n = len(grid)
    lines = [str(n)]
    lines += ["".join(row) for row in grid]
    return "\n".join(lines)

def main():
    p = argparse.ArgumentParser(description="쿠키크루 지원 분야 - 테스트 케이스 생성기")
    p.add_argument("--seed", type=int, default=None)
    p.add_argument("--cases", type=int, default=1, help="생성할 케이스 수(파일 모드일 때 유용)")
    groupN = p.add_mutually_exclusive_group()
    groupN.add_argument("--N", type=int, help="고정 N (4..100)")
    groupN.add_argument("--minN", type=int, default=4)
    p.add_argument("--maxN", type=int, default=100)
    p.add_argument("--pattern", choices=["random","cluster","line","diag","edge","tie"], default="random")
    p.add_argument("--outdir", default=None, help="여러 케이스를 파일로 저장할 디렉터리")
    p.add_argument("--with-answers", action="store_true", help="표준출력(단일 케이스) 또는 .ans 파일(다중 케이스)로 정답 라벨도 함께 출력")
    args = p.parse_args()

    rnd = random.Random(args.seed)

    if args.cases <= 0:
        print("cases는 1 이상이어야 합니다.", file=sys.stderr)
        sys.exit(2)

    if args.N is not None and not (4 <= args.N <= 100):
        print("--N은 4..100 범위여야 합니다.", file=sys.stderr)
        sys.exit(2)

    if args.outdir and args.cases > 1:
        os.makedirs(args.outdir, exist_ok=True)

    for idx in range(args.cases):
        n = args.N if args.N is not None else rnd.randint(args.minN, args.maxN)
        grid = build_grid(n, args.pattern, rnd)
        validate_grid(grid)
        ans = solve_label(grid)  # 정답 라벨 산출

        if args.outdir and args.cases > 1:
            path_in = os.path.join(args.outdir, f"case_{idx+1:04d}.in")
            with open(path_in, "w", encoding="utf-8") as f:
                f.write(dump_input(grid))
                f.write("\n")
            if args.with_answers:
                path_ans = os.path.join(args.outdir, f"case_{idx+1:04d}.ans")
                with open(path_ans, "w", encoding="utf-8") as f:
                    f.write(ans + "\n")
        else:
            # 단일 케이스는 표준출력에 바로 내보냄
            print(dump_input(grid))
            if args.with_answers:
                # 채점기 입력과 섞이지 않게 주석 형태로 힌트 제공
                print(f"# EXPECT: {ans}", file=sys.stdout)

if __name__ == "__main__":
    main()