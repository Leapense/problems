def portmanteau(word1, word2):
    # Step 1: Process the first word
    first_letter = word1[0]
    first_part = first_letter
    
    # Find the first vowel in word1 from the second letter onwards
    v1 = None
    for char in word1[1:]:
        if char in 'aeiou':
            v1 = char
            break
        first_part += char
    
    # Step 2: Process the second word
    last_letter = word2[-1]
    second_part = last_letter
    
    # Find the first vowel in word2 while moving left
    v2 = None
    for char in reversed(word2[:-1]):  # Exclude the last letter
        if char in 'aeiou':
            v2 = char
            break
        second_part = char + second_part  # Prepend to second part
    
    # Step 3: Determine the merging vowel
    if v2 is not None:
        merging_vowel = v2
    elif v1 is not None:
        merging_vowel = v1
    else:
        merging_vowel = 'o'
    
    # Step 4: Combine and return the result
    combined_word = first_part + merging_vowel + second_part
    return combined_word

# Input reading
word1 = input().strip()
word2 = input().strip()

# Output the result
result = portmanteau(word1, word2)
print(result)
