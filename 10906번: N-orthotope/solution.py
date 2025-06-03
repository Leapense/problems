from typing import List, Tuple

def compute_intersection_dimension(
    a_ranges: List[Tuple[int, int]],
    b_ranges: List[Tuple[int, int]]
) -> int:
    """
    두 개의 N-orthotope (a_ranges, b_ranges)의 교집합이
    - 존재하지 않으면 -1
    - 존재하면 교집합이 M-orthotope이므로 M을 반환

    각 리스트 요소는 (s_i, e_i), (s'_i, e'_i) 형태의 튜플이며,
    교집합 구간은 [max(s_i, s'_i), min(e_i, e'_i)] 이다.

    :param a_ranges: 첫 번째 orthotope의 차원별 구간 리스트
    :param b_ranges: 두 번째 orthotope의 차원별 구간 리스트
    :return: 교집합이 없으면 -1, 있으면 M (교집합 차원)
    """
    dimension_count = 0
    for (s_i, e_i), (s_pi, e_pi) in zip(a_ranges, b_ranges):
        start_i = max(s_i, s_pi)
        end_i = min(e_i, e_pi)

        if start_i > end_i:
            return -1
        
        if start_i < end_i:
            dimension_count += 1

    return dimension_count

def main() -> None:
    """
    표준 입력으로부터 두 orthotope 정보를 읽고,
    compute_intersection_dimension()을 호출하여 결과를 출력한다.
    """
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    
    index = 0
    try:
        n = int(data[index])
    except (ValueError, IndexError):
        sys.stdout.write("-1")
        return
    
    index += 1
    a_ranges: List[Tuple[int, int]] = []
    b_ranges: List[Tuple[int, int]] = []

    for _ in range(n):
        try:
            s_val = int(data[index])
            e_val = int(data[index + 1])
        except (ValueError, IndexError):
            sys.stdout.write("-1")
            return
        
        a_ranges.append((s_val, e_val))
        index += 2

    for _ in range(n):
        try:
            sp_val = int(data[index])
            ep_val = int(data[index + 1])
        except (ValueError, IndexError):
            sys.stdout.write("-1")
            return
        
        b_ranges.append((sp_val, ep_val))
        index += 2

    intersection_dim = compute_intersection_dimension(a_ranges, b_ranges)

    sys.stdout.write(str(intersection_dim))

if __name__ == "__main__":
    main()