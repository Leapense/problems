def time_to_minutes(time_str):
    hours, minutes = map(int, time_str.split(':'))
    return hours * 60 + minutes

def calculate_battery_percentage(n, x, y, times):
    current_time = 0
    battery_percentage = 100.0
    charging = True

    times = [time_to_minutes(time) for time in times]
    times.append(23 * 60 + 59)

    for next_time in times:
        duration = next_time - current_time

        if charging:
            battery_percentage += duration / y * 100
        else:
            battery_percentage -= duration / x * 100

        battery_percentage = max(0, min(100, battery_percentage))

        charging = not charging
        current_time = next_time
    
    return battery_percentage

n, x, y = map(int, input().split())
times = [input().strip() for _ in range(n)]

print(calculate_battery_percentage(n, x, y, times))