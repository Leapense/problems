def shift_by_13(password):
    result = []
    for char in password:
        shifted_char = chr(((ord(char) - ord('a') + 13) % 26) + ord('a'))
        result.append(shifted_char)
    return ''.join(result)

def solve(test_cases):
    results = []
    for password in test_cases:
        shifted_password = shift_by_13(password)
        if shifted_password == password:
            results.append("NIE")
        else:
            results.append(shifted_password)
    return results

# Input/Output
z = int(input().strip())
test_cases = [input().strip() for _ in range(z)]

results = solve(test_cases)
for result in results:
    print(result)
