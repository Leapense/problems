import sys
from typing import List

input = sys.stdin.readline

class FenwickTree:
    def __init__(self, size: int) -> None:
        self._n = size
        self._tree = [0] * (self._n + 1)

    def update(self, index: int, delta: int) -> None:
        while index <= self._n:
            self._tree[index] += delta
            index += index & -index

    def query(self, index: int) -> int:
        result = 0
        while index > 0:
            result += self._tree[index]
            index -= index & -index

        return result
    
    def range_sum(self, left: int, right: int) -> int:
        if left > right:
            return 0
        return self.query(right) - self.query(left - 1)
    

def compute_satisfaction(n: int, midterm_by_final: List[int]) -> List[int]:
    pos = [0] * (n + 1)
    for final_rank, mid_rank in enumerate(midterm_by_final, start=1):
        pos[mid_rank] = final_rank

    b_counts = [0] * (n + 1)
    c_counts = [0] * (n + 1)

    fenw_b = FenwickTree(n)
    for i in range(1, n + 1):
        current_pos = pos[i]
        b_counts[i] = fenw_b.range_sum(current_pos + 1, n)
        fenw_b.update(current_pos, 1)

    fenw_c = FenwickTree(n)
    for i in range(n, 0, -1):
        current_pos = pos[i]
        c_counts[i] = fenw_c.range_sum(1, current_pos - 1)
        fenw_c.update(current_pos, 1)

    satisfaction = [0] * (n + 1)
    for i in range(1, n + 1):
        satisfaction[i] = b_counts[i] - c_counts[i]

    return satisfaction

def main() -> None:
    n = int(input().strip())
    midterm_by_final = list(map(int, input().split()))

    result = compute_satisfaction(n, midterm_by_final)
    writer = sys.stdout
    for i in range(1, n + 1):
        writer.write(str(result[i]) + "\n")

if __name__ == "__main__":
    main()