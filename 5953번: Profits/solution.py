def max_subarray_sum(profits):
    max_sum = profits[0]
    current_sum = profits[0]
    for profit in profits[1:]:
        current_sum = max(profit, current_sum + profit)
        max_sum = max(max_sum, current_sum)
    return max_sum

import sys
input = sys.stdin.readline

N = int(input())
profits = [int(input()) for _ in range(N)]

print(max_subarray_sum(profits))