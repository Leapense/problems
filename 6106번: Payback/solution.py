import sys
from typing import List

def min_travel_distance(n: int, d: List[int]) -> int:
    balance = 0
    min_neg_idx = None
    extra = 0

    for i in range(1, n + 1):
        balance += d[i]

        if d[i] < 0:
            if min_neg_idx is None or i < min_neg_idx:
                min_neg_idx = i

        if balance >= 0 and min_neg_idx is not None:
            extra += 2 * (i - min_neg_idx)
            min_neg_idx = None

    return n + extra

def main() -> None:
    data = sys.stdin.read().split()
    n = int(data[0])

    debts = [0] * (n + 1)
    for idx in range(1, n + 1):
        debts[idx] = int(data[idx])

    print(min_travel_distance(n, debts))

if __name__ == '__main__':
    main()