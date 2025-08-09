import argparse
import random

from typing import List, Set

DIGITS = ['1', '2', '3', '4', '5', '6']

def join(chars: List[str]) -> str:
    return ''.join(chars)

def boundary_suite() -> List[str]:
    cases: List[str] = []
    cases.append("xxxxxx")

    cases.extend([
        "123456",
        "654321",
        "135246",
        "246135",
        "321564",
    ])

    base = list("123456")
    for i in range(6):
        s = base.copy()
        s[i] = 'x'
        cases.append(join(s))

    for i in range(6):
        s = ['x'] * 6
        s[i] = str(i + 1)
        cases.append(join(s))

    cases.append("x1x2x3")
    cases.append("1x2x3x")
    cases.append("xxx123")
    cases.append("123xxx")
    cases.append("x23x5x")
    
    seen: Set[str] = set()
    deduped: List[str] = []
    for c in cases:
        if c not in seen:
            seen.add(c)
            deduped.append(c)
    return deduped

def random_case(k_unknown: int) -> str:
    assert 0 <= k_unknown <= 6
    positions = list(range(6))
    random.shuffle(positions)
    x_pos = set(positions[:k_unknown])

    visible_slots = [i for i in range(6) if i not in x_pos]
    digits = DIGITS[:]
    random.shuffle(digits)
    assign = ['x'] * 6

    for i, pos in enumerate(visible_slots):
        assign[pos] = digits[i]

    return join(assign)

def random_pool(n: int, allow_duplicates: bool = False) -> List[str]:
    out: List[str] = []
    seen: Set[str] = set()
    tries = 0
    while len(out) < n and tries < n * 50:
        tries += 1

        k = random.choices(
            population=[0,1,2,3,4,5,6],
            weights=[1,2,2,3,2,2,3],
            k=1
        )[0]
        c = random_case(k)
        if allow_duplicates or c not in seen:
            out.append(c)
            seen.add(c)
    return out

def make_suite(random_count: int, include_boundary: bool, seed: int | None) -> List[str]:
    if seed is not None:
        random.seed(seed)
    result: List[str] = []
    if include_boundary:
        result.extend(boundary_suite())

    result.extend(random_pool(random_count))
    return result

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--random", type=int, default=50, help="Number of random cases to add (default: 50).")
    ap.add_argument("--seed", type=int, default=None, help="Random seed for reproducibility.")
    ap.add_argument("--no-boundary", action="store_true", help="Exclude curated boundary cases.")
    args = ap.parse_args()
    suite = make_suite(
        random_count=args.random,
        include_boundary=not args.no_boundary,
        seed=args.seed
    )

    print(len(suite))
    for s in suite:
        print(s)

if __name__ == "__main__":
    main()