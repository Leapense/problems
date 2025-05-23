def can_be_true(x1, x2, n):
    # Calculate S
    S = (x1 - x2) // 2
    
    # If n is zero, the cities must still have the same status.
    if n == 0:
        return "YES" if x1 == x2 else "NO"
    
    # Check if x1 + x2 is even and S >= n
    if (x1 + x2) % 2 == 0 and S >= n:
        return "YES"
    else:
        return "NO"

# Read input
x1, x2, n = map(int, input().strip().split())
# Produce output based on the input
print(can_be_true(x1, x2, n))
