import sys
import threading

def main():
    sys.setrecursionlimit(1 << 25)

    N_and_rest = sys.stdin.read().split()
    N = int(N_and_rest[0])
    profits = list(map(int, N_and_rest[1:N+1]))
    prices = list(map(int, N_and_rest[N+1:2*N+1]))

    max_profit = -1
    second_max_profit = -1
    count_max = 0

    for profit in profits:
        if profit > max_profit:
            second_max_profit = max_profit
            max_profit = profit
            count_max = 1
        elif profit == max_profit:
            count_max += 1
        elif profit > second_max_profit:
            second_max_profit = profit

    if second_max_profit == -1:
        second_max_profit = max_profit

    result = []

    for i in range(N):
        if profits[i] < max_profit:
            max_other_profit = max_profit
        else:
            if count_max > 1:
                max_other_profit = max_profit
            else:
                max_other_profit = second_max_profit
        opportunity_cost = max_other_profit - prices[i]
        net_profit = profits[i] - opportunity_cost - prices[i]
        result.append(str(net_profit))

    print(' '.join(result))

main()