import sys
from math import gcd
from typing import Dict, List, Tuple

def coord_map() -> Dict[str, Tuple[int, int]]:
    """숫자 문자에서 2D 좌표로 매핑"""
    return {
        '1': (0, 0), '2': (1, 0), '3': (2, 0),
        '4': (0, 1), '5': (1, 1), '6': (2, 1),
        '7': (0, 2), '8': (1, 2), '9': (2, 2),
        '0': (1, 3)
    }

def compute_line_key_and_interval(p1: Tuple[int, int], p2: Tuple[int, int]) -> Tuple[Tuple[int, int, int], Tuple[int, int]]:
    """
    선분 p1->p2에 대해:
        - 라인 키: (n_x, n_y, c) (법선 벡터와 상수 조합)
        - 투영 구간: (t_start, t_end) (방향 벡터를 따라 1차원으로 투영)
    """
    x1, y1 = p1
    x2, y2 = p2
    dx = x2 - x1
    dy = y2 - y1

    if dx == 0 and dy == 0:
        return None
    
    n_x, n_y = -dy, dx
    g = gcd(abs(n_x), abs(n_y))
    n_x //= g
    n_y //= g
    if n_x < 0 or (n_x == 0 and n_y < 0):
        n_x, n_y = -n_x, -n_y

    c = n_x * x1 + n_y * y1
    d_x, d_y = -n_y, n_x

    t1 = d_x * x1 + d_y * y1
    t2 = d_x * x2 + d_y * y2
    t_start = min(t1, t2)
    t_end = max(t1, t2)

    return (n_x, n_y, c), (t_start, t_end)

def merge_intervals(intervals: List[Tuple[int, int]]) -> int:
    """
    닫힌 구간 리스트를 병합하여
    연결된 컴포넌트(구간)의 수를 반환.
    """
    if not intervals:
        return 0
    
    intervals.sort(key=lambda iv : iv[0])
    merged_count = 1
    cur_start, cur_end = intervals[0]
    for s, e in intervals[1:]:
        if cur_end >= s:
            cur_end = max(cur_end, e)
        else:
            merged_count += 1
            cur_start, cur_end = s, e
    return merged_count

def mnds_for_number(num: str) -> int:
    """한 전화번호 문자열에 대한 MNDS 계산"""
    cmap = coord_map()
    line_groups: Dict[Tuple[int,int,int], List[Tuple[int,int]]] = {}
    all_degenerate = True

    for i in range(len(num) - 1):
        p1 = cmap[num[i]]
        p2 = cmap[num[i + 1]]
        result = compute_line_key_and_interval(p1, p2)
        if result is None:
            continue

        all_degenerate = False
        key, interval = result
        line_groups.setdefault(key, []).append(interval)

    if all_degenerate:
        return 0
    
    total = 0
    for intervals in line_groups.values():
        total += merge_intervals(intervals)
    
    return total

def classify(mnds: int) -> str:
    """MNDS 값에 따른 등급 분류"""
    if mnds <= 3:
        return 'EXCELLENT'
    if mnds == 4:
        return 'GOOD'
    return 'BAD'

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out_lines = []
    for _ in range(t):
        num = data[idx].strip()
        idx += 1
        mnds = mnds_for_number(num)
        out_lines.append(classify(mnds))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()