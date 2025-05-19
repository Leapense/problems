import sys
from typing import List, Tuple, Iterator

def _ints_from_stdin() -> Iterator[int]:
    for tok in sys.stdin.buffer.read().split():
        yield int(tok)

def _max_run_indices(nums: Iterator[int], n: int) -> Tuple[int, int]:
    best_sum = -10**18
    best_i = best_j = 1

    cur_sum = 0
    cur_start = 1

    for idx in range(1, n + 1):
        val = next(nums)
        cur_sum += val

        if (cur_sum > best_sum or (cur_sum == best_sum and (cur_start < best_i or (cur_start == best_i and idx < best_j)))):
            best_sum = cur_sum
            best_i, best_j = cur_start, idx

        if cur_sum < 0:
            cur_sum = 0
            cur_start = idx + 1

    return best_i, best_j

def solve(data: str | None = None) -> str:
    if data is None:
        ints = _ints_from_stdin()
    else:
        ints = (int(x) for x in data.strip().split())

    t = next(ints)
    out_lines: List[str] = []
    for _ in range(t):
        n = next(ints)
        i, j = _max_run_indices(ints, n)
        out_lines.append(f"{i} {j}")
    result = "\n".join(out_lines) + ("\n" if data is None else "")
    if data is None:
        sys.stdout.write(result)
    return result

if __name__ == "__main__":
    solve()