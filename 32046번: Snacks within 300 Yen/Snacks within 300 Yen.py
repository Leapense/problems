def process_snacks():
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")
    
    results = []
    index = 0
    
    while index < len(data):
        line = data[index].strip()
        if line == "0":
            break
        
        n = int(line)
        index += 1
        snacks = list(map(int, data[index].strip().split()))
        index += 1
        
        total_cost = 0
        for price in snacks:
            if total_cost + price <= 300:
                total_cost += price
        
        results.append(total_cost)
    
    for result in results:
        print(result)

process_snacks()