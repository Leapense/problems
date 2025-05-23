def can_get_passport(arrival_time, n, windows):
    # Helper function to convert time hh:mm to minutes since midnight
    def time_to_minutes(t):
        hh, mm = map(int, t.split(':'))
        return hh * 60 + mm

    # Read the arrival time in minutes since midnight
    current_time = time_to_minutes(arrival_time)

    # Process each window
    for i in range(n):
        open_time, close_time, service_duration = windows[i]
        
        # Convert times to minutes since midnight
        open_time = time_to_minutes(open_time)
        close_time = time_to_minutes(close_time)
        service_duration = int(service_duration)

        # Determine if service can start
        if current_time < open_time:
            current_time = open_time
        
        # Last time to start the service so it can finish
        last_possible_start = close_time - service_duration

        # Check if we can be served at this window
        if current_time > last_possible_start:
            return "No"
        
        # Update current time to the time we will finish this service
        current_time += service_duration

    # If we can finish all services, calculate the end time
    end_hh = current_time // 60
    end_mm = current_time % 60
    return "Yes\n{:02}:{:02}".format(end_hh, end_mm)

arrival_time = input()
n = int(input())
windows = [input().split() for _ in range(n)]

print(can_get_passport(arrival_time, n, windows))