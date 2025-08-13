import argparse
import random
import shlex
import subprocess
import sys
from typing import List, Tuple

U32_BITS = 32
U32_MAX = (1 << U32_BITS) - 1

SPECIAL_VALUES = [
    0,
    1,
    U32_MAX,
    U32_MAX - 1,
    1 << 31,
    (1 << 31) - 1,
    1 << 30,
    (1 << 30) - 1,
    3,
    (1 << 16) - 1,
    (1 << 24) - 1,
    0xAAAAAAAA,
    0x55555555,
    0x80000001,
    0x7FFFFFFF,
    0xFFFFFFFE,
    0x0000FFFF,
    0xFFFF0000,
    0xF0F0F0F0,
    0x0F0F0F0F,
    0xCCCCCCCC,
    0x33333333,
]


def reachable_oracle(x: int, y: int) -> bool:
    x &= U32_MAX
    y &= U32_MAX
    if y == 0:
        return True
    for s in range(0, U32_BITS + 1):
        max_m = U32_BITS - s
        for m in range(0, max_m + 1):
            mask = ((1 << m) - 1) if m > 0 else 0
            seg = (x >> s) & mask
            for p in range(0, U32_BITS - m + 1):
                cand = (seg << p) & U32_MAX
                if cand == y:
                    return True
    return False


def random_u32(rng: random.Random) -> int:
    r = rng.random()
    if r < 0.2:
        return rng.choice(SPECIAL_VALUES) & U32_MAX
    if r < 0.5:
        m = rng.randint(0, U32_BITS)
        p = rng.randint(0, U32_BITS - m)
        return (((1 << m) - 1) << p) & U32_MAX
    if r < 0.7:
        base = rng.getrandbits(U32_BITS)
        mask = rng.choice([0xAAAAAAAA, 0x55555555, 0xCCCCCCCC, 0x33333333, 0xF0F0F0F0, 0x0F0F0F0F])
        return (base ^ mask) & U32_MAX
    return rng.getrandbits(U32_BITS)


def random_yes_case(rng: random.Random) -> Tuple[int, int]:
    x = random_u32(rng)
    s = rng.randint(0, U32_BITS)
    max_m = U32_BITS - s
    if max_m > 0:
        if rng.random() < 0.9:
            m = rng.randint(1, max_m)
        else:
            m = rng.randint(0, max_m)
    else:
        m = 0
    p = rng.randint(0, U32_BITS - m)
    mask = ((1 << m) - 1) if m > 0 else 0
    y = (((x >> s) & mask) << p) & U32_MAX
    return x, y


def random_no_case(rng: random.Random) -> Tuple[int, int]:
    while True:
        x = random_u32(rng)
        ones = x.bit_count()
        if ones < U32_BITS:
            break
    m = ones + 1
    p = rng.randint(0, U32_BITS - m)
    y = (((1 << m) - 1) << p) & U32_MAX
    return x, y


def generate_cases(t: int, yes_ratio: float, seed: int | None) -> Tuple[List[Tuple[int, int]], List[str]]:
    rng = random.Random(seed)
    yes_target = int(round(t * yes_ratio))
    cases: List[Tuple[int, int]] = []
    answers: List[str] = []
    yes_count = 0
    for _ in range(t):
        force_yes = yes_count < yes_target and (t - len(cases) - 1) >= (yes_target - yes_count)
        force_no = (len(cases) - yes_count) < (t - yes_target) and (t - len(cases) - 1) >= (t - yes_target - (len(cases) - yes_count))
        pick_yes = force_yes or (not force_no and rng.random() < yes_ratio)
        if pick_yes:
            x, y = random_yes_case(rng)
            ans = "Yes"
            yes_count += 1
        else:
            x, y = random_no_case(rng)
            ans = "No"
        cases.append((x, y))
        answers.append(ans)
    return cases, answers


def build_input_text(cases: List[Tuple[int, int]]) -> str:
    lines = [str(len(cases))]
    for x, y in cases:
        lines.append(f"{x} {y}")
    return "\n".join(lines) + "\n"


def compute_answers_oracle(cases: List[Tuple[int, int]]) -> List[str]:
    return ["Yes" if reachable_oracle(x, y) else "No" for x, y in cases]


def verify_external(cmd: str, input_text: str, expected: List[str], timeout_sec: float) -> Tuple[bool, str]:
    try:
        proc = subprocess.run(
            shlex.split(cmd),
            input=input_text.encode("utf-8"),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=timeout_sec,
        )
    except Exception as exc:
        return False, f"Execution failed: {exc}"
    out = proc.stdout.decode("utf-8", errors="replace").strip().splitlines()
    out = [line.strip() for line in out if line.strip() != ""]
    if len(out) != len(expected):
        return False, f"Line count mismatch: expected {len(expected)}, got {len(out)}"
    for i, (e, a) in enumerate(zip(expected, out), start=1):
        if e != a:
            return False, f"Mismatch at line {i}: expected '{e}', got '{a}'"
    return True, "OK"


def main() -> None:
    parser = argparse.ArgumentParser(prog="gen_rand_u32_tests", add_help=True)
    parser.add_argument("--t", type=int, default=200)
    parser.add_argument("--seed", type=int, default=None)
    parser.add_argument("--yes-ratio", type=float, default=0.5)
    parser.add_argument("--output-input", type=str, default=None)
    parser.add_argument("--output-answers", type=str, default=None)
    parser.add_argument("--verify-cmd", type=str, default=None)
    parser.add_argument("--timeout", type=float, default=3.0)
    args = parser.parse_args()

    if args.t <= 0:
        print("t must be positive", file=sys.stderr)
        sys.exit(2)
    if not (0.0 <= args.yes_ratio <= 1.0):
        print("yes-ratio must be in [0,1]", file=sys.stderr)
        sys.exit(2)

    cases, planned = generate_cases(args.t, args.yes_ratio, args.seed)
    input_text = build_input_text(cases)
    oracle = compute_answers_oracle(cases)

    if args.output_input:
        with open(args.output_input, "w", encoding="utf-8") as f:
            f.write(input_text)
    else:
        sys.stdout.write(input_text)

    if args.output_answers:
        with open(args.output_answers, "w", encoding="utf-8") as f:
            for ans in oracle:
                f.write(ans + "\n")

    if args.verify_cmd:
        ok, msg = verify_external(args.verify_cmd, input_text, oracle, args.timeout)
        status = "PASS" if ok else "FAIL"
        print(f"[{status}] {msg}", file=sys.stderr)


if __name__ == "__main__":
    main()