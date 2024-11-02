def calculte_total_cost(N, ingredients):
    total_cost = 0
    for H, B, K in ingredients:
        if B > H:
            total_cost += (B - H) * K
    return total_cost

N = int(input().strip())
ingredients = [tuple(map(int, input().split())) for _ in range(N)]

total_cost = calculte_total_cost(N, ingredients)
print(total_cost)