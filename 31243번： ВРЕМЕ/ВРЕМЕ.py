def time_to_minutes(hours, minutes):
    return hours * 60 + minutes

def minutes_to_time(minutes):
    hours = minutes // 60
    minutes = minutes % 60
    return f"{hours}:{minutes:02}"

def calculate_duration(start_h, start_m, end_h, end_m):
    start_time = time_to_minutes(start_h, start_m)
    end_time = time_to_minutes(end_h, end_m)
    if end_time < start_time:
        end_time += 24 * 60  # Adjust for next day arrival
    return end_time - start_time

import sys
input = sys.stdin.read
data = input().split()

start_end_times = [(int(data[i]), int(data[i+1]), int(data[i+2]), int(data[i+3])) for i in range(0, len(data), 4)]

durations = [calculate_duration(start_h, start_m, end_h, end_m) for start_h, start_m, end_h, end_m in start_end_times]

min_duration = min(durations)
max_duration = max(durations)

print(minutes_to_time(min_duration))
print(minutes_to_time(max_duration))