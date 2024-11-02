def find_possible_missing_entry(n, a, b, entries):
    # Determine the possible values for the missing entry
    possible_entries = set(range(a, b + 1))
    
    # Create sets to check for the presence of a and b
    entry_set = set(entries)
    
    # Check if a and b are already in the entries
    has_a = a in entry_set
    has_b = b in entry_set
    
    # If a is not in the entries, then a must be one of the possible missing entries
    if not has_a:
        possible_entries.add(a)
    
    # If b is not in the entries, then b must be one of the possible missing entries
    if not has_b:
        possible_entries.add(b)
    
    # The missing entry must ensure the presence of both a and b in the final list
    valid_missing_entries = sorted([x for x in possible_entries if (has_a or x == a) and (has_b or x == b)])
    
    # If there are no valid entries, return -1
    if not valid_missing_entries:
        return [-1]
    
    return valid_missing_entries

# Read input
import sys
input = sys.stdin.read
data = input().split()

n = int(data[0])
a = int(data[1])
b = int(data[2])
entries = list(map(int, data[3:]))

# Find and print possible missing entries
possible_entries = find_possible_missing_entry(n, a, b, entries)
print("\n".join(map(str, possible_entries)))