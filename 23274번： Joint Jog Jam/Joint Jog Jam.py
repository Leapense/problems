import math

def max_distance(x1, y1, x2, y2, x3, y3, x4, y4):
    def distance(t):
        # Kari's position at time t
        kx = x1 + t * (x3 - x1)
        ky = y1 + t * (y3 - y1)
        # Ola's position at time t
        ox = x2 + t * (x4 - x2)
        oy = y2 + t * (y4 - y2)
        # Euclidean distance between Kari and Ola at time t
        return math.sqrt((kx - ox) ** 2 + (ky - oy) ** 2)
    
    # Ternary search for maximum value of the distance function in the range [0, 1]
    left, right = 0.0, 1.0
    while right - left > 1e-9:
        mid1 = left + (right - left) / 3
        mid2 = right - (right - left) / 3
        if distance(mid1) < distance(mid2):
            left = mid1
        else:
            right = mid2
    
    # Output the maximum distance found
    print(f"{distance(left):.10f}")

x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
max_distance(x1, y1, x2, y2, x3, y3, x4, y4)