import argparse
import os
import random
import string
from typing import List, Tuple

ALPH = list(string.ascii_lowercase)

def make_base(h: int, w: int, mode: str) -> List[List[str]]:
    g = [['a'] * w for _ in range(h)]
    if mode == 'all_same':
        ch = random.choice(ALPH)
        for r in range(h):
            for c in range(w):
                g[r][c] = ch
        return g
    
    if mode == 'random':
        for r in range(h):
            for c in range(w):
                g[r][c] = random.choice(ALPH)
        return g
    
    if mode == 'row_stripes':
        palette = random.sample(ALPH, k=min(3, len(ALPH)))
        for r in range(h):
            ch = palette[r % len(palette)]
            for c in range(w):
                g[r][c] = ch
        return g
    
    if mode == 'col_stripes':
        palette = random.sample(ALPH, k=min(3, len(ALPH)))
        for r in range(h):
            for c in range(w):
                g[r][c] = palette[c % len(palette)]
        return g
    
    if mode == 'checker':
        a, b = random.sample(ALPH, 2)
        for r in range(h):
            for c in range(w):
                g[r][c] = a if (r + c) % 2 == 0 else b

        return g
    
    if mode == 'periodic':
        rp = random.randint(2, min(4, h)) if h >= 2 else 1
        cp = random.randint(2, min(4, w)) if w >= 2 else 1
        tile = [[random.choice(ALPH) for _ in range(cp)] for _ in range(rp)]
        for r in range(h):
            for c in range(w):
                g[r][c] = tile[r % rp][c % cp]
        return g
    
    return make_base(h, w, 'random')

def expand_by_ij(base: List[List[str]], i: int, j: int) -> List[List[str]]:
    H0, W0 = len(base), len(base[0])
    out = []
    for r in range(H0):
        row = base[r]
        exp_row = []
        for val in row:
            exp_row.extend([val] * j)
        for _ in range(i):
            out.append(exp_row[:])
    return out

def dedupe_rows_cols(grid: List[List[str]]) -> List[List[str]]:
    if not grid:
        return grid
    
    rows = []
    prev = None
    for r in grid:
        if prev is None or r != prev:
            rows.append(r)
            prev = r

    H = len(rows)
    W = len(rows[0])
    keep = [0]
    for c in range(1, W):
        same = True
        for r in range(H):
            if rows[r][c] != rows[r][keep[-1]]:
                same = False
                break
        if not same:
            keep.append(c)
    shrunk = []
    for r in range(H):
        shrunk.append([rows[r][c] for c in keep])

    return shrunk

def assert_roundtrip(base: List[List[str]], i: int, j: int) -> Tuple[List[List[str]], List[List[str]]]:
    big = expand_by_ij(base, i, j)
    shrunk = dedupe_rows_cols(big)
    assert shrunk == base, "확대->디듀프 결과가 원본과 다릅니다(생성 로직 오류)."
    return big, shrunk

def to_text(grid: List[List[str]]) -> str:
    return "\n".join("".join(row) for row in grid)

def pick_dims_for_limit(target_h: int, target_w: int) -> Tuple[int, int, int, int]:
    def divisors(n: int) -> List[int]:
        ds = []
        d = 1
        while d * d <= n:
            if n % d == 0:
                ds.append(d)
                if d * d != n:
                    ds.append(n // d)

            d += 1
        ds.sort()
        return ds
    
    h_divs = divisors(target_h)
    w_divs = divisors(target_w)
    i = random.choice(h_divs)
    j = random.choice(w_divs)
    H0 = target_h // i
    W0 = target_w // j
    return H0, W0, i, j

def choose_target_size(mode: str) -> Tuple[int, int]:
    if mode == 'min':
        return 1, 1
    if mode == 'thin_row':
        return 1, 1000
    if mode == 'thin_col':
        return 1000, 1
    if mode == 'max':
        return 1000, 1000
    H = random.randint(1, 1000)
    W = random.randint(1, 1000)
    return H, W

BASE_MODES = ['random', 'all_same', 'row_stripes', 'col_stripes', 'checker', 'periodic']

def generate_case(global_mode: str) -> str:
    if global_mode == 'worst':
        size_mode = random.choice(['min', 'thin_row', 'thin_col', 'max'])
        H, W = choose_target_size(size_mode)
        base_mode = random.choice(BASE_MODES)
    elif global_mode in ['min', 'max', 'thin_row', 'thin_col']:
        H, W = choose_target_size(global_mode)
        base_mode = random.choice(BASE_MODES)
    else:
        H, W = choose_target_size('random')
        base_mode = random.choice(BASE_MODES)

    H0, W0, i, j = pick_dims_for_limit(H, W)

    if global_mode == 'worst' and (H0 <= 3 or W0 <= 3):
        base_mode = random.choice(['checker', 'periodic', 'row_stripes', 'col_stripes', 'all_same'])

    base = make_base(H0, W0, base_mode)
    big, _ = assert_roundtrip(base, i, j)

    out = []
    out.append(f"{H} {W}")
    out.append(to_text(big))
    return "\n".join(out)

def main():
    ap = argparse.ArgumentParser(description="확대 이미지 복원 문제용 테스트 케이스 생성기")
    ap.add_argument("--seed", type=int, default=None, help="난수 시드 (재현성)")
    ap.add_argument("--mode", choices=["random", "worst", "min", "max", "thin_row", "thin_col"], default="random", help="케이스 성격")
    ap.add_argument("--batch", type=int, default=0, help="여러 케이스를 out/ 디렉토리에 저장(0이면 표준출력으로 1개만 출력)")
    args = ap.parse_args()

    if args.seed is not None:
        random.seed(args.seed)

    if args.batch <= 0:
        print(generate_case(args.mode))
    else:
        os.makedirs("out", exist_ok=True)
        used = set()
        for t in range(1, args.batch + 1):
            key = None
            for _ in range(10000):
                H, W = choose_target_size(args.mode if args.mode in ['min', 'max', 'thin_row', 'thin_col'] else 'random')
                key = (H, W, random.randint(0, 1_000_000_000))
                if key not in used:
                    used.add(key)
                    break
            text = generate_case(args.mode)
            path = os.path.join("out", f"case_{t:04d}.txt")
            with open(path, "w", encoding="utf-8") as f:
                f.write(text)
        print(f"생성 완료: out/case_0001.txt ~ out/case_{args.batch:04d}.txt", flush=True)

if __name__ == "__main__":
    main()