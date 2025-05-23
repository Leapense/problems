digits_to_braille = {
    '1': ['*.', '..', '..'],
    '2': ['*.', '*.', '..'],
    '3': ['**', '..', '..'],
    '4': ['**', '.*', '..'],
    '5': ['*.', '.*', '..'],
    '6': ['**', '*.', '..'],
    '7': ['**', '**', '..'],
    '8': ['*.', '**', '..'],
    '9': ['.*', '*.', '..'],
    '0': ['.*', '**', '..']
}

braille_to_digits = {tuple(v) : k for k, v in digits_to_braille.items()}

import sys

def main():
    input_lines = sys.stdin.read().splitlines()
    idx = 0
    while idx < len(input_lines):
        D_line = input_lines[idx].strip()
        if D_line == '':
            idx += 1
            continue
        D = int(D_line)
        if D == 0:
            break
        idx += 1
        mode = input_lines[idx].strip()
        idx += 1
        if mode == 'S':
            digits = input_lines[idx].strip()
            idx += 1
            row1 = []
            row2 = []
            row3 = []

            for digit in digits:
                braille = digits_to_braille[digit]
                row1.append(braille[0])
                row2.append(braille[1])
                row3.append(braille[2])
            print(' '.join(row1))
            print(' '.join(row2))
            print(' '.join(row3))
        elif mode == 'B':
            if idx + 2 >= len(input_lines):
                break
            braille_row1 = input_lines[idx].strip().split()
            braille_row2 = input_lines[idx + 1].strip().split()
            braille_row3 = input_lines[idx + 2].strip().split()
            idx += 3
            digits = []
            for i in range(D):
                cell = (braille_row1[i], braille_row2[i], braille_row3[i])
                digit = braille_to_digits.get(cell, '?')
                digits.append(digit)
            print(''.join(digits))
        else:
            pass
if __name__ == '__main__':
    main()