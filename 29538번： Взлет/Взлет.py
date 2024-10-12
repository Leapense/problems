def calculate_minimum_fuel(M, N, alpha, masses):
    P = sum(masses)
    beta = 1000 - alpha

    if beta <= 0:
        return "Impossible"
    
    F_min = (alpha * (M + P)) / beta
    return F_min

M, N, alpha = map(int, input().split())
masses = list(map(int, input().split()))

print(calculate_minimum_fuel(M, N, alpha, masses))