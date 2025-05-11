from math import comb
import sys
from typing import List, Set

def _binomial_coefficients(n: int) -> List[int]:
    return [comb(n, k) for k in range(n + 1)]

def find_sequence(N: int, F: int) -> List[int]:
    coeff = _binomial_coefficients(N - 1)
    used: Set[int] = set()
    answer: List[int] = [0] * N

    def dfs(idx: int, acc_sum: int) -> bool:
        if idx == N:
            return acc_sum == F
        
        rem_coeff = coeff[idx + 1:]
        asc_coeff = sorted(rem_coeff)
        desc_coeff = asc_coeff[::-1]

        for num in range(1, N + 1):
            if num in used:
                continue

            next_sum = acc_sum + coeff[idx] * num
            remaining_nums = [x for x in range(1, N + 1)
                              if x not in used and x != num]
            
            remaining_nums.sort()
            desc_nums = remaining_nums[::-1]

            min_future = sum(c * n for c, n in zip(desc_coeff, remaining_nums))
            max_future = sum(c * n for c, n in zip(desc_coeff, desc_nums))

            if not (next_sum + min_future <= F <= next_sum + max_future):
                continue

            answer[idx] = num
            used.add(num)
            if dfs(idx + 1, next_sum):
                return True
            
            used.remove(num)

        return False
    
    if not dfs(0, 0):
        raise ValueError("No valid sequence exists (contradicts task guarantees).")
    return answer

def main() -> None:
    N, F = map(int, sys.stdin.readline().split())
    seq = find_sequence(N, F)
    print(" ".join(map(str, seq)))

if __name__ == "__main__":
    main()