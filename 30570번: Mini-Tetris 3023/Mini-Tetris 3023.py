def max_width(a, b, c):
    points_from_a = a * 2

    points_from_b = 0
    if b > 0 and c >= 2:
        points_from_b = b * 2
    
    points_from_c = c // 2 * 3

    return points_from_a + points_from_b + points_from_c

# Example usage (replace with actual input values)
a, b, c = map(int, input().split())
result = max_width(a, b, c)
print(result)