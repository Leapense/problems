# Define the patterns for digits 0-9
digit_patterns = [
    [
        "..#####..",
        ".##...##.",
        "##.....##",
        "##.....##",
        "##.....##",
        ".##...##.",
        "..#####..",
        "........."
    ],
    [
        "....##...",
        "..####...",
        "....##...",
        "....##...",
        "....##...",
        "....##...",
        "..######.",
        "........."
    ],
    [
        ".#######.",
        "##.....##",
        ".......##",
        ".#######.",
        "##.......",
        "##.......",
        "#########",
        "........."
    ],
    [
        ".#######.",
        "##.....##",
        ".......##",
        ".#######.",
        ".......##",
        "##.....##",
        ".#######.",
        "........."
    ],
    [
        "##.......",
        "##....##.",
        "##....##.",
        "##....##.",
        "#########",
        "......##.",
        "......##.",
        "........."
    ],
    [
        ".########",
        ".##......",
        ".##......",
        ".#######.",
        ".......##",
        ".##....##",
        "..######.",
        "........."
    ],
    [
        ".#######.",
        "##.....##",
        "##.......",
        "########.",
        "##.....##",
        "##.....##",
        ".#######.",
        "........."
    ],
    [
        ".########",
        ".##....##",
        ".....##..",
        "....##...",
        "...##....",
        "...##....",
        "...##....",
        "........."
    ],
    [
        ".#######.",
        "##.....##",
        "##.....##",
        ".#######.",
        "##.....##",
        "##.....##",
        ".#######.",
        "........."
    ],
    [
        ".#######.",
        "##.....##",
        "##.....##",
        ".########",
        ".......##",
        "##.....##",
        ".#######.",
        "........."
    ]
]

def read_input():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    N = int(data[0])
    patterns = data[1:]
    return N, patterns

def extract_digit_patterns(N, patterns):
    digits = []
    for i in range(N):
        digit_pattern = patterns[i*8:(i+1)*8]
        digits.append(digit_pattern)
    return digits

def match_digit(digit_pattern):
    for i, pattern in enumerate(digit_patterns):
        if pattern == digit_pattern:
            return i
    return None

def main():
    N, patterns = read_input()
    digits_patterns = extract_digit_patterns(N, patterns)
    number = ''
    for digit_pattern in digits_patterns:
        digit = match_digit(digit_pattern)
        if digit is not None:
            number += str(digit)
    print(number)

if __name__ == "__main__":
    main()
