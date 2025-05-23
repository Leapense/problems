def evaluate_expression(A, B, C, operator, base):
    """Evaluate the expression A ? B = C in the given base."""
    try:
        # Convert A, B, C from the given base to decimal
        a_dec = int(A, base)
        b_dec = int(B, base)
        c_dec = int(C, base)

        # Perform the operation
        if operator == '+':
            return a_dec + b_dec == c_dec
        elif operator == '-':
            return a_dec - b_dec == c_dec
        elif operator == '*':
            return a_dec * b_dec == c_dec
    except ValueError:
        # If conversion fails, this base is invalid for one of the numbers
        return False

def find_valid_bases(expression):
    # Split the expression into parts
    parts = expression.split()
    A, operator, B, _, C = parts  # A ? B = C

    # Determine the minimum base for each number
    def min_base(num):
        return max(int(digit) for digit in num) + 1

    min_base_A = min_base(A)
    min_base_B = min_base(B)
    min_base_C = min_base(C)
    
    # The minimum base we can use
    minimum_base = max(min_base_A, min_base_B, min_base_C)

    valid_bases = []
    
    # Check all bases from the minimum to 10
    for base in range(max(minimum_base, 2), 11):
        if evaluate_expression(A, B, C, operator, base):
            valid_bases.append(base)

    return valid_bases

# Read input
expression = input().strip()

# Find valid bases
valid_bases = find_valid_bases(expression)

# Output the results
print(len(valid_bases))
if valid_bases:
    print(" ".join(map(str, valid_bases)))