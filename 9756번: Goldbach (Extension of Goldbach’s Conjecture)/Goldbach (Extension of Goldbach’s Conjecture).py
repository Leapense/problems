def find_odd_sequence(m):
    if m == 0:
        return False, 0  # Special case to stop processing
    
    m3 = m ** 3
    first_odd = m ** 2 - m + 1
    
    return True, first_odd

# Reading input values
import sys
input = sys.stdin.read
data = input().strip().split()

results = []

for val in data:
    m = int(val)
    if m == 0:
        break
    can_find, first_odd = find_odd_sequence(m)
    if can_find:
        results.append(f"Y {first_odd}")
    else:
        results.append("N 0")

# Printing results
for result in results:
    print(result)