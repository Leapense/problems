def min_tab_presses(n, m, tabs):
    current_position = 1  # Start at tab 1
    total_presses = 0

    for tab in tabs:
        # Calculate direct distance
        direct_distance = abs(tab - current_position)
        
        # Calculate cyclic distance
        cyclic_distance = n - direct_distance
        
        # Take the minimum of both distances
        total_presses += min(direct_distance, cyclic_distance)
        
        # Update the current position
        current_position = tab

    return total_presses

# Read input
n, m = map(int, input().split())
tabs = list(map(int, input().split()))

# Output the result
print(min_tab_presses(n, m, tabs))