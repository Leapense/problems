def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    
    index = 0
    results = []
    
    while index < len(data):
        # Read n
        n = int(data[index])
        if n == 0:
            break
        index += 1
        
        # Read new members list
        new_members = list(map(int, data[index].split()))
        index += 1
        
        # Calculate maximum number of members in any year
        max_members = 0
        current_members = 0
        yearly_members = [0] * (n + 3)
        
        for i in range(n):
            yearly_members[i + 3] = new_members[i]
        
        for i in range(3, n + 3):
            current_members += yearly_members[i]
            current_members -= yearly_members[i - 3]
            if current_members > max_members:
                max_members = current_members
        
        results.append(max_members)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()