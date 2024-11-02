def remaining_bacteria(n, requirements):
    MOD = 10**9 + 7
    current_bacteria = 1  # Start with 1 bacterium

    for i in range(n):
        # Bacteria doubles every hour
        current_bacteria *= 2
        
        # Check if we have enough bacteria to conduct the experiment
        if current_bacteria < requirements[i]:
            return "error"
        
        # Subtract the bacteria used in the experiment
        current_bacteria -= requirements[i]

    # Return the remaining bacteria modulo 10^9 + 7
    return current_bacteria % MOD

# Example Usage
n = int(input().strip())
requirements = list(map(int, input().strip().split()))
print(remaining_bacteria(n, requirements))
