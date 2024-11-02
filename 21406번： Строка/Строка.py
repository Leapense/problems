def generate_sequence(n):
    s = ""  # Initialize s_0 as an empty string
    
    for i in range(1, n + 1):
        str_i = str(i)  # Convert i to its string representation
        if str_i not in s:
            s += str_i  # Append str_i to s if str_i is not already a substring of s
    
    return s

# Reading input
n = int(input().strip())

# Generating the sequence and getting the result for s_n
result = generate_sequence(n)

# Outputting the result
print(result)