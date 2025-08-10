import argparse
import os
import random
from collections import deque
from typing import List, Tuple, Callable

def solve_oracle(N: int, K: int, A: List[int]) -> str:
    visited = [False] * N
    dq = deque([0])
    visited[0] = True
    while dq:
        i = dq.popleft()
        if i == N - 1:
            return "YES"
        maxJ = min(N - 1, i + K)
        Ai = A[i]
        for j in range(i + 1, maxJ + 1):
            if visited[j]:
                continue
            step = j - i
            diff = Ai - A[j]
            if diff < 0:
                diff = -diff
            if step * (1 + diff) <= K:
                visited[j] = True
                dq.append(j)
    return "NO"

def clamp(v, lo, hi):
    return max(lo, min(hi, v))

def gen_random(N: int, K: int, lo: int, hi: int, rnd: random.Random) -> List[int]:
    return [rnd.randint(lo, hi) for _ in range(N)]

def gen_equal(N: int, K: int, lo: int, hi: int, rnd: random.Random) -> List[int]:
    v = rnd.randint(lo, hi)
    return [v] * N

def gen_increasing(N: int, K: int, lo: int, hi: int, rnd: random.Random) -> List[int]:
    arr = [rnd.randint(lo, lo + 5) for _ in range(N)]
    for i in range(1, N):
        arr[i] = clamp(arr[i - 1] + rnd.randint(0, 2), lo, hi)
    return arr

def gen_decreasing(N: int, K: int, lo: int, hi: int, rnd: random.Random) -> List[int]:
    arr = [rnd.randint(hi - 5, hi) for _ in range(N)]
    for i in range(1, N):
        arr[i] = clamp(arr[i - 1] - rnd.randint(0, 2), lo, hi)
    return arr

def gen_zigzag(N: int, K: int, lo: int, hi: int, rnd: random.Random) -> List[int]:
    a, b = lo, hi
    arr = []
    for i in range(N):
        arr.append(a if i % 2 == 0 else b)
    for i in range(N):
        if rnd.random() < 0.1:
            arr[i] = clamp(arr[i] + rnd.randint(-2, 2), lo, hi)

    return arr

