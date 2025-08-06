#!/usr/bin/env python3
from __future__ import annotations
import argparse
import random
import sys

MIN_SPEED = 1
MAX_SPEED = 100
MIN_Z = 1
MAX_Z = 100_000
MAX_T = 10_000
MAX_Z_SUM = 1_000_000

def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="달팽이 문제용 입력 파일 생성기"
    )
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument(
        "--t",
        type=int,
        help="무작위 테스트 수(1-10,000)"
    )
    group.add_argument(
        "--boundary",
        action="store_true",
        help="경계값 테스트 세트 생성"
    )
    parser.add_argument(
        "--seed",
        type=int,
        default=None,
        help="난수 시드(지정 시 재현 가능)"
    )
    return parser.parse_args()

def build_boundary_cases() -> list[tuple[int, int, int, int, int]]:
    speed_values = [MIN_SPEED, MIN_SPEED + 1, MAX_SPEED - 1, MAX_SPEED]
    z_values = [MIN_Z, MIN_Z + 1, MAX_Z - 1, MAX_Z]
    cases = []
    for a1 in speed_values:
        for b1 in speed_values:
            for a2 in speed_values:
                for b2 in speed_values:
                    for z in z_values:
                        if validate_case(a1, b1, a2, b2, z):
                            cases.append((a1, b1, a2, b2, z))
    assert len(cases) <= MAX_T
    assert sum(item[4] for item in cases) <= MAX_Z_SUM
    return cases

def build_random_cases(t: int, seed: int | None) -> list[tuple[int, int, int, int, int]]:
    if not 1 <= t <= MAX_T:
        raise ValueError("t 범위 오류")
    rng = random.Random(seed)
    cases = []
    remain_z_total = MAX_Z_SUM
    for _ in range(t):
        max_z_here = min(MAX_Z, remain_z_total - (t - len(cases) - 1) * MIN_Z)
        z_val = rng.randint(MIN_Z, max_z_here)
        a1 = rng.randint(MIN_SPEED, MAX_SPEED)
        b1 = rng.randint(MIN_SPEED, MAX_SPEED)
        a2 = rng.randint(MIN_SPEED, MAX_SPEED)
        b2 = rng.randint(MIN_SPEED, MAX_SPEED)
        cases.append((a1, b1, a2, b2, z_val))
        remain_z_total -= z_val
    rng.shuffle(cases)
    assert sum(item[4] for item in cases) <= MAX_Z_SUM
    return cases

def validate_case(a1: int, b1: int, a2: int, b2: int, z: int) -> bool:
    return (
        MIN_SPEED <= a1 <= MAX_SPEED
        and MIN_SPEED <= b1 <= MAX_SPEED
        and MIN_SPEED <= a2 <= MAX_SPEED
        and MIN_SPEED <= b2 <= MAX_SPEED
        and MIN_Z <= z <= MAX_Z
    )

def emit_cases(cases: list[tuple[int, int, int, int, int]]) -> None:
    print(len(cases))
    for a1, b1, a2, b2, z in cases:
        print(a1, b1, a2, b2, z)

def main() -> None:
    args = parse_args()
    if args.seed is not None:
        random.seed(args.seed)
    if args.boundary:
        cases = build_boundary_cases()
    else:
        cases = build_random_cases(args.t, args.seed)
    emit_cases(cases)

if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print(str(exc), file=sys.stderr)
        sys.exit(1)