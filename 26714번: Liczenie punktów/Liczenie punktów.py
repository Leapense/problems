def calculate_points(n, results):
    # Number of tests in each group
    group_size = n // 10
    points = 0
    
    # Check each group
    for i in range(0, n, group_size):
        group = results[i:i + group_size]
        if all(test == 'T' for test in group):
            points += 1
    
    return points

# Reading input
n = int(input().strip())
results = input().strip()

# Calculate and print the points
points = calculate_points(n, results)
print(points)