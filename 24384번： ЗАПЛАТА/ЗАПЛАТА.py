def find_kth_tax_percentage_optimized(k):
    # The sequence is built conceptually but not stored completely
    cumulative_length = 0
    month = 1
    
    while True:
        # Calculate the salary for this month, which is the cube of the month number
        salary = month ** 3
        # Convert salary to string to find out its length
        salary_str = str(salary)
        salary_length = len(salary_str)
        
        # Update the cumulative length of the sequence
        previous_length = cumulative_length
        cumulative_length += salary_length
        
        # Check if the current cumulative length has reached or surpassed the position k
        if cumulative_length >= k:
            # We want the (k - previous_length)th character from salary_str
            # Adjusting (k - previous_length - 1) for 0-indexed access
            kth_char = salary_str[k - previous_length - 1]
            return int(kth_char)  # convert this character to an integer
        
        # Increment the month counter for next iteration
        month += 1

# Example usage
k = int(input())
result = find_kth_tax_percentage_optimized(k)
print(result)
