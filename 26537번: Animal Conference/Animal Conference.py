import math

def find_closest_pair(n, data_sets):
    results = []
    
    for z, animals in data_sets:
        min_dist = float('inf')
        closest_pair = None
        
        for i in range(z):
            for j in range(i + 1, z):
                x1, y1 = animals[i]
                x2, y2 = animals[j]
                dist_squared = (x2 - x1) ** 2 + (y2 - y1) ** 2
                
                if dist_squared < min_dist:
                    min_dist = dist_squared
                    closest_pair = sorted([(x1, y1), (x2, y2)])
                elif dist_squared == min_dist:
                    candidate_pair = sorted([(x1, y1), (x2, y2)])
                    if candidate_pair < closest_pair:
                        closest_pair = candidate_pair
        
        # Append the result in the format required
        results.append(f"{closest_pair[0][0]} {closest_pair[0][1]} {closest_pair[1][0]} {closest_pair[1][1]}")
    
    return results

# Reading input and invoking the function
def main():
    n = int(input())
    data_sets = []
    
    for _ in range(n):
        z = int(input())
        animals = []
        for _ in range(z):
            x, y = map(int, input().split())
            animals.append((x, y))
        data_sets.append((z, animals))
    
    results = find_closest_pair(n, data_sets)
    
    for result in results:
        print(result)

# Sample usage with the provided input
if __name__ == "__main__":
    main()