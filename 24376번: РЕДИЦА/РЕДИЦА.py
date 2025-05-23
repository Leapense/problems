def find_nth_digit(x, n):
    # Initial value and sequence as string
    current_value = 1
    sequence = ""
    
    # Build the sequence until its length reaches at least n
    while len(sequence) < n:
        # Append the current value to the sequence as a string
        sequence += str(current_value)
        # Calculate the next number in the sequence
        current_value *= x
    
    # Return the n-th digit (1-based index)
    return sequence[n-1]

# Read the input values
import sys
input = sys.stdin.read
x, n = map(int, input().strip().split())

# Output the result
print(find_nth_digit(x, n))