def decrypt(text, distance):
    decrypted_text = ""
    for char in text:
        if 'A' <= char <= 'Z':
            decrypted_char = chr(((ord(char) - ord('A') - distance) % 26) + ord('A'))
        else:
            decrypted_char = char
        decrypted_text += decrypted_char
    return decrypted_text

def solve():
    text = input()
    letter_counts = {}
    for char in text:
        if 'A' <= char <= 'Z':
            letter_counts[char] = letter_counts.get(char, 0) + 1
    
    if not letter_counts:
        print("0", text)
        return

    max_count = 0
    most_frequent_letters = []
    for letter, count in letter_counts.items():
        if count > max_count:
            max_count = count
            most_frequent_letters = [letter]
        elif count == max_count:
            most_frequent_letters.append(letter)

    possible_distances = []
    for letter in most_frequent_letters:
        distance = (ord(letter) - ord('E')) % 26
        possible_distances.append(distance)

    if len(possible_distances) > 1:
        print("NOT POSSIBLE")
    elif len(possible_distances) == 1:
        distance = possible_distances[0]
        decrypted_text = decrypt(text, distance)
        print(distance, decrypted_text)
    else:
        print("0", text)

c = int(input())
for _ in range(c):
    solve()