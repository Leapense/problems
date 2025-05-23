hour, minute, second = map(int, input().split())

# Add one second

second += 1

# Check if we need to increase the minute or hour
if second == 60:
    second = 0
    minute += 1

    if minute == 60:
        minute = 0
        hour += 1

        if hour == 24:
            hour = 0

print(f"{hour:02d}:{minute:02d}:{second:02d}")