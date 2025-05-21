#!/usr/bin/env python3
import sys

input_lines = sys.stdin.readline

def main():
    L1, L2 = map(int, input_lines().split())
    S1 = [int(input_lines()) for _ in range(L1)]
    S2 = [int(input_lines()) for _ in range(L2)]

    if L1 < L2:
        S1, S2 = S2, S1
        L1, L2 = L2, L1

    prev = [0] * (L2 + 1)
    ans = 0

    for i in range(1, L1 + 1):
        curr = [0] * (L2 + 1)
        a = S1[i - 1]
        for j in range(1, L2 + 1):
            if a == S2[j - 1]:
                curr[j] = prev[j - 1] + 1
                if curr[j] > ans:
                    ans = curr[j]
        prev = curr

    print(ans)

if __name__ == "__main__":
    main()