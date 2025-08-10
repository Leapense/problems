#!/usr/bin/env python3
import argparse
import os
import random
from collections import deque
from typing import List, Tuple

# -----------------------------
# 레퍼런스 솔버 (이분 탐색 + BFS)
# N이 클 때는 느릴 수 있으므로, 작은 케이스에만 사용 권장
# -----------------------------
def can_reach(a: List[int], k: int) -> bool:
    n = len(a)
    vis = [False]*n
    dq = deque([0])
    vis[0] = True
    while dq:
        i = dq.popleft()
        if i == n-1:
            return True
        # d는 최대 n-1-i까지만 시도하면 됨
        max_d = min(k, n-1-i)
        if max_d <= 0:
            continue
        # 주의: 파이썬은 느릴 수 있으므로 조기 가지치기 없음
        for d in range(1, max_d+1):
            j = i + d
            if vis[j]:
                continue
            diff = abs(a[i] - a[j])
            if d * (1 + diff) <= k:
                vis[j] = True
                dq.append(j)
                if j == n-1:
                    return True
    return False

def solve_min_k(a: List[int]) -> int:
    n = len(a)
    minA = min(a)
    maxA = max(a)
    lo = 0
    hi = (n-1) * (1 + (maxA - minA))
    while lo < hi:
        mid = (lo + hi) // 2
        if can_reach(a, mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

# -----------------------------
# 배열 빌더들 (패턴별)
# -----------------------------
def arr_constant(n: int, v: int) -> List[int]:
    return [v]*n

def arr_increasing(n: int, start: int, step: int) -> List[int]:
    return [start + i*step for i in range(n)]

def arr_decreasing(n: int, start: int, step: int) -> List[int]:
    return [start - i*step for i in range(n)]

def arr_alternating_extremes(n: int, lo: int, hi: int) -> List[int]:
    return [lo if i%2==0 else hi for i in range(n)]

def arr_blocks(n: int, vals: List[int], block_size: int) -> List[int]:
    a = []
    idx = 0
    while len(a) < n:
        v = vals[idx % len(vals)]
        take = min(block_size, n - len(a))
        a.extend([v]*take)
        idx += 1
    return a

def arr_sawtooth(n: int, base: int, peak: int, period: int) -> List[int]:
    a = []
    for i in range(n):
        t = i % period
        if t < period//2:
            # 올라감
            val = base + (peak-base) * t // max(1, (period//2))
        else:
            # 내려감
            t2 = t - period//2
            val = peak - (peak-base) * t2 // max(1, (period - period//2))
        a.append(val)
    return a

def arr_local_trap(n: int, low: int, high: int, trap_len: int) -> List[int]:
    """
    앞/뒤는 이동 쉬움(값 비슷), 가운데 '함정 구간'은 급격한 고저차로 점프 비용을 키워
    가까운 점프를 어렵게 만드는 패턴.
    """
    left = [low + (i % 3) for i in range(max(1, n//4))]
    trap = arr_alternating_extremes(trap_len, low, high)
    right_len = n - len(left) - len(trap)
    right = [low + (i % 3) for i in range(max(0, right_len))]
    return (left + trap + right)[:n]

def arr_random_uniform(n: int, lo: int, hi: int, rng: random.Random) -> List[int]:
    return [rng.randint(lo, hi) for _ in range(n)]

def arr_narrow_band(n: int, center: int, width: int, rng: random.Random) -> List[int]:
    lo = max(1, center - width)
    hi = center + width
    return [rng.randint(lo, hi) for _ in range(n)]

def arr_long_jump_friendly(n: int, lo: int, hi: int) -> List[int]:
    """
    가까운 곳은 큰 |Δ|로 막고, 멀리 가면 |Δ|가 줄어드는 구조.
    """
    a = []
    half = n//2
    # 전반: 교차 극값
    a.extend(arr_alternating_extremes(half, lo, hi))
    # 후반: 완만한 증가
    a.extend(arr_increasing(n - half, (lo+hi)//2, 1))
    return a[:n]

# -----------------------------
# 케이스 생성기
# -----------------------------
A_MIN = 1
A_MAX = 1_000_000

def one_input(a: List[int]) -> str:
    return f"{len(a)}\n" + " ".join(map(str, a)) + "\n"

def emit_case(a: List[int], want_oracle: bool) -> Tuple[str, str]:
    """
    return: (input_text, output_text_or_empty)
    """
    if want_oracle:
        ans = solve_min_k(a)
        return (one_input(a), str(ans) + "\n")
    else:
        return (one_input(a), "")

def gen_edge_cases(rng: random.Random) -> List[List[int]]:
    cases = []

    # N=2 최소/최대 값
    cases.append([A_MIN, A_MIN])                   # 동일값
    cases.append([A_MIN, A_MAX])                   # 최댓차
    cases.append([A_MAX, A_MIN])                   # 최댓차(반대)

    # 작은 N 다양성
    cases.append(arr_constant(5, 7))               # 모두 동일
    cases.append(arr_increasing(6, 1, 1))          # 단조 증가(Δ=1)
    cases.append(arr_decreasing(6, 100, 1))        # 단조 감소(Δ=1)
    cases.append(arr_alternating_extremes(7, 1, A_MAX))  # 교차 극값
    cases.append(arr_blocks(10, [5, 6, 7], 2))     # 반복 블록
    cases.append(arr_sawtooth(9, 10, 100, 4))      # 톱니

    # 좁은 대역 / 넓은 대역
    cases.append(arr_narrow_band(12, 500_000, 0, rng))   # 전부 동일값 중심
    cases.append(arr_narrow_band(12, 500_000, 5, rng))   # 아주 좁은 밴드
    cases.append(arr_random_uniform(12, A_MIN, A_MAX, rng))  # 전체 범위

    return cases

def gen_adversarial_cases(rng: random.Random) -> List[List[int]]:
    cases = []
    # 장거리 점프가 유리한 구조
    cases.append(arr_long_jump_friendly(50, 1, A_MAX))
    # 국소 함정
    cases.append(arr_local_trap(60, 10_000, 990_000, 20))
    # 큰 N(정답은 선택적)
    cases.append(arr_alternating_extremes(500, 1, A_MAX))
    cases.append(arr_sawtooth(800, 1, A_MAX, 17))
    return cases

def gen_random_cases(count: int, rng: random.Random) -> List[List[int]]:
    cases = []
    for _ in range(count):
        n = rng.choice([10, 20, 30, 50, 80, 120, 200])
        mode = rng.randint(0, 6)
        if mode == 0:
            a = arr_random_uniform(n, A_MIN, A_MAX, rng)
        elif mode == 1:
            a = arr_narrow_band(n, rng.randint(1000, A_MAX-1000), rng.choice([0,1,3,7,15]), rng)
        elif mode == 2:
            a = arr_increasing(n, rng.randint(1, 1000), rng.choice([0,1,1,2,3]))
        elif mode == 3:
            a = arr_decreasing(n, rng.randint(1000, 2000), rng.choice([0,1,1,2,3]))
        elif mode == 4:
            a = arr_alternating_extremes(n, rng.randint(1, 10_000), rng.randint(900_000, A_MAX))
        elif mode == 5:
            a = arr_blocks(n, [rng.randint(1, A_MAX//2), rng.randint(A_MAX//2, A_MAX)], rng.choice([1,2,3,5,8]))
        else:
            a = arr_sawtooth(n, rng.randint(1, 1000), rng.randint(500_000, A_MAX), rng.choice([4,5,7,9,12]))
        cases.append(a)
    return cases

def gen_stress_cases(count: int, rng: random.Random) -> List[List[int]]:
    cases = []
    # 대형 N (최대 5000 근처). 정답 계산은 기본적으로 생략.
    for _ in range(count):
        n = rng.choice([1500, 2000, 3000, 4000, 5000])
        pattern = rng.randint(0, 4)
        if pattern == 0:
            a = arr_alternating_extremes(n, 1, A_MAX)
        elif pattern == 1:
            a = arr_blocks(n, [1, A_MAX, A_MAX//2], rng.choice([2,3,5,8,13,21]))
        elif pattern == 2:
            a = arr_sawtooth(n, 1, A_MAX, rng.choice([17,29,41]))
        elif pattern == 3:
            a = arr_long_jump_friendly(n, 1, A_MAX)
        else:
            a = arr_random_uniform(n, A_MIN, A_MAX, rng)
        cases.append(a)
    return cases

# -----------------------------
# 메인
# -----------------------------
def main():
    parser = argparse.ArgumentParser(description="징검다리 최소 K 테스트 케이스 생성기")
    parser.add_argument("--seed", type=int, default=0)
    parser.add_argument("--suite", type=str, default="edge,adversarial,random",
                        help="콤마 구분: edge,adversarial,random,stress")
    parser.add_argument("--count", type=int, default=10, help="random/stress에 사용할 개수")
    parser.add_argument("--out-dir", type=str, default="")
    parser.add_argument("--max-n-for-oracle", type=int, default=1500,
                        help="이 크기 이하에서만 파이썬 레퍼런스로 정답 계산(.out 생성)")
    parser.add_argument("--force-oracle", action="store_true",
                        help="큰 N도 강제로 정답 계산(매우 느릴 수 있음)")
    args = parser.parse_args()

    rng = random.Random(args.seed)
    suites = [s.strip() for s in args.suite.split(",") if s.strip()]

    all_cases: List[List[int]] = []
    if "edge" in suites:
        all_cases.extend(gen_edge_cases(rng))
    if "adversarial" in suites:
        all_cases.extend(gen_adversarial_cases(rng))
    if "random" in suites:
        all_cases.extend(gen_random_cases(args.count, rng))
    if "stress" in suites:
        all_cases.extend(gen_stress_cases(args.count, rng))

    if args.out_dir:
        os.makedirs(args.out_dir, exist_ok=True)
        for idx, a in enumerate(all_cases, 1):
            want_oracle = args.force_oracle or (len(a) <= args.max_n_for_oracle)
            inp, outp = emit_case(a, want_oracle)
            in_path = os.path.join(args.out_dir, f"case{idx:02d}.in")
            with open(in_path, "w", encoding="utf-8") as f:
                f.write(inp)
            if outp:
                out_path = os.path.join(args.out_dir, f"case{idx:02d}.out")
                with open(out_path, "w", encoding="utf-8") as f:
                    f.write(outp)
        print(f"{len(all_cases)}개 케이스를 '{args.out_dir}'에 생성했습니다.")
    else:
        # STDOUT로 하나만 내보냄(편의용): 마지막 케이스
        a = all_cases[-1]
        want_oracle = args.force_oracle or (len(a) <= args.max_n_for_oracle)
        inp, outp = emit_case(a, want_oracle)
        print(inp, end="")
        if outp:
            print("# Expected Output")
            print(outp, end="")

if __name__ == "__main__":
    main()