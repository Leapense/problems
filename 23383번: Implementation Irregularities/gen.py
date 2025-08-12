import argparse
import random
import sys
from typing import List, Tuple

def clamp_range(lo: int, hi: int) -> Tuple[int, int]:
    if lo > hi:
        lo, hi = hi, lo
    return lo, hi

def rand_inclusive(rng: random.Random, lo: int, hi: int) -> int:
    lo, hi = clamp_range(lo, hi)
    return rng.randint(lo, hi)

def generate_random_case(n: int, t_min: int, t_max: int, s_min: int, s_max: int, absent_prob: float, ensure_deadline: bool, pattern: str, seed: int | None,) -> Tuple[int, List[int], List[int]]:
    rng = random.Random(seed)
    if t_min < 0:
        raise ValueError("t_min must be >= 0")
    if s_min < 1:
        raise ValueError("s_min must be >= 1 (to avoid division by zero)")
    t_min, t_max = clamp_range(t_min, t_max)
    s_min, s_max = clamp_range(s_min, s_max)
    if not (0.0 <= absent_prob <= 1.0):
        raise ValueError("absent_prob must be within [0, 1]")
    
    t_lo, t_hi = t_min, t_max
    s_lo, s_hi = s_min, s_max
    local_absent_prob = absent_prob

    if pattern == "random":
        pass
    elif pattern == "tight":
        t_lo = max(t_min, (t_min + t_max) // 2)
        t_hi = t_max
        s_hi = max(s_min, min(s_max, max(2, n // 2)))
        local_absent_prob = min(0.2, absent_prob)
    elif pattern == "loose":
        t_hi = max(t_min, (t_min + t_max) // 2)
        s_lo = min(s_max, max(s_min, (s_min + s_max) // 2))
        local_absent_prob = min(0.2, absent_prob)
    elif pattern == "all":
        local_absent_prob = 0.0
    elif pattern == "none":
        local_absent_prob = 1.0
    else:
        raise ValueError(f"Unknown pattern: {pattern}")
    
    t = [rand_inclusive(rng, t_lo, t_hi) for _ in range(n)]
    s = []
    for _ in range(n):
        if rng.random() < local_absent_prob:
            s.append(-1)
        else:
            s.append(rand_inclusive(rng, s_lo, s_hi))

    if ensure_deadline and all(x == -1 for x in s):
        idx = rng.randrange(n)
        s[idx] = rand_inclusive(rng, s_lo, s_hi)
    return n, t, s

def main() -> None:
    parser = argparse.ArgumentParser(
        description="Generate a random test case for the min_computers solver."
    )
    parser.add_argument("-n", type=int, default=10, help="number of tasks (default: 10)")
    parser.add_argument("--t-min", type=int, default=1, help="min workload t[i] (default: 1)")
    parser.add_argument("--t-max", type=int, default=20, help="max workload t[i] (default: 20)")
    parser.add_argument("--s-min", type=int, default=1, help="min positive deadline s[i] (default: 1)")
    parser.add_argument("--s-max", type=int, default=20, help="max positive deadline s[i] (default: 20)")
    parser.add_argument("--absent-prob", type=float, default=0.3, help="probability that s[i] = -1 (default: 0.3)")
    parser.add_argument("--ensure-deadline", action="store_true", help="force at least one s[i] != -1")
    parser.add_argument("--pattern", choices=["random", "tight", "loose", "all", "none"], default="random", help="generation pattern (default: random)")
    parser.add_argument("--seed", type=int, default=None, help="PRNG seed for reproducibility")

    args = parser.parse_args()

    n, t, s = generate_random_case(
        n=args.n,
        t_min=args.t_min,
        t_max=args.t_max,
        s_min=args.s_min,
        s_max=args.s_max,
        absent_prob=args.absent_prob,
        ensure_deadline=args.ensure_deadline,
        pattern=args.pattern,
        seed=args.seed,
    )

    out = sys.stdout
    print(n, file=out)
    print(" ".join(map(str, t)), file=out)
    print(" ".join(map(str, s)), file=out)

if __name__ == "__main__":
    main()