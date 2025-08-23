import sys, itertools

def solve():
    n = int(sys.stdin.readline())
    initial_costs = list(map(int, sys.stdin.readline().split()))
    discounts = [[] for _ in range(n)]
    for i in range(n):
        p = int(sys.stdin.readline())
        for _ in range(p):
            a, d = map(int, sys.stdin.readline().split())
            discounts[i].append((a - 1, d))

    min_total_cost = float('inf')
    potion_indices = list(range(n))
    for order in itertools.permutations(potion_indices):
        current_costs = list(initial_costs)
        current_total_cost = 0
        for potion_index in order:
            cost = current_costs[potion_index]
            current_total_cost += cost
            for target_potion, reduction in discounts[potion_index]:
                current_costs[target_potion] -= reduction
                if current_costs[target_potion] < 1:
                    current_costs[target_potion] = 1

        min_total_cost = min(min_total_cost, current_total_cost)
    print(min_total_cost)

solve()