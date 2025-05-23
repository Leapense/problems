def find_histogram_sequence(height_sequence):
    n = len(height_sequence)
    histogram_sequence = []
    
    if n == 0:
        return histogram_sequence
    
    current_height = height_sequence[0]
    current_count = 0
    
    for height in height_sequence:
        if height == current_height:
            current_count += 1
        else:
            histogram_sequence.append(current_count)
            current_height = height
            current_count = 1
            
    # Don't forget to append the last group
    histogram_sequence.append(current_count)
    
    return histogram_sequence

# Example usage
m = int(input())
height_sequence = list(map(int, input().split()))
histogram_sequence = find_histogram_sequence(height_sequence)
print(" ".join(map(str, histogram_sequence)))
