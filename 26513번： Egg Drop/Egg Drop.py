def solve():
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")
    
    index = 0
    results = []
    
    while index < len(data):
        # Read the first line of a dataset
        line = data[index].strip()
        index += 1
        
        if line == "0 0":
            break
        
        n, k = map(int, line.split())
        mn = 1
        mx = k
        
        for _ in range(n):
            floor, result = data[index].strip().split()
            index += 1
            floor = int(floor)
            
            if result[0] == 'S':
                mn = max(mn, floor)
            else:
                mx = min(mx, floor)
        
        results.append(str(mn + 1) + " " + str(mx - 1))
    
    if results:
        print("\n".join(results))

solve()