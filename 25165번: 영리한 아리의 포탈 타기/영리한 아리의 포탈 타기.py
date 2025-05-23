def simulate_ari_path(N, M, Ac, D, Sr, Sc):
    # Ari's initial position and direction
    current_col = Ac
    current_row = 1
    direction = D  # 0 is left, 1 is right
    
    while current_row <= N:
        # Determine the range of columns Ari will move across this row
        if direction == 0:
            # Moving left to column 1
            start_col = current_col
            end_col = 1
            step = -1
        else:
            # Moving right to column M
            start_col = current_col
            end_col = M
            step = 1
        
        # Simulate movement across the row
        for col in range(start_col, end_col + step, step):
            if current_row == Sr and col == Sc:
                # Ari meets the minion
                return "NO..."
        
        # Move to the next row
        current_row += 1
        # Update the start column for the next row based on current end direction
        if direction == 0:
            current_col = 1  # She will start from the leftmost column next row
        else:
            current_col = M  # She will start from the rightmost column next row
        
        # Toggle the direction for the next row
        direction = 1 - direction
    
    # If we finished all rows without meeting the minion
    return "YES!"

N, M = map(int, input().split())
Ac, D = map(int, input().split())
Sr, Sc = map(int, input().split())
print(simulate_ari_path(N, M, Ac, D, Sr, Sc))