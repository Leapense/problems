import math

def find_square(s):
    if s == 1:
        return [(0, 0), (1, 0), (0, 1), (1, 1)]
    
    root_s = int(math.isqrt(s))
    if root_s * root_s == s:
        return [(0, 0), (root_s, 0), (0, root_s), (root_s, root_s)]
    
    for a in range(int(math.sqrt(s)) + 1):
        b_squared = s - a * a
        b = int(math.sqrt(b_squared))
        if b * b == b_squared:
            x1, y1 = 0, 0
            x2, y2 = a, b
            x3, y3 = -b, a
            x4, y4 = a-b, b+a
            return [(x1, y1), (x2, y2), (x3, y3), (x4, y4)]
        
    return "Impossible"

s = int(input())
result = find_square(s)

if result == "Impossible":
    print(result)
else:
    for x, y in result:
        print(x, y)