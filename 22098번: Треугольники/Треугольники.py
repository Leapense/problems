def classify_triangle(a, b, c):
    sides = sorted([a, b, c])
    if sides[0] + sides[1] <= sides[2]:
        return None  # Not a valid triangle
    
    a2, b2, c2 = sides[0]**2, sides[1]**2, sides[2]**2
    
    if a2 + b2 == c2:
        return 'right'
    elif a2 + b2 > c2:
        return 'acute'
    else:
        return 'obtuse'

def count_triangles(segments):
    from itertools import combinations
    
    right_count = 0
    acute_count = 0
    obtuse_count = 0
    
    for combo in combinations(segments, 3):
        triangle_type = classify_triangle(*combo)
        if triangle_type == 'right':
            right_count += 1
        elif triangle_type == 'acute':
            acute_count += 1
        elif triangle_type == 'obtuse':
            obtuse_count += 1
    
    return right_count, acute_count, obtuse_count

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])
    index = 1
    results = []
    
    for _ in range(T):
        segments = list(map(int, data[index:index+4]))
        index += 4
        results.append(count_triangles(segments))
    
    for result in results:
        print(result[0], result[1], result[2])

if __name__ == "__main__":
    main()