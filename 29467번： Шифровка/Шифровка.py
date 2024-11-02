def find_max_lexicographical_substring(s: str) -> str:
    max_substring = ""
    n = len(s)
    
    for i in range(n):
        current_substring = s[i:]
        if current_substring > max_substring:
            max_substring = current_substring
    
    return max_substring

# Example usage
if __name__ == "__main__":
    import sys
    input = sys.stdin.read().strip()
    result = find_max_lexicographical_substring(input)
    print(result)