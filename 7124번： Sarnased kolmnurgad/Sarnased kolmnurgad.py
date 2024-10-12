def find_similarity_factor(triangle1, triangle2):
    import math

    def calculate_sides(triangle):
        x1, y1, x2, y2, x3, y3 = triangle
        side1 = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
        side2 = math.sqrt((x3 - x2) ** 2 + (y3 - y2) ** 2)
        side3 = math.sqrt((x1 - x3) ** 2 + (y1 - y3) ** 2)

        return sorted([side1, side2, side3])
    
    sides1 = calculate_sides(triangle1)
    sides2 = calculate_sides(triangle2)

    ratios = [sides1[i] / sides2[i] for i in range(3)]
    k = ratios[0]

    if all(math.isclose(ratios[i], k, rel_tol=1e-5) for i in range(3)):
        return k
    else:
        return -1
    
triangle1_coords = list(map(int, input().split()))
triangle2_coords = list(map(int, input().split()))

similarity_factor = find_similarity_factor(triangle1_coords, triangle2_coords)

print(f"{similarity_factor:.4f}" if similarity_factor != -1 else "-1")