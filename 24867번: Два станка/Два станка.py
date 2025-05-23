def max_parts_produced(k, a, x, b, y):
    # Scenario 1: Setup the first machine first
    parts_first_scenario = 0
    if k >= a:
        remaining_time = k - a
        parts_first_scenario += remaining_time * x
        remaining_time_after_second_setup = remaining_time - b
        if remaining_time_after_second_setup >= 0:
            parts_first_scenario += remaining_time_after_second_setup * y
    
    # Scenario 2: Setup the second machine first
    parts_second_scenario = 0
    if k >= b:
        remaining_time = k - b
        parts_second_scenario += remaining_time * y
        remaining_time_after_first_setup = remaining_time - a
        if remaining_time_after_first_setup >= 0:
            parts_second_scenario += remaining_time_after_first_setup * x
    
    # Return the maximum of the two scenarios
    return max(parts_first_scenario, parts_second_scenario)

# Reading inputs
k = int(input())
a, x = map(int, input().split())
b, y = map(int, input().split())

# Calculate the maximum number of parts produced
result = max_parts_produced(k, a, x, b, y)
print(result)