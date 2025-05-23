def find_generations(data_sets):
    results = []
    for idx, (L, n, parents) in enumerate(data_sets):
        generations = 0
        current = L
        
        while current != 0:
            generations += 1
            current = parents[current - 1]
        
        results.append(f"Data Set {idx + 1}:\n{generations}\n")
    
    return "\n".join(results)

K = int(input())
data_sets = []

for i in range(K):
    L, n = map(int, input().split())
    parents = list(map(int, input().split()))
    data_sets.append((L, n, parents))

print(find_generations(data_sets))