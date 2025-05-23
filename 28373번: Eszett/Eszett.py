def main():
    import sys
    input = sys.stdin.read
    
    S = input().strip()
    s = S.lower()
    
    results = []
    
    # Look for positions with 'ss' and generate strings replacing 'ss' with 'B'
    for i in range(len(s) - 1):
        if s[i] == 's' and s[i + 1] == 's':
            # Replace 'ss' with 'B' at position i
            new_string = s[:i] + 'B' + s[i+2:]
            results.append(new_string)
    
    # Output the original lowercase version
    print(s)
    
    # Output all versions with 'ss' replaced by 'B'
    for result in results:
        print(result)

# This setup assumes that the input will be provided similarly to how Java receives it,
# for example through a command-line pipe or a redirected input file.
if __name__ == "__main__":
    main()
