def pyramid_height(N):
    height = 0
    total_blocks = 0
    current_side_length = 1
    
    while True:
        required_blocks = current_side_length ** 2
        if total_blocks + required_blocks > N:
            break
        total_blocks += required_blocks
        height += 1
        current_side_length += 2
        
    return height

# Example usage
N = int(input().strip())
print(pyramid_height(N))