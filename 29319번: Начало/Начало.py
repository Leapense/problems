def min_names_to_read(n, a):
    # Sort the array
    a.sort()
    
    # Sum all the elements except the last one
    total_names = sum(a[:-1])
    
    return total_names

# Read input
n = int(input())
a = list(map(int, input().split()))

# Get the result
result = min_names_to_read(n, a)

# Print the result
print(result)