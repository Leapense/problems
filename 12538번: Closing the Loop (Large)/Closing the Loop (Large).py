def solve():
    import sys
    
    input_data = sys.stdin.read().strip().split()
    # index to traverse input_data
    idx = 0
    
    # Number of test cases
    T = int(input_data[idx]); idx += 1
    
    for case_num in range(1, T + 1):
        # Number of rope segments
        S = int(input_data[idx])
        idx += 1
        
        # Lists to store lengths
        blue_segments = []
        red_segments = []
        
        for _ in range(S):
            segment = input_data[idx]
            idx += 1
            # Separate length from color. Example: "5B" => length=5, color='B'
            length_str = segment[:-1]  # All but last char
            color = segment[-1]       # Last char: 'B' or 'R'
            length = int(length_str)
            
            if color == 'B':
                blue_segments.append(length)
            else:  # color == 'R'
                red_segments.append(length)
        
        # Sort lists in descending order
        blue_segments.sort(reverse=True)
        red_segments.sort(reverse=True)
        
        # Maximum number of pairs is limited by the smaller list
        m = min(len(blue_segments), len(red_segments))
        
        if m == 0:
            # Cannot form any loop if we don't have at least one of each color
            print(f"Case #{case_num}: 0")
            continue
        
        # Sum of the top m lengths in each color
        total_length = sum(blue_segments[:m]) + sum(red_segments[:m])
        # Subtract the knots for each used segment (2m segments => 2m knots)
        loop_length = total_length - 2 * m
        
        # Output the result
        print(f"Case #{case_num}: {loop_length}")

solve()