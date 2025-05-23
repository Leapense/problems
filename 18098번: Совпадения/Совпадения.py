def count_matching_passports(N, passports):
    room_set = set(range(1, N + 1))  # Set of all possible room numbers
    count = 0
    
    for passport in passports:
        if passport in room_set:
            count += 1
            room_set.remove(passport)  # Remove to avoid counting this room number again
    
    return count

# Input reading
import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
passports = [int(data[i]) for i in range(1, N + 1)]

# Calculate and print the result
result = count_matching_passports(N, passports)
print(result)