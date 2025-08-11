import argparse
import os
import random
import re
from pathlib import Path
from typing import List, Tuple

INT32_MAX = 2_147_483_647
INT32_MIN = -2_147_483_647 - 1

def calc_expected(food: List[int]) -> int:
    n = len(food)
    if n == 0:
        return 0
    
    dp0 = 0
    dp1 = food[0]
    dp2 = 0

    for i in range(1, n):
        new0 = max(dp0, dp1, dp2)
        new1 = dp0 + food[i]
        new2 = dp1 + food[i] // 2
        dp0, dp1, dp2 = new0, new1, new2
    return max(dp0, dp1, dp2)

def slugify(name: str) -> str:
    s = name.lower()
    s = re.sub(r"[^a-z0-9\-_.]+", "-", s)
    s = re.sub(r"-{2,}", "-", s).strip("-")
    return s

def write_case(out_dir: Path, idx: int, name: str, arr: List[int], write_answers: bool = True):
    slug = slugify(name)
    in_path = out_dir / f"{idx:03d}_{slug}.in"
    out_path = out_dir / f"{idx:03d}_{slug}.out"

    with open(in_path, "w", encoding="utf-8") as f:
        f.write(str(len(arr)) + "\n")
        f.write(" ".join(str(x) for x in arr) + "\n")

    if write_answers:
        ans = calc_expected(arr)
        with open(out_path, "w", encoding="utf-8") as f:
            f.write(str(ans) + "\n")

def gen_deterministic_cases(include_negative: bool = False) -> List[Tuple[str, List[int]]]:
    cases = []
    cases.append(("n1_zero", [0]))
    cases.append(("n1_one", [1]))
    cases.append(("n1_even_two", [2]))
    cases.append(("n1_int_max", [INT32_MAX]))
    if include_negative:
        cases.append(("n1_int_min", [INT32_MIN]))
        cases.append(("n1_minus_one", [-1]))

    cases.extend([
        ("n2_all_zero", [0, 0]),
        ("n2_small_odd_even", [5, 3]),
        ("n2_full_then_half_better", [100, 100]),
        ("n2_skip_then_full_better", [1, 100]),
        ("n2_half_is_zero", [20, 1]),
        ("n2_max_max", [INT32_MAX, INT32_MAX]),
        ("n2_zero_max", [0, INT32_MAX]),
        ("n2_max_zero", [INT32_MAX, 0]),
    ])

    if include_negative:
        cases.extend([
            ("n2_neg_pos", [-5, 10]),
            ("n2_pos_neg", [10, -5]),
            ("n2_both_neg", [-7, -3]),
        ])
    
    cases.extend([
        ("n3_all_zero", [0, 0, 0]),
        ("n3_all_one", [1, 1, 1]),
        ("n3_all_two", [2, 2, 2]),
        ("n3_ascending_small", [1, 2, 3]),
        ("n3_descending_small", [5, 3, 1]),
        ("n3_full_half_skip_pattern", [100, 100, 0]),
        ("n3_alternate_big_small", [100, 1, 100]),
        ("n3_odd_big", [INT32_MAX, INT32_MAX, INT32_MAX]),
        ("n3_even_mix", [2, INT32_MAX - 1, INT32_MAX]),
    ])
    if include_negative:
        cases.append(("n3_with_neg", [INT32_MIN, 0, INT32_MAX]))

    cases.extend([
        ("n10_all_zero", [0] * 10),
        ("n10_all_one", [1] * 10),
        ("n10_all_int_max", [INT32_MAX] * 10),
        ("n10_alternating_high_low", [100, 1] * 5),
        ("n10_strictly_increasing", list(range(1, 11))),
        ("n10_strictly_decreasing", list(range(10, 0, -1))),
        ("n10_even_odd_mix", [2,3,4,5,6,7,8,9,10,11]),
        ("n10_half_effect_heavy", [9] * 10),
    ])

    cases.append(("n20_odd_only", [999_999_999] * 20))
    cases.append(("n20_even_only", [1_000_000_000] * 20))
    cases.append(("n20_saw_tooth", [1, 1000] * 10))
    cases.append(("n20_blocks", [100, 100, 1, 1, 1, 100, 100, 1, 1, 1, 100, 100, 1, 1, 1, 100, 100, 1, 1, 1]))

    return cases

