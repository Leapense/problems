def is_optimal_launch_year(year):
    # April 2018 in months since the year 0
    april_2018 = 2018 * 12 + 4
    
    # Convert the given year to the range in months
    start_month = year * 12 + 1
    end_month = year * 12 + 12
    
    # Check each 26-month interval starting from April 2018
    current_window_start = april_2018
    while current_window_start <= end_month:
        current_window_end = current_window_start + 25
        if current_window_start <= end_month and current_window_start >= start_month:
            return "yes"
        current_window_start += 26
    
    return "no"

# Input handling
y = int(input())
print(is_optimal_launch_year(y))

# STOP BREAKING THE TWITTER UI ELON MUSK!