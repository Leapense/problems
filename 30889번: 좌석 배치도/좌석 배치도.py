seating_chart = [['.' for _ in range(20)] for _ in range(10)]

# Read input
import sys
input = sys.stdin.read
data = input().split()

# Number of reservations
N = int(data[0])

# Process each reservation
for i in range(1, N + 1):
    seat = data[i]
    row_char = seat[0]
    column = int(seat[1:])
    
    # Convert row character to row index (0-based)
    row_index = ord(row_char) - ord('A')
    # Convert column number to column index (0-based)
    column_index = column - 1
    
    # Mark the seat as reserved
    seating_chart[row_index][column_index] = 'o'

# Print the seating chart
for row in seating_chart:
    print("".join(row))