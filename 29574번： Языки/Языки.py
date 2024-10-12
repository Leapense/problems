def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the digit names
    digit_names = data[:10]  # The first 10 entries are the names of the digits 0-9
    queries_index = 11  # 1st line + 10 digit names
    
    # Number of queries
    num_queries = int(data[10])
    
    # Collect all queries
    queries = data[queries_index:queries_index + num_queries]
    
    # Mapping digit to their names
    digit_to_name = {str(i): digit_names[i] for i in range(10)}
    
    results = []
    
    # Process each query
    for number in queries:
        # We need to find the highest lexicographical name among the digits in this number
        seen_names = []
        
        # Check each digit in the number and collect their names
        seen = set()
        for char in number:
            if char not in seen:
                seen.add(char)
                seen_names.append(digit_to_name[char])
        
        # Find the maximum lexicographical name
        max_name = max(seen_names)
        
        # Append the result for this number
        results.append(max_name)
    
    # Output results
    for result in results:
        print(result)

if __name__ == '__main__':
    main()