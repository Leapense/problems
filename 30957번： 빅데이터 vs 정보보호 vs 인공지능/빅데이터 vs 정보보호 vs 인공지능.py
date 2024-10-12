def analyze_interest(N, interests):
    # Initialize counters
    b_count = 0
    s_count = 0
    a_count = 0
    
    # Count the occurrences of B, S, and A
    for interest in interests:
        if interest == 'B':
            b_count += 1
        elif interest == 'S':
            s_count += 1
        elif interest == 'A':
            a_count += 1
    
    # Create a dictionary to store counts
    counts = {'B': b_count, 'S': s_count, 'A': a_count}
    
    # Find the maximum count
    max_count = max(counts.values())
    
    # Collect all keys with the maximum count
    most_interests = [key for key, value in counts.items() if value == max_count]
    
    # Determine the output
    if len(most_interests) == 1:
        print(most_interests[0])
    elif len(most_interests) == 3:
        print('SCU')
    else:
        print(''.join(most_interests))

# Example usage
N = int(input())
interests = input().strip()
analyze_interest(N, interests)