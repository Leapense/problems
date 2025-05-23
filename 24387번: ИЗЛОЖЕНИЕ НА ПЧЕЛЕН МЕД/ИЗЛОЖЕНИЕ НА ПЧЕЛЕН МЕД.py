def honey(A1, A2, A3, B1, B2, B3):
    from itertools import permutations
    
    prices = [A1, A2, A3]
    capacities = [B1, B2, B3]
    
    max_profit = 0
    
    # Permute capacities and calculate the profit for each permutation
    for perm in permutations(capacities):
        profit = sum(prices[i] * perm[i] for i in range(3))
        max_profit = max(max_profit, profit)
    
    return max_profit

A1, A2, A3 = map(int, input().split())
B1, B2, B3 = map(int, input().split())

print(honey(A1, A2, A3, B1, B2, B3))