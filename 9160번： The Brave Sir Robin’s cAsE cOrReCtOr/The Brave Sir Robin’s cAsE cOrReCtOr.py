import sys

def case_correct(text):
    n = len(text)
    result = []
    uppercase_next = False
    i = 0

    while i < n:
        char = text[i]
        
        if uppercase_next:
            if char.isalpha():
                # If the next alpha character after punctuation, convert to uppercase
                result.append(char.upper())
                uppercase_next = False
            elif char not in (' ', '\t', '\n', '(', ')'):
                # If we encounter any non-whitespace and non-parentheses
                # and non-alpha character, stop trying to uppercase
                result.append(char.lower())
                uppercase_next = False
            else:
                # It's a whitespace or parentheses, add as is
                result.append(char)
        else:
            result.append(char.lower())
        
        # Determine if the next alpha should be uppercased
        if char in ('.', '?', '!'):
            uppercase_next = True
        
        i += 1
    
    return ''.join(result)

def main():
    input_text = sys.stdin.read()
    output_text = case_correct(input_text)
    print(output_text, end="")

if __name__ == "__main__":
    main()