def gen_random_cases(
        count: int,
        max_n: int,
        min_val: int,
        max_val: int,
        seed: int,
) -> List[Tuple[str, List[int]]]:
    rng = random.Random(seed)
    cases = []
    for i in range(count):
        if max_n <= 10:
            n = rng.randint(1, max_n)
        else:
            r = rng.random()
            if r < 0.6:
                n = rng.randint(1, min(max_n, 100))
            elif r < 0.9:
                n = rng.randint(101, min(max_n, 1000))
            else:
                n = rng.randint(1001, max_n)
            n = max(1, min(n, max_n))

        arr = [rng.randint(min_val, max_val) for _ in range(n)]
        cases.append((f"random_{i+1}_n{n}", arr))
    return cases

def gen_stress_case(max_n_stress: int, max_val: int, seed: int) -> Tuple[str, List[int]]:
    rng = random.Random(seed ^ 0xA5A5A5)
    arr = []
    for i in range(max_n_stress):
        if i % 5 == 0:
            v = max_val
        elif i % 5 == 1:
            v = max_val - 1
        elif i % 5 == 2:
            v = 1_000_000_000
        elif i % 5 == 3:
            v = 999_999_999
        else:
            v = rng.randint(0, 10_000)
        arr.append(v)
    return ("stress_big_n", arr)

def main():
    parser = argparse.ArgumentParser(description="경계값 분석 중심 테스트 케이스 생성기")
    parser.add_argument("-o", "--out-dir", default="cases", help="출력 폴더 (기본: cases)")
    parser.add_argument("-r", "--random-count", type=int, default=10, help="랜덤 케이스 개수 (기본: 10)")
    parser.add_argument("--max-n", type=int, default=200, help="랜덤 케이스의 최대 N (기본: 200)")
    parser.add_argument("--min-val", type=int, default=0, help="값 하한 (기본: 0)")
    parser.add_argument("--max-val", type=int, default=INT32_MAX, help=f"값 상한 (기본: {INT32_MAX})")
    parser.add_argument("--seed", type=int, default=42, help="난수 시드 (기본: 42)")
    parser.add_argument("--include-negative", action="store_true", help="음수 값 포함 BVA 케이스 생성")
    parser.add_argument("--include-stress", action="store_true", help="대규모 스트레스 케이스 추가 생성")
    parser.add_argument("--max-n-stress", type=int, default=200_000, help="스트레스 케이스 N (기본: 200000)")
    parser.add_argument("--no-answers", action="store_true", help=".out 정답 파일을 생성하지 않음")
    args = parser.parse_args()

    out_dir = Path(args.out_dir)
    os.makedirs(out_dir, exist_ok=True)

    # 1) 확정(경계/패턴) 케이스
    cases = gen_deterministic_cases(include_negative=args.include_negative)

    # 2) 랜덤 케이스
    cases += gen_random_cases(
        count=args.random_count,
        max_n=args.max_n,
        min_val=args.min_val if not args.include_negative else INT32_MIN,
        max_val=args.max_val,
        seed=args.seed,
    )

    # 3) 스트레스 케이스(옵션)
    if args.include_stress:
        cases.append(gen_stress_case(args.max_n_stress, args.max_val, args.seed))

    # 파일로 저장
    for idx, (name, arr) in enumerate(cases, start=1):
        write_case(out_dir, idx, name, arr, write_answers=not args.no-answers if hasattr(args, "no-answers") else True)

    # 요약 출력
    print(f"[완료] 생성된 케이스: {len(cases)}개 -> 폴더: {out_dir}")
    print(f"  - 정답 파일 생성 여부: {'NO' if args.no_answers else 'YES'}")
    print(f"  - 랜덤 시드: {args.seed}")
    print(f"  - 값 범위: [{args.min_val if not args.include_negative else INT32_MIN}, {args.max_val}]")
    if args.include_stress:
        print(f"  - 스트레스 케이스 N: {args.max_n_stress}")


if __name__ == "__main__":
    main()