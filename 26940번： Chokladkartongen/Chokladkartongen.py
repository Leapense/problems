def min_new_boxes(N, observations):
    # Initialize the count of new boxes needed
    new_boxes = 0
    
    # Track the previous number of chocolates
    previous_count = observations[0]
    
    for i in range(1, N):
        current_count = observations[i]
        
        # Check if the current count is greater than the previous count
        if current_count > previous_count:
            # If so, a new box must have been bought
            new_boxes += 1
            previous_count = current_count
        else:
            # Otherwise, just update the count to the current observation
            previous_count = current_count
    
    return new_boxes

# Read input values
import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
observations = list(map(int, data[1:]))

# Compute and print the result
print(min_new_boxes(N, observations))