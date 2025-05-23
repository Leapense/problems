def can_prepare_tasks(n, positions):
    # Dictionary to count the occurrences of each position
    task_counts = {}
    
    # Initialize the dictionary with all positions set to 0
    for i in range(1, 6):
        for div in ['A', 'B', 'C']:
            pos = f"{i}{div}"
            task_counts[pos] = 0
    
    # Count each position in the input list
    for pos in positions:
        if pos in task_counts:
            task_counts[pos] += 1
    
    # Check the conditions
    for i in range(1, 6):
        for div in ['A', 'B', 'C']:
            pos = f"{i}{div}"
            if i == 5:  # For round 5, we need at least 2 tasks for each division
                if task_counts[pos] < 2:
                    return "NIE"
            else:  # For rounds 1 to 4, we need at least 1 task for each division
                if task_counts[pos] < 1:
                    return "NIE"
    
    return "TAK"

# Reading input
n = int(input().strip())
positions = input().strip().split()

# Check if we can prepare tasks
result = can_prepare_tasks(n, positions)
print(result)