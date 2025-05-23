def min_actions_to_destroy_aliens(n, p, a):
    # Convert 1-based index to 0-based
    p -= 1
    
    # Calculate actions for left-to-right strategy
    actions_left_to_right = 0
    current_position = p
    for i in range(p, n):
        if a[i] > 0:
            actions_left_to_right += abs(current_position - i)  # Move to the column
            actions_left_to_right += a[i]  # Shoot all aliens in this column
            current_position = i  # Update current position

    for i in range(p - 1, -1, -1):
        if a[i] > 0:
            actions_left_to_right += abs(current_position - i)  # Move to the column
            actions_left_to_right += a[i]  # Shoot all aliens in this column
            current_position = i  # Update current position

    # Calculate actions for right-to-left strategy
    actions_right_to_left = 0
    current_position = p
    for i in range(p, -1, -1):
        if a[i] > 0:
            actions_right_to_left += abs(current_position - i)  # Move to the column
            actions_right_to_left += a[i]  # Shoot all aliens in this column
            current_position = i  # Update current position

    for i in range(p + 1, n):
        if a[i] > 0:
            actions_right_to_left += abs(current_position - i)  # Move to the column
            actions_right_to_left += a[i]  # Shoot all aliens in this column
            current_position = i  # Update current position
    
    # Return the minimum of the two strategies
    return min(actions_left_to_right, actions_right_to_left)

n, p = map(int, input().split())
a = list(map(int, input().split()))

print(min_actions_to_destroy_aliens(n, p, a))