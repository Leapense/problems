import sys

PATTERN_DICT = {
    '0': (
        'xxxxx',
        'x...x',
        'x...x',
        'x...x',
        'x...x',
        'x...x',
        'xxxxx'
    ),
    '1': (
        '....x',
        '....x',
        '....x',
        '....x',
        '....x',
        '....x',
        '....x'
    ),
    '2': (
        'xxxxx',
        '....x',
        '....x',
        'xxxxx',
        'x....',
        'x....',
        'xxxxx'
    ),
    '3': (
        'xxxxx',
        '....x',
        '....x',
        'xxxxx',
        '....x',
        '....x',
        'xxxxx'
    ),
    '4': (
        'x...x',
        'x...x',
        'x...x',
        'xxxxx',
        '....x',
        '....x',
        '....x'
    ),
    '5': (
        'xxxxx',
        'x....',
        'x....',
        'xxxxx',
        '....x',
        '....x',
        'xxxxx'
    ),
    '6': (
        'xxxxx',
        'x....',
        'x....',
        'xxxxx',
        'x...x',
        'x...x',
        'xxxxx'
    ),
    '7': (
        'xxxxx',
        '....x',
        '....x',
        '....x',
        '....x',
        '....x',
        '....x'
    ),
    '8': (
        'xxxxx',
        'x...x',
        'x...x',
        'xxxxx',
        'x...x',
        'x...x',
        'xxxxx'
    ),
    '9': (
        'xxxxx',
        'x...x',
        'x...x',
        'xxxxx',
        '....x',
        '....x',
        'xxxxx'
    ),
    '+': (
        '.....',
        '..x..',
        '..x..',
        'xxxxx',
        '..x..',
        '..x..',
        '.....'
    )
}

def main():
    data = sys.stdin.read().splitlines()
    if len(data) != 7:
        return
    
    input_rows = data
    width = len(input_rows[0])
    k = (width + 1) // 6

    token_patterns = []

    for i in range(k):
        pattern = tuple(row[i * 6 : i * 6 + 5] for row in input_rows)
        token_patterns.append(pattern)

    tokens = []
    for pat in token_patterns:
        found = False
        for ch, template in PATTERN_DICT.items():
            if pat == template:
                tokens.append(ch)
                found = True
                break
        if not found:
            raise ValueError("Unknown pattern encountered.")
        
    plus_index = tokens.index('+')
    a_str = ''.join(tokens[:plus_index])
    b_str = ''.join(tokens[plus_index+1:])

    a = int(a_str)
    b = int(b_str)
    c = a + b
    c_str = str(c)

    output_rows = [''] * 7

    for idx, digit in enumerate(c_str):
        digit_pattern = PATTERN_DICT[digit]

        if idx == 0:
            for r in range(7):
                output_rows[r] += digit_pattern[r]

        else:
            for r in range(7):
                output_rows[r] += '.' + digit_pattern[r]


    for row in output_rows:
        print(row)

if __name__ == "__main__":
    main()