def gen_block_alt(N: int, K: int, lo: int, hi: int, rnd: random.Random) -> List[int]:
    arr = []
    block = max(1, int(max(2, K//3)))
    v1, v2 = lo, hi
    use_v1 = True
    i = 0
    while i < N:
        val = v1 if use_v1 else v2
        for _ in range(block):
            if i >= N: break
            arr.append(val)
            i += 1
        use_v1 = not use_v1
    return arr

def gen_tightK_yes(N: int, K: int, lo: int, hi: int, rnd:random.Random) -> List[int]:
    bigdiff = clamp(K - 1, 0, hi - lo)
    lowv, highv = lo, clamp(lo + bigdiff, lo, hi)
    arr = []
    for i in range(N):
        arr.append(lowv if i % 2 == 0 else highv)
    return arr

def gen_n2_yes(lo: int, hi: int, rnd: random.Random) -> Tuple[int,int,List[int]]:
    N = 2
    K = 1000
    A = [rnd.randint(lo, hi), rnd.randint(lo, hi)]
    return N, K, A

def gen_n2_no(lo: int, hi: int, rnd: random.Random) -> Tuple[int,int,List[int]]:
    N = 2
    K = 1
    a = rnd.randint(lo, hi - 1)
    b = clamp(a + 1, lo, hi)
    return N, K, [a, b]

def gen_nmax_random(K: int, lo: int, hi: int, rnd: random.Random) -> Tuple[int,int,List[int]]:
    N = 5000
    A = [rnd.randint(lo, hi) for _ in range(N)]
    return N, K, A

def gen_nmax_zigzag(K: int, lo: int, hi: int, rnd: random.Random) -> Tuple[int,int,List[int]]:
    N = 5000
    A = gen_zigzag(N, K, lo, hi, rnd)
    return N, K, A

PATTERNS: dict[str, Callable] = {
    "random": gen_random,
    "equal": gen_equal,
    "inc": gen_increasing,
    "dec": gen_decreasing,
    "zigzag": gen_zigzag,
    "blocks": gen_block_alt,
    "tightK": gen_tightK_yes,
}

def make_single_case(pattern: str, N: int | None, K: int | None, lo: int, hi: int, seed: int | None,) -> Tuple[int,int,List[int],str]:
    rnd = random.Random(seed)
    if pattern == "n2_yes":
        N2, K2, A2 = gen_n2_yes(lo, hi, rnd)
        return N2, K2, A2, solve_oracle(N2, K2, A2)
    if pattern == "n2_no":
        N2, K2, A2 = gen_n2_no(lo, hi, rnd)
        return N2, K2, A2, solve_oracle(N2, K2, A2)
    
    if pattern == "nmax_random":
        if K is None: K = rnd.randint(1, 1000)
        N2, K2, A2 = gen_nmax_random(K, lo, hi, rnd)
        return N2, K2, A2, solve_oracle(N2, K2, A2)
    
    if pattern == "nmax_zigzag":
        if K is None: K = rnd.randint(1, 1000)
        N2, K2, A2 = gen_nmax_zigzag(K, lo, hi, rnd)
        return N2, K2, A2, solve_oracle(N2, K2, A2)
    
    if N is None:
        N = rnd.randint(2, 200)
    if K is None:
        K = rnd.randint(1, 1000)

    if pattern not in PATTERNS:
        raise ValueError(f"unknown pattern: {pattern}")
    
    A = PATTERNS[pattern](N, K, lo, hi, rnd)
    assert 2 <= N <= 5000
    assert 1 <= K <= 1000
    assert len(A) == N
    assert all(1 <= x <= 1000 for x in A)
    ans = solve_oracle(N, K, A)
    return N, K, A, ans

SUITE_RECIPES = [
    # (설명, kwargs)
    ("min_N_yes", {"pattern":"n2_yes"}),
    ("min_N_no", {"pattern":"n2_no"}),
    ("equal_easy_yes", {"pattern":"equal", "N":50, "K":1}),
    ("inc_soft_yes", {"pattern":"inc", "N":60, "K":10}),
    ("dec_soft_yes", {"pattern":"dec", "N":60, "K":10}),
    ("zigzag_noish", {"pattern":"zigzag", "N":80, "K":3}),
    ("blocks_edge", {"pattern":"blocks", "N":120, "K":5}),
    ("tightK_edge", {"pattern":"tightK", "N":150, "K":5}),
    ("random_mix_smallK", {"pattern":"random", "N":120, "K":2}),
    ("random_mix_midK", {"pattern":"random", "N":200, "K":20}),
    ("nmax_random", {"pattern":"nmax_random", "K":1000}),
    ("nmax_zigzag", {"pattern":"nmax_zigzag", "K":4}),
]

def write_case(path_in: str, path_ans: str, N: int, K: int, A: List[int], ans: str):
    with open(path_in, "w", encoding="utf-8") as f:
        f.write(f"{N} {K}\n")
        f.write(" ".join(map(str, A)) + "\n")
    with open(path_ans, "w", encoding="utf-8") as f:
        f.write(ans + "\n")

def main():
    p = argparse.ArgumentParser(description="징검다리 건너기(small) 테스트 케이스 생성기")
    p.add_argument("--seed", type=int, default=None, help="난수 시드(재현성)")
    p.add_argument("--pattern", type=str, default="random",
                   choices=["random","equal","inc","dec","zigzag","blocks","tightK",
                            "n2_yes","n2_no","nmax_random","nmax_zigzag"],
                   help="생성 패턴 선택")
    p.add_argument("--N", type=int, default=None, help="돌 개수(미지정 시 패턴 기본값)")
    p.add_argument("--K", type=int, default=None, help="최대 힘 K(미지정 시 랜덤 1..1000)")
    p.add_argument("--lo", type=int, default=1, help="A[i] 최소값(기본 1)")
    p.add_argument("--hi", type=int, default=1000, help="A[i] 최대값(기본 1000)")
    p.add_argument("--suite", type=str, default=None,
                   help="폴더명을 주면 다량 스위트(.in/.ans)를 생성")
    p.add_argument("--count", type=int, default=1,
                   help="단일 출력 모드에서 케이스 여러 개를 연달아 출력(디버깅용)")
    args = p.parse_args()

    if args.suite:
        rnd = random.Random(args.seed)
        outdir = args.suite
        os.makedirs(outdir, exist_ok=True)
        for idx, (name, kw) in enumerate(SUITE_RECIPES, start=1):
            seed = None if args.seed is None else (args.seed * 911 + idx)
            N = kw.get("N", None)
            K = kw.get("K", None)
            pattern = kw["pattern"]
            N2, K2, A2, ans2 = make_single_case(
                pattern=pattern, N=N, K=K, lo=args.lo, hi=args.hi, seed=seed
            )
            base = f"{idx:02d}_{name}"
            write_case(
                os.path.join(outdir, base + ".in"),
                os.path.join(outdir, base + ".ans"),
                N2, K2, A2, ans2
            )
        print(f"생성 완료: {outdir}/*.in, *.ans")
        return
    
    for _ in range(args.count):
        N, K, A, ans = make_single_case(
            pattern=args.pattern, N=args.N, K=args.K,
            lo=args.lo, hi=args.hi, seed=args.seed
        )
        print(f"{N} {K}")
        print(" ".join(map(str, A)))
        if args.count > 1:
            print()

if __name__ == "__main__":
    main()