import argparse
import random
import string
import sys

def one_case(rng: random.Random) -> str:
    """Return a single random test case as a ready-to-print string."""
    N = rng.randint(2, 15)
    K = rng.randint(2, 10)
    M = rng.randint(2, 5)

    lines = [f"{N} {K} {M}"]
    alphabet = string.ascii_uppercase[:K]      # e.g. 'ABCDEF' if K = 6

    for _ in range(M):
        length = rng.randint(2, K)             # 2 … K inclusive
        group = rng.sample(alphabet, length)   # distinct letters
        rng.shuffle(group)                     # random order
        lines.append("".join(group))

    return "\n".join(lines)

def main() -> None:
    parser = argparse.ArgumentParser(
        description="Random test-case generator for the Zoo problem")
    parser.add_argument("--cases", type=int, default=100,
                        help="number of cases to generate (default: 100)")
    parser.add_argument("--seed", type=int,
                        help="seed for RNG (optional)")
    args = parser.parse_args()

    rng = random.Random(args.seed)
    emit = (one_case(rng) for _ in range(args.cases))
    sys.stdout.write("\n".join(emit))
    if args.cases:
        sys.stdout.write("\n")  # final newline

if __name__ == "__main__":
    main()