def determine_scholarship(n, marks):
    # Check for any satisfactory mark
    if 3 in marks:
        return "None"
    
    # Check if all marks are excellent
    if all(mark == 5 for mark in marks):
        return "Named"
    
    # Calculate the average mark
    average_mark = sum(marks) / n
    
    # Check for high scholarship
    if average_mark >= 4.5:
        return "High"
    
    # If no satisfactory marks and no other higher scholarships, common scholarship
    return "Common"

# Read input
import sys
input = sys.stdin.read
data = input().split()

n = int(data[0])
marks = [int(data[i]) for i in range(1, n+1)]

# Determine and print the scholarship type
print(determine_scholarship(n, marks))