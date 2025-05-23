import math

def check_paths(N, M):
    # Calculate N!
    total_paths = math.factorial(N)
    
    # Compare total_paths with M
    if total_paths >= M:
        return "Nope"
    else:
        return "Harshat Mata"

# Read inputs
N, M = map(int, input().split())

# Output the result
print(check_paths(N, M))
