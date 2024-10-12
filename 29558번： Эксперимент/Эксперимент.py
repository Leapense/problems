def solve():
    # Read inputs
    n, d = map(int, input().split())
    
    # Generate initial sequence
    initial_sequence = list(range(n))
    
    # Calculate the current sum
    current_sum = sum(initial_sequence)
    
    # Calculate the required sum
    required_sum = d * n
    
    # Calculate the shift
    shift = (required_sum - current_sum) // n
    
    # Apply the shift to all elements in the sequence
    result = [x + shift for x in initial_sequence]
    
    # Print the result
    print(" ".join(map(str, result)))

# Run the function
solve()