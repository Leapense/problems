from __future__ import annotations
import sys
from typing import List, Tuple, Optional

RULE_CNT: int = 256
LEFT_BIT: int = 1

def next_row(row: int, rule: int, n: int, full: int, interior: int) -> int:
    left = (row << 1) & full
    center = row
    right = row >> 1

    not_l = (~left) & full
    not_c = (~center) & full
    not_r = (~right) & full

    out: int = 0
    for pat in range(8):
        if rule & (1 << pat):
            a = (pat >> 2) & 1
            b = (pat >> 1) & 1
            c = pat & 1
            mask = (left if a else not_l) & (center if b else not_c) & (right if c else not_r)
            out |= mask
    return out & interior

def first_hit(rule: int, target: int, max_step: int, n: int, full: int, interior: int) -> Optional[int]:
    row: int = 1 << (n // 2)
    if row == target:
        return 1
    
    for step in range(2, max_step + 1):
        row = next_row(row, rule, n, full, interior)
        if row == target:
            return step
    return None

def encode(line: str) -> int:
    val: int = 0
    for ch in reversed(line):
        val = (val << 1) | (ch == 'B')
    return val

def main() -> None:
    lines = (ln.rstrip('\n') for ln in sys.stdin)
    answers: List[str] = []

    for idx, raw in enumerate(lines, start = 1):
        if raw == "END OF INPUT":
            break

        parts: List[str] = raw.split()
        if len(parts) != 2:
            answers.append(f"LINE {idx} NONE")
            continue

        try:
            max_step = int(parts[0])
        except ValueError:
            answers.append(f"LINE {idx} NONE")
            continue

        pattern: str = parts[1]
        n: int = len(pattern)

        if (n % 2 == 0 or n < 3 or pattern[0] != 'W' or pattern[-1] != 'W' or any(ch not in 'WB' for ch in pattern)):
            answers.append(f"LINE {idx} NONE")
            continue

        full_mask: int = (1 << n) - 1
        interior_mask: int = full_mask ^ (1 | (1 << (n - 1)))
        target_bits: int = encode(pattern)

        pairs: List[Tuple[int, int]] = []
        for rule in range(RULE_CNT):
            step = first_hit(rule, target_bits, max_step, n, full_mask, interior_mask)

            if step is not None:
                pairs.append((rule, step))

        if pairs:
            pair_str = ''.join(f"({r},{s})" for r, s in pairs)
            answers.append(f"LINE {idx} {pair_str}")
        else:
            answers.append(f"LINE {idx} NONE")

    sys.stdout.write("\n".join(answers))

if __name__ == "__main__":
    main()