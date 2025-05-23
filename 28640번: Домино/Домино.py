def can_match_dominoes(domino1, domino2):
    # Parse each domino's sides based on the '|' separator
    left1, right1 = domino1.split('|')
    left2, right2 = domino2.split('|')
    
    # Count the dots on each side
    left1_count = left1.count('.')
    right1_count = right1.count('.')
    left2_count = left2.count('.')
    right2_count = right2.count('.')
    
    # Create sets of counts for each domino
    domino1_counts = {left1_count, right1_count}
    domino2_counts = {left2_count, right2_count}
    
    # Check if there's any intersection in the count sets
    if domino1_counts & domino2_counts:
        return "Yes"
    else:
        return "No"

# Read input
domino1 = input().strip()
domino2 = input().strip()

# Output result
print(can_match_dominoes(domino1, domino2))