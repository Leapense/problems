import sys
from typing import List

def read_int_list() -> List[int]:
    """Fast int list reader."""
    return list(map(int, sys.stdin.readline().split()))

def is_row_ok(row: List[int], limit: int) -> bool:
    heavy_stack: List[int] = []
    for weight in row:
        if weight > limit:
            heavy_stack.append(weight)

    if len(heavy_stack) & 1:
        return False
    
    i: int = 0
    size: int = len(heavy_stack)
    while i < size:
        if heavy_stack[i] != heavy_stack[i + 1]:
            return False
        i += 2

    return True

def is_feasible(limit: int, row_a: List[int], row_b: List[int]) -> bool:
    return is_row_ok(row_a, limit) and is_row_ok(row_b, limit)

def find_min_strength(row_a: List[int], row_b: List[int]) -> int:
    high: int = max(max(row_a), max(row_b))
    low: int = -1

    while high - low > 1:
        mid: int = (low + high) // 2
        if is_feasible(mid, row_a, row_b):
            high = mid
        else:
            low = mid
    return high

def main() -> None:
    n: int = int(sys.stdin.buffer.readline())
    row_a: List[int] = read_int_list()
    row_b: List[int] = read_int_list()

    assert len(row_a) == n and len(row_b) == n, "Invalid input."

    answer: int = find_min_strength(row_a, row_b)
    sys.stdout.write(f"{answer}\n")

if __name__ == "__main__":
    main()