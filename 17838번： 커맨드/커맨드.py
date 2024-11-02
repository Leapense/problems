def is_favorite_command(command):
    # Check if the length is exactly 7
    if len(command) != 7:
        return 0
    
    # Check if there are exactly 2 distinct characters
    unique_chars = set(command)
    if len(unique_chars) != 2:
        return 0
    
    # Extract the two characters
    char1, char2 = list(unique_chars)
    
    # Check if the string matches the pattern AABBABB with the two characters
    pattern1 = char1 + char1 + char2 + char2 + char1 + char2 + char2
    pattern2 = char2 + char2 + char1 + char1 + char2 + char1 + char1
    
    if command == pattern1 or command == pattern2:
        return 1
    else:
        return 0

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])
    results = []
    
    for i in range(1, T + 1):
        command = data[i]
        results.append(is_favorite_command(command))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()