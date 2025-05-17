import sys
from typing import List, Tuple

# Period table: (youngest → oldest)
_PERIODS: List[Tuple[str, int, int, str]] = [
    ("Quaternary", 0, 3, "A"),
    ("Neogene", 4, 23, "B"),
    ("Paleogene", 24, 66, "C"),
    ("Cretaceous", 67, 146, "D"),
    ("Jurassic", 147, 200, "E"),
    ("Triassic", 201, 251, "F"),
    ("Permian", 252, 299, "G"),
    ("Carboniferous", 300, 359, "H"),
    ("Devonian", 360, 416, "I"),
    ("Silurian", 417, 444, "J"),
    ("Ordovician", 445, 488, "K"),
    ("Cambrian", 489, 542, "L"),
    ("Precambrian", 543, 3_000_000, "M"),   # cap huge upper bound
]

# Maps
_letter_to_ord = {row[3]: idx for idx, row in enumerate(_PERIODS)}

def _period_ordinal_for_age(t: int) -> int:
    """Return smallest ordinal whose period contains age t (millions of years ago)."""
    for idx, (_, lo, hi, _) in enumerate(_PERIODS):
        if lo <= t <= hi:
            return idx
    # Should never happen with given ranges (t ≤ 3000)
    raise ValueError(f"Age {t} out of range")

# 8-direction deltas
_DELTA = [(-1, -1), (-1, 0), (-1, 1),
          (0, -1),          (0, 1),
          (1, -1),  (1, 0), (1, 1)]

def _check_dataset(t: int, grid: List[str]) -> bool:
    h, w = len(grid), len(grid[0])
    p0 = _period_ordinal_for_age(t)

    for r in range(h):
        for c in range(w):
            cell = grid[r][c]
            if 'A' <= cell <= 'M':                         # found a fossil
                # find smallest adjacent digit
                min_stratum = 10  # digits are 0-9
                for dr, dc in _DELTA:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < h and 0 <= nc < w:
                        if grid[nr][nc].isdigit():
                            min_stratum = min(min_stratum, int(grid[nr][nc]))
                if min_stratum == 10:      # no digit neighbours – cannot happen by spec
                    return False

                expected_ord = p0 + min_stratum
                if expected_ord >= len(_PERIODS):          # fossil deeper than table
                    return False
                if _letter_to_ord[cell] != expected_ord:   # mismatch
                    return False
    return True

def solve(stream_in=sys.stdin, stream_out=sys.stdout) -> None:
    it = iter(stream_in.read().splitlines())
    k = int(next(it))
    for case in range(1, k + 1):
        # t, w, d
        t_str, w_str, d_str = next(it).split()
        t, w, d = int(t_str), int(w_str), int(d_str)
        grid = [next(it).rstrip() for _ in range(d)]

        ok = _check_dataset(t, grid)
        stream_out.write(f"Data Set {case}:\n")
        stream_out.write("Yes\n\n" if ok else "No\n\n")

if __name__ == "__main__":
    solve()