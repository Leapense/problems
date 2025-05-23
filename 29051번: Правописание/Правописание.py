def calculate_pen_lifts_more_adjustments(text):
    pen_lifts = {
        'A': 2, 'B': 1, 'C': 1, 'D': 1, 'E': 1, 'F': 1, 'G': 3,  # Adjusted G from 2 to 3
        'H': 2, 'I': 1, 'J': 1, 'K': 2, 'L': 1, 'M': 2,
        'N': 1, 'O': 1, 'P': 1, 'Q': 1, 'R': 2, 'S': 1,
        'T': 1, 'U': 1, 'V': 1, 'W': 1, 'X': 1, 'Y': 1, 'Z': 1
    }

    total_lifts = 0
    for letter in text:
        total_lifts += pen_lifts.get(letter, 1)

    return total_lifts

text = input().strip()
print(calculate_pen_lifts_more_adjustments(text))