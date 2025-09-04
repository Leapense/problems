import sys
from typing import List

N = 20

def solve_case(bowls: List[int], first_flip: bool) -> int:
    arr = bowls[:]
    flips = 0
    if first_flip:
        arr[0] ^= 1
        arr[1] ^= 1
        flips += 1
    for i in range(1, N):
        if arr[i - 1] == 1:
            flips += 1
            arr[i - 1] ^= 1
            arr[i] ^= 1
            if i + 1 < N:
                arr[i + 1] ^= 1
    if any(arr):
        return float('inf')
    return flips

def main() -> None:
    data = sys.stdin.read().strip().split()
    if len(data) != N:
        print(0)
        return
    bowls = [int(x) for x in data]
    ans = min(solve_case(bowls, False), solve_case(bowls, True))
    print(int(ans))

if __name__ == "__main__":
    main()