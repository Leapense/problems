import math

def find_cut_point(X, Y):
    # The vertical line must divide the triangle into two parts with equal area
    # The total area of the triangle
    total_area = 0.5 * X * Y
    # We want the left part when cut at x to have an area of half the total area
    target_area = total_area / 2
    
    # Binary search to find the value of x
    low, high = 0, X
    while high - low > 1e-7:
        mid = (low + high) / 2
        # Area on the left of the line x = mid
        # The triangle is from (0,0) to (mid,0) to (mid, Y * (1 - mid/X))
        y_at_mid = Y * (1 - mid / X)
        left_area = 0.5 * mid * y_at_mid
        
        if left_area < target_area:
            low = mid
        else:
            high = mid
    
    return low

# Example input
X, Y = map(int, input().split())
x = find_cut_point(X, Y)
print(f"{x:.9f}")
