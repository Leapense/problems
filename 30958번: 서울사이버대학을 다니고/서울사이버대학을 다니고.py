def most_frequent_letter_count(N, song):
    letter_count = {}

    for char in song:
        if char.isalpha():
            if char in letter_count:
                letter_count[char] += 1
            else:
                letter_count[char] = 1

    max_count = max(letter_count.values())
    print(max_count)

N = int(input())
song = input().strip()
most_frequent_letter_count(N, song)