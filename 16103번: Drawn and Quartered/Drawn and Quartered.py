def perform_switcheroo(S):
    n = len(S)
    quarter_len = n // 4
    A = S[:quarter_len]
    B = S[quarter_len:2*quarter_len]
    C = S[2*quarter_len:3*quarter_len]
    D = S[3*quarter_len:]
    return A + D + B + C

def final_string(N, K, S):
    seen = {}
    original = S
    step = 0
    
    while step < K:
        if S in seen:
            cycle_length = step - seen[S]
            remaining_steps = (K - step) % cycle_length
            for _ in range(remaining_steps):
                S = perform_switcheroo(S)
            return S
        seen[S] = step
        S = perform_switcheroo(S)
        step += 1
    
    return S

# Read inputs
N, K = map(int, input().strip().split())
S = input().strip()

# Get the final string after K switcheroos
result = final_string(N, K, S)
print(result)