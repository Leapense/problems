def painted_boards_count(A, B, C, D):
    # Calculate actual start and end of each range
    start1 = min(A, B)
    end1 = max(A, B)
    start2 = min(C, D)
    end2 = max(C, D)
    
    # Calculate length of painted sections
    length1 = end1 - start1 + 1
    length2 = end2 - start2 + 1
    
    # Calculate overlap
    overlap_start = max(start1, start2)
    overlap_end = min(end1, end2)
    if overlap_start <= overlap_end:
        overlap_length = overlap_end - overlap_start + 1
    else:
        overlap_length = 0
    
    # Calculate total unique painted boards
    total_painted = length1 + length2 - overlap_length
    
    return total_painted

A, B, C, D = map(int, input().split())
print(painted_boards_count(A, B, C, D))