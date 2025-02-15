#!/usr/bin/env python3
import sys, bisect

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    M = int(input_data[1])

    S = set()
    for i in range(M):
        S.add(int(input_data[2 + i]))

    allowed = [num for num in range(1, 1001) if num not in S]
    allowed.sort()

    best_diff = float('inf')

    for x in allowed:
        for y in allowed:
            prod_xy = x * y
            target = N / prod_xy
            idx = bisect.bisect_left(allowed, target)
            for cand_idx in [idx - 1, idx]:
                if 0 <= cand_idx < len(allowed):
                    z = allowed[cand_idx]
                    product = prod_xy * z
                    diff = abs(N - product)
                    if diff < best_diff:
                        best_diff = diff
                        if best_diff == 0:
                            print(0)
                            return
    print(best_diff)

if __name__ == "__main__":
    main()