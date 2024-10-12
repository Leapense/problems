def check_conditions(team_name):
    # Check if the team name has more or equal lowercase than uppercase letters
    lowercase_count = sum(1 for char in team_name if char.islower())
    uppercase_count = sum(1 for char in team_name if char.isupper())
    cond1 = lowercase_count >= uppercase_count
    
    # Check if the team name length is 10 or less
    cond2 = len(team_name) <= 10
    
    # Check if there is at least one non-digit character
    cond3 = not team_name.isdigit()
    
    # Return True if all conditions are met
    return all([cond1, cond2, cond3])

# Input reading
N = int(input())
team_names = [input() for _ in range(N)]

# Find the team name that meets all conditions
valid_team_name = None
for name in team_names:
    if check_conditions(name):
        valid_team_name = name
        break

# Output the result
print(valid_team_name)