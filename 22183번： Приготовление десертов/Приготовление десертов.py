def count_compatible_desserts(n, m, k, incompatible_crust_filling, incompatible_filling_icecream, incompatible_crust_icecream):
    # Compatibility matrix 3D: initially set everything to True
    compatible = [[[True for _ in range(k)] for _ in range(m)] for _ in range(n)]
    
    # Mark incompatible crust-filling pairs
    for crust, filling in incompatible_crust_filling:
        # Adjust to zero-indexed
        crust -= 1
        filling -= 1
        for icecream in range(k):
            compatible[crust][filling][icecream] = False
    
    # Mark incompatible filling-icecream pairs
    for filling, icecream in incompatible_filling_icecream:
        # Adjust to zero-indexed
        filling -= 1
        icecream -= 1
        for crust in range(n):
            compatible[crust][filling][icecream] = False
    
    # Mark incompatible crust-icecream pairs
    for crust, icecream in incompatible_crust_icecream:
        # Adjust to zero-indexed
        crust -= 1
        icecream -= 1
        for filling in range(m):
            compatible[crust][filling][icecream] = False
    
    # Count all True values in the compatibility 3D matrix
    count = 0
    for crust in range(n):
        for filling in range(m):
            for icecream in range(k):
                if compatible[crust][filling][icecream]:
                    count += 1
    
    return count

n, m, k = map(int, input().split())
p = int(input())
incompatible_crust_filling = [tuple(map(int, input().split())) for _ in range(p)]
q = int(input())
incompatible_filling_icecream = [tuple(map(int, input().split())) for _ in range(q)]
r = int(input())
incompatible_crust_icecream = [tuple(map(int, input().split())) for _ in range(r)]

result = count_compatible_desserts(n, m, k, incompatible_crust_filling, incompatible_filling_icecream, incompatible_crust_icecream)

print(result)