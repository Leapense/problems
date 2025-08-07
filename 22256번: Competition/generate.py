#!/usr/bin/env python3
import random
import sys
from typing import List, Tuple

MAX_SCORE = 10_000
DEFAULT_CASES = 20
DEFAULT_N_MAX = 200_000

def emit_case(n: int, a: int, physics: List[int], biology: List[int]) -> None:
    print(n, a, n - a)
    print(*physics)
    print(*biology)

def make_case(n_max: int) -> Tuple[int, int, List[int], List[int]]:
    n = random.randint(1, n_max)
    a = random.randint(0, n)
    physics, biology = [], []

    for _ in range(n):
        mode = random.random()
        if mode < 0.10:
            score = random.randint(0, MAX_SCORE)
            physics.append(score)
            biology.append(score)
        elif mode < 0.20:
            physics.append(MAX_SCORE)
            biology.append(0)
        elif mode < 0.30:
            physics.append(0)
            biology.append(MAX_SCORE)
        else:
            physics.append(random.randint(0, MAX_SCORE))
            biology.append(random.randint(0, MAX_SCORE))
    return n, a, physics, biology

def main() -> None:
    args = list(map(int, sys.argv[1:]))
    num_cases = args[0] if len(args) >= 1 else DEFAULT_CASES
    n_max = args[1] if len(args) >= 2 else DEFAULT_N_MAX
    seed = args[2] if len(args) >= 3 else None
    if seed is not None:
        random.seed(seed)

    emit_case(1, 0, [0], [0])
    emit_case(1, 1, [MAX_SCORE], [MAX_SCORE])
    emit_case(10, 0, [0]*10, [MAX_SCORE]*10)
    emit_case(10, 10, [MAX_SCORE]*10, [0]*10)
    emit_case(5, 2, [100]*5, [100]*5)

    for _ in range(num_cases - 5):
        n, a, phys, bio = make_case(n_max)
        emit_case(n, a, phys, bio)

if __name__ == "__main__":
    main()