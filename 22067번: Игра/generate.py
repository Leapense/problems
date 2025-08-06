#!/usr/bin/env python3
import argparse
import random
import sys
from typing import List, Tuple

MAX_N_SINGLE    = 1_000          # 한 테스트에서 n 최대치
MAX_TOTAL_N     = 1_000          # Σ n 상한
MAX_LEN         = 1_000_000_000  # 간선 길이 상한
MIN_LEN         = 1              # 간선 길이 하한


def gen_row(length: int) -> List[int]:
    return [random.randint(MIN_LEN, MAX_LEN) for _ in range(length)]


def prepare_boundary_cases(total_tests: int) -> List[Tuple[int, List[List[int]]]]:
    """
    * n=1  : 최소 입력
    * n=10 : 동일 길이(42) 입력
    * n=max: 가능한 한 큰 n 입력
    단, Σ n ≤ 1000 와 total_tests 를 항상 만족하도록 n_max 를 자동 조정
    """
    cases: List[Tuple[int, List[List[int]]]] = []

    # 1) n = 1 (최소)
    cases.append((1, [[MIN_LEN, MIN_LEN]]))

    # 2) n = 10, 모든 길이 42 (동점 처리 확인)
    SAME_LEN_N = 10
    if SAME_LEN_N + 1 <= MAX_TOTAL_N:
        row42 = [[42] * (2 * lvl) for lvl in range(1, SAME_LEN_N + 1)]
        cases.append((SAME_LEN_N, row42))

    # 3) 가능한 최대 n
    unused_budget = MAX_TOTAL_N - sum(n for n, _ in cases) - (total_tests - len(cases))
    # 위 식은 “남은 랜덤 테스트마다 최소 1 레벨은 필요” 조건을 고려
    max_n = max(1, min(MAX_N_SINGLE, unused_budget))
    if len(cases) < total_tests:
        cases.append((max_n,
                      [[MAX_LEN] * (2 * lvl) for lvl in range(1, max_n + 1)]))

    return cases


def generate_cases(total_tests: int) -> List[Tuple[int, List[List[int]]]]:
    if total_tests < 3:
        raise ValueError("경계값 포함을 위해 --tests 는 최소 3 이상이어야 합니다.")

    cases = prepare_boundary_cases(total_tests)
    remaining_tests = total_tests - len(cases)
    remaining_budget = MAX_TOTAL_N - sum(n for n, _ in cases)

    for tests_left in range(remaining_tests, 0, -1):
        # 각 단계마다 남은 테스트 수(tests_left)만큼 1 이상 할당할 공간을 남겨 둔다
        max_n_allowed = remaining_budget - (tests_left - 1)
        n = random.randint(1, max_n_allowed)
        remaining_budget -= n
        levels = [gen_row(2 * lvl) for lvl in range(1, n + 1)]
        cases.append((n, levels))

    random.shuffle(cases)
    return cases


def dump(cases: List[Tuple[int, List[List[int]]]], fp) -> None:
    print(len(cases), file=fp)
    for n, rows in cases:
        print(n, file=fp)
        for row in rows:
            print(*row, file=fp)


def main() -> None:
    parser = argparse.ArgumentParser(description="랜덤 + 경계값 테스트케이스 생성기")
    parser.add_argument("-t", "--tests", type=int, default=5,
                        help="생성할 테스트케이스 개수(≥3)")
    parser.add_argument("-s", "--seed", type=int, default=None,
                        help="random 시드 (None=시스템 랜덤)")
    parser.add_argument("-o", "--outfile", type=str, default="-",
                        help="출력 파일 ('-' 또는 생략 시 stdout)")
    args = parser.parse_args()

    if args.tests < 3:
        parser.error("--tests 값은 최소 3이어야 합니다.")

    random.seed(args.seed)
    cases = generate_cases(args.tests)

    out = sys.stdout if args.outfile == "-" else open(args.outfile, "w", encoding="utf-8")
    try:
        dump(cases, out)
    finally:
        if out is not sys.stdout:
            out.close()


if __name__ == "__main__":
    main()