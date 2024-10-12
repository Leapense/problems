import math

def heron_counts(a, b):
    # Calculate minimum number of herons
    min_herons = max(math.ceil(a / 2), math.ceil(b / 2))
    
    # Calculate maximum number of herons
    max_herons = max(a, b)
    
    return min_herons, max_herons

a, b = map(int, input().split())
result = heron_counts(a, b)
print(result[0], result[1])