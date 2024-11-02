def calculate_mean_word(words):
    max_length = max(len(word) for word in words)
    sum_ascii = [0] * max_length
    count_ascii = [0] * max_length

    for word in words:
        for i, char in enumerate(word):
            sum_ascii[i] += ord(char)
            count_ascii[i] += 1

    mean_word = []

    for i in range(max_length):
        if count_ascii[i] > 0:
            average_ascii = sum_ascii[i] // count_ascii[i]
            mean_word.append(chr(average_ascii))

    return ''.join(mean_word)

n = int(input().strip())
words = [input().strip() for _ in range(n)]

mean_word = calculate_mean_word(words)
print(mean_word)