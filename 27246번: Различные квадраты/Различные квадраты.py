def max_different_squares(n):
    k = 1
    count = 0
    
    while n >= k * k:
        n -= k * k
        k += 1
        count += 1
    
    return count

# Read input
n = int(input().strip())

# Print the result
print(max_different_squares(n))