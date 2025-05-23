import math

def minimum_tile_area(a):
    # Step 1: Calculate the radius of the circle
    r = math.sqrt(a / math.pi)
    
    # Step 2: Calculate the side length of the square tile
    s = 2 * r + 2
    
    # Step 3: Calculate the area of the square tile
    tile_area = s * s
    
    return tile_area

# Example usage
a = int(input().strip())
print(f"{minimum_tile_area(a):.10f}")