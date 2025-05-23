def max_square_length(a1, a2, a3, a4):
    def can_form_square(k):
        # Required number of triangles to form a k x k square
        required_triangles = 2 * k * k
        # We need exactly half the triangles of two orientations combined
        half_required = k * k
        
        # Check if we can form k*k triangles of each of the opposite orientations
        return min(a1, a4) + min(a2, a3) >= half_required

    # Binary search for the maximum side length of the square
    low, high = 0, int(1e9)  # Setting a practical upper bound

    while low < high:
        mid = (low + high + 1) // 2
        if can_form_square(mid):
            low = mid
        else:
            high = mid - 1
    
    return low

# Example usage
a1, a2, a3, a4 = map(int, input().split())
print(max_square_length(a1, a2, a3, a4))
