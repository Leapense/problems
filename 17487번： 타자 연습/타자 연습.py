def count_keystrokes(sentence):
    left_hand = "qwertyasdfgzxcvb"
    right_hand = "uiophjklnm"
    left, right, other = 0, 0, 0

    for s in sentence:
        if s.isupper():
            other += 1
    
    for s in sentence.lower():
        if s in right_hand:
            right += 1
        elif s in left_hand:
            left += 1
        else:
            other += 1

    while other != 0:
        if left <= right:
            left += 1
        else:
            right += 1
        other -= 1

    return left, right

sentence = input().strip()
left_count, right_count = count_keystrokes(sentence)
print(left_count, right_count)