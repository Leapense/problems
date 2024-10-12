def max_attentive_students(n, m):
    # Calculate the number of mixed pairs
    pairs = min(n, m)
    
    # Calculate the remaining boys and girls
    remaining_boys = n - pairs
    remaining_girls = m - pairs
    
    # Calculate the total number of attentive students
    attentive_students = 2 * pairs + (remaining_boys % 2) + (remaining_girls % 2)
    
    return attentive_students

# Read input values
n = int(input().strip())
m = int(input().strip())

# Print the result
print(max_attentive_students(n, m))