#!/usr/bin/env python3

from collections import defaultdict
from typing import List, Tuple
import sys


def read_ints() -> List[int]:
    """한 줄을 정수 리스트로 변환한다."""
    return list(map(int, sys.stdin.readline().split()))


def solve() -> None:
    """표준 입력을 읽어 답을 출력한다."""
    p, k = read_ints()
    n, = read_ints()

    events: defaultdict[int, int] = defaultdict(int)

    for _ in range(n):
        a_i, b_i = read_ints()

        # [a_i, b_i] 가 [p, k] 와 전혀 겹치지 않으면 무시
        if b_i < p or a_i > k:
            continue

        events[a_i] += 1
        events[b_i + 1] -= 1

    # 범죄 구간의 시작·끝을 명시적으로 넣어 둔다
    events[p] += 0
    events[k + 1] += 0

    # 이벤트 시각 정렬
    times: List[int] = sorted(events)

    current = 0          # 현재 시각 직전까지 현장 인원
    min_cnt = float("inf")
    max_cnt = 0
    prev: int | None = None

    for t in times:
        if prev is not None:
            # 세그먼트 [prev, t-1] 에서는 current 가 일정
            seg_start = prev
            seg_end = t - 1

            # 세그먼트와 [p, k] 의 교집합
            ov_start = max(seg_start, p)
            ov_end = min(seg_end, k)

            if ov_start <= ov_end:
                min_cnt = min(min_cnt, current)
                max_cnt = max(max_cnt, current)

        # 이번 시각의 모든 델타 적용
        current += events[t]
        prev = t

    # 현장에 겹친 사람이 없을 수도 있다
    if min_cnt == float("inf"):
        print("0 0")
    else:
        print(f"{min_cnt} {max_cnt}")


if __name__ == "__main__":
    solve()