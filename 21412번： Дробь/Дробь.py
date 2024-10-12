import math

def find_largest_proper_fraction(n):
    max_numerator = 0
    max_denominator = 0
    
    for a in range(1, n):
        b = n - a
        if a < b and math.gcd(a, b) == 1:
            max_numerator = a
            max_denominator = b
    
    return max_numerator, max_denominator

# Input reading
n = int(input().strip())

# Find the largest proper irreducible fraction
numerator, denominator = find_largest_proper_fraction(n)

# Output the result
print(numerator, denominator)