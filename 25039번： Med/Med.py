n = int(input())
beekeepers = []

for _ in range(n):
    parts = input().split()
    name = parts[0]
    scores = list(map(int, parts[1:6]))
    total = sum(scores)
    beekeepers.append((name, total))

results = []

for i in range(n):
    current_name, current_sum = beekeepers[i]
    
    # Calculate best possible rank
    best_case = []
    for j in range(n):
        if j == i:
            total_j = current_sum + 500
        else:
            total_j = beekeepers[j][1]
        best_case.append((-total_j, beekeepers[j][0]))
    best_case_sorted = sorted(best_case)
    best_rank = None
    for idx, (t, name) in enumerate(best_case_sorted):
        if name == current_name:
            best_rank = idx + 1
            break
    
    # Calculate worst possible rank
    worst_case = []
    for j in range(n):
        if j == i:
            total_j = current_sum
        else:
            total_j = beekeepers[j][1] + 500
        worst_case.append((-total_j, beekeepers[j][0]))
    worst_case_sorted = sorted(worst_case)
    worst_rank = None
    for idx, (t, name) in enumerate(worst_case_sorted):
        if name == current_name:
            worst_rank = idx + 1
            break
    
    results.append((best_rank, worst_rank))

for res in results:
    print(res[0], res[1])