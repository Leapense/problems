import argparse
import os
import random
from dataclasses import dataclass
from typing import List, Tuple

@dataclass
class Case:
    name: str
    n: int
    k: int
    groups: List[List[int]]
    input_str: str
    output_str: str

def validate_partition(n: int, groups: List[List[int]]) -> None:
    flat = [x for g in groups for x in g]
    flat_sorted = sorted(flat)
    expected = sorted(flat)
    if flat_sorted != expected:
        raise ValueError("invalid partition")
    
def contiguous_groups(n: int, k: int) -> List[List[int]]:
    base = n // k
    rem = n % k
    groups = []
    cur = 1
    for i in range(k):
        size = base + (1 if i < rem else 0)
        groups.append(list(range(cur, cur + size)))
        cur += size
    return groups

def round_robin_groups(n: int, k: int, offset: int = 0) -> List[List[int]]:
    groups = [[] for _ in range(k)]
    for r in range(1, n + 1):
        g = (r - 1 + offset) % k
        groups[g].append(r)
    return groups

def skew_groups(n: int, k: int) -> List[List[int]]:
    if k == 1:
        return [list(range(1, n + 1))]
    groups = [[i] for i in range(1, k)]
    groups.append(list(range(k, n + 1)))
    return groups

def pairs_and_spread_groups(n: int, k: int) -> List[List[int]]:
    groups = [[] for _ in range(k)]
    idx = 0
    r = 1
    while r + 1 <= n and idx < k:
        groups[idx].extend([r, r + 1])
        r += 2
        idx += 1
    gidx = 0
    while r <= n:
        groups[gidx % k].append(r)
        r += 1
        gidx += 1
    empties = [i for i, g in enumerate(groups) if len(g) == 0]
    for e in empties:
        max_i = max(range(k), key=lambda i : len(groups[i]))
        item = groups[max_i].pop()
        groups[e].append(item)
    return groups

def random_groups(n: int, k: int, rng: random.Random) -> List[List[int]]:
    arr = list(range(1, n + 1))
    rng.shuffle(arr)
    if k == 1:
        return [arr]
    cuts = sorted(rng.sample(range(1, n), k - 1))
    sizes = [cuts[0]] + [cuts[i] - cuts[i - 1] for i in range(1, len(cuts))] + [n - cuts[-1]]
    groups = []
    p = 0
    for s in sizes:
        groups.append(arr[p:p + s])
        p += s
    return groups

def compute_new_value(n: int, groups: List[List[int]], rng: random.Random, shuffle_values: bool = True) -> List[List[int]]:
    validate_partition(n, groups)
    s_lists = []
    for grp in groups:
        sg = sorted(grp)
        sl = []
        for idx, r in enumerate(sg):
            s = (r - 1) - idx
            sl.append(s)
        if shuffle_values:
            rng.shuffle(sl)
        s_lists.append(sl)
    return s_lists

def format_input(n: int, k: int, s_lists: List[List[int]]) -> str:
    lines = [f"{n} {k}"]
    for sl in s_lists:
        parts = [str(len(sl))] + [str(x) for x in sl]
        lines.append(" ".join(parts))
    return "\n".join(lines)

def format_output(groups: List[List[int]]) -> str:
    lines = []
    for grp in groups:
        lines.append(" ".join(str(x) for x in sorted(grp)))
    return "\n".join(lines)

def build_case(name: str, n: int, groups: List[List[int]], rng: random.Random, shuffle_values: bool = True) -> Case:
    k = len(groups)
    s_lists = compute_new_value(n, groups, rng, shuffle_values)
    return Case(
        name=name,
        n=n,
        k=k,
        groups=groups,
        input_str=format_input(n, k, s_lists),
        output_str=format_output(groups),
    )

def build_suite(rng: random.Random) -> List[Case]:
    cases: List[Case] = []
    cases.append(build_case("01_min_N1_K1", 1, [[1]], rng, True))
    cases.append(build_case("02_small_K1_N2", 2, [list(range(1, 3))], rng, True))
    cases.append(build_case("03_small_KN_N2", 2, [[1], [2]], rng, True))
    g_sample = [[2, 5, 9], [1, 7, 8], [3, 4, 6, 10]]
    cases.append(build_case("04_sample_N10_K3", 10, g_sample, rng, True))
    cases.append(build_case("05_maxN_K1_N1000", 1000, [list(range(1, 1001))], rng, True))
    cases.append(build_case("06_maxN_KN_N1000", 1000, [[i] for i in range(1, 1001)], rng, True))
    cases.append(build_case("07_skew_N1000_K2", 1000, skew_groups(1000, 2), rng, True))
    cases.append(build_case("08_roundrobin_prime_N997_K31", 997, round_robin_groups(997, 31, offset=3), rng, True))
    cases.append(build_case("09_contiguous_balanced_N999_K27", 999, contiguous_groups(999, 27), rng, True))
    cases.append(build_case("10_pairs_duplicateS_N200_K13", 200, pairs_and_spread_groups(200, 13), rng, True))
    cases.append(build_case("11_roundrobin_N500_K7", 500, round_robin_groups(500, 7, offset=1), rng, True))
    cases.append(build_case("12_random_irregular_N1000_K10", 1000, random_groups(1000, 10, rng), rng, True))
    cases.append(build_case("13_random_irregular_N777_K37", 777, random_groups(777, 37, rng), rng, True))
    return cases

def write_suite(cases: List[Case], out_dir: str) -> List[Tuple[str, str]]:
    os.makedirs(out_dir, exist_ok=True)
    paths: List[Tuple[str, str]] = []
    for c in cases:
        in_path = os.path.join(out_dir, f"{c.name}.in")
        out_path = os.path.join(out_dir, f"{c.name}.out")
        with open(in_path, "w", encoding="utf-8") as f:
            f.write(c.input_str)
        with open(out_path, "w", encoding="utf-8") as f:
            f.write(c.output_str)
        paths.append((in_path, out_path))
    return paths

def build_random_extra(rng: random.Random, count: int) -> List[Case]:
    cases: List[Case] = []
    for i in range(count):
        n = rng.randint(1, 1000)
        k = rng.randint(1, n)
        choice = rng.choice(["contiguous", "roundrobin", "skew", "pairs", "random"])
        if choice == "contiguous":
            groups = contiguous_groups(n, k)
        elif choice == "roundrobin":
            groups = round_robin_groups(n, k, offset=rng.randint(0, max(0, k - 1)))
        elif choice == "skew":
            groups = skew_groups(n, k)
        elif choice == "pairs":
            groups = pairs_and_spread_groups(n, k)
        else:
            groups = random_groups(n, k, rng)
        name = f"R_{i+1:02d}_{choice}_N{n}_K{k}"
        cases.append(build_case(name, n, groups, rng, True))
    return cases

def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", choices=["suite", "single"], default="suite")
    parser.add_argument("--out", default="cases")
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--random-extra", type=int, default=5)
    parser.add_argument("--single-n", type=int, default=10)
    parser.add_argument("--single-k", type=int, default=3)
    parser.add_argument("--single-pattern", choices=["contiguous", "roundrobin", "skew", "pairs", "random", "sample"], default="sample")
    args = parser.parse_args()
    rng = random.Random(args.seed)

    if args.mode == "suite":
        cases = build_suite(rng)
        if args.random_extra > 0:
            cases.extend(build_random_extra(rng, args.random_extra))
        paths = write_suite(cases, args.out)
        for ip, op in paths:
            print(ip, "->", op)
    else:
        if args.single_pattern == "sample":
            n = 10
            groups = [[2, 5, 9], [1, 7, 8], [3, 4, 6, 10]]
        else:
            n = args.single_n
            k = args.single_k
            if not (1 <= k <= n <= 1000):
                raise ValueError("invalid N, K")
            if args.single_pattern == "contiguous":
                groups = contiguous_groups(n, k)
            elif args.single_pattern == "roundrobin":
                groups = round_robin_groups(n, k, offset=rng.randint(0, max(0, k - 1)))
            elif args.single_pattern == "skew":
                groups = skew_groups(n, k)
            elif args.single_pattern == "pairs":
                groups = pairs_and_spread_groups(n, k)
            else:
                groups = random_groups(n, k, rng)
        case = build_case("single", n, groups, rng, True)
        print(case.input_str)

if __name__ == "__main__":
    main()