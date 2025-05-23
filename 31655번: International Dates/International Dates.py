def determine_date_format(date_str):
    parts = date_str.split('/')
    day_or_month1 = int(parts[0])
    day_or_month2 = int(parts[1])
    year = int(parts[2])

    is_us_format_possible = 1 <= day_or_month1 <= 12
    is_eu_format_possible = 1 <= day_or_month2 <= 12

    if is_us_format_possible and is_eu_format_possible:
        return 'either'
    elif is_us_format_possible:
        return 'US'
    elif is_eu_format_possible:
        return 'EU'
    else:
        return 'Invalid'
    
date_str = input()
print(determine_date_format(date_str))