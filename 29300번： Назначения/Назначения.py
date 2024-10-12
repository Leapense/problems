def lex_min_string(s):
    unique_chars = set(s)
    min_string = None

    for c in unique_chars:
        filtered = ''.join([ch for ch in s if ch != c])
        if min_string is None or filtered < min_string:
            min_string = filtered
    
    return min_string

import sys

def main():
    s = sys.stdin.read().strip()
    result = lex_min_string(s)
    print(result)

if __name__ == "__main__":
    main()