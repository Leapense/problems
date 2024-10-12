from datetime import datetime, timedelta

def feeding_interval(time_today, time_tomorrow):
    # Define the date part for today and tomorrow
    today_date = "2024-07-20"
    tomorrow_date = "2024-07-21"
    
    # Parse today's feeding time
    today_datetime = datetime.strptime(f"{today_date} {time_today}", "%Y-%m-%d %H:%M")
    # Parse tomorrow's feeding time
    tomorrow_datetime = datetime.strptime(f"{tomorrow_date} {time_tomorrow}", "%Y-%m-%d %H:%M")
    
    # Calculate the difference
    diff = tomorrow_datetime - today_datetime
    
    # Convert the difference to total minutes
    total_minutes = diff.total_seconds() // 60
    diff_hours = int(total_minutes // 60)
    diff_minutes = int(total_minutes % 60)
    
    # Format the result to HH:MM with leading zeros if necessary
    result = f"{diff_hours:02}:{diff_minutes:02}"
    
    return result

# Read input
time_today = input().strip()
time_tomorrow = input().strip()

# Calculate and print the feeding interval
print(feeding_interval(time_today, time_tomorrow))
