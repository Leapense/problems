def generate_password(n, a, b, c):
    import random
    
    # Characters pools
    uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    lowercase = 'abcdefghijklmnopqrstuvwxyz'
    digits = '0123456789'
    
    # Minimum requirements
    required_upper = a
    required_lower = b
    required_digits = c
    
    password = []
    current_length = 0
    
    # Function to add a character from a pool that is not the same as the last character
    def add_char_from_pool(pool, last_char):
        available_choices = [ch for ch in pool if ch != last_char]
        if not available_choices:  # edge case if pool is extremely restricted, usually doesn't happen
            return last_char if pool == last_char else random.choice(pool)
        return random.choice(available_choices)
    
    # Start filling the password ensuring each component is at least filled as required
    for _ in range(required_upper):
        char = add_char_from_pool(uppercase, password[-1] if password else '')
        password.append(char)
        current_length += 1
    
    for _ in range(required_lower):
        char = add_char_from_pool(lowercase, password[-1] if password else '')
        password.append(char)
        current_length += 1
    
    for _ in range(required_digits):
        char = add_char_from_pool(digits, password[-1] if password else '')
        password.append(char)
        current_length += 1
    
    # Fill the remaining characters needed to make the length n
    while current_length < n:
        # Choose a pool based on shortage to balance out remaining characters
        if len(password) >= 2:
            last_char = password[-1]
        else:
            last_char = ''
        
        # Choose which type of character to add more of
        if required_upper < a or current_length - (required_lower + required_digits) < a:
            char = add_char_from_pool(uppercase, last_char)
            required_upper += 1
        elif required_lower < b or current_length - (required_upper + required_digits) < b:
            char = add_char_from_pool(lowercase, last_char)
            required_lower += 1
        else:
            char = add_char_from_pool(digits, last_char)
            required_digits += 1
            
        password.append(char)
        current_length += 1
    
    # The last scrambling to ensure no beginning to end issues
    for i in range(1, len(password)):
        if password[i] == password[i - 1]:
            # Swap with some other position
            for j in range(len(password)):
                if j != i and password[j] != password[i]:
                    password[i], password[j] = password[j], password[i]
                    break
    
    return ''.join(password)

# Reading input
n = int(input().strip())
a, b, c = map(int, input().strip().split())

# Generate and output the password
print(generate_password(n, a, b, c))
