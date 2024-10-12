def solve():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    h = int(data[0])
    m = int(data[1])
    dh = int(data[2])
    dm = int(data[3])
    c = int(data[4])
    
    if c == 1:
        # Calculate the new time
        total_minutes = m + dm
        total_hours = h + dh + total_minutes // 60
        new_minutes = total_minutes % 60
        new_hours = total_hours % 12
        
        print(new_hours, new_minutes)
    
    elif c == 2:
        # Calculate the exact minute mark the hour hand points to
        
        # Initial position in minute marks
        initial_position = (h * 5) + (m / 12.0)
        
        # Additional movement in minute marks
        additional_minutes = dh * 60 + dm
        movement_in_marks = additional_minutes / 12.0
        
        # Calculate the total position on the minute track
        total_position = (initial_position + movement_in_marks) % 60
        
        # Determine exact or between marks
        lower_bound = int(total_position)
        upper_bound = (lower_bound + 1) % 60
        
        if abs(total_position - lower_bound) < 1e-9:  # Float precision handling
            # Exact position on a minute mark
            print(f"@ {lower_bound}")
        else:
            # Between two minute marks
            print(f"{lower_bound} {upper_bound}")

if __name__ == "__main__":
    solve()