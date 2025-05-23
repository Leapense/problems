def translate_word(word):
    # Dictionary mapping the provided English letters to the Russian pronunciations
    translation_map = {
        'A': 'a', 'B': 'v', 'E': 'ye', 'K': 'k', 'M': 'm', 'H': 'n', 'O': 'o',
        'P': 'r', 'C': 's', 'T': 't', 'Y': 'u', 'X': 'h'
    }
    
    # Translate each letter in the word using the map
    translated = ''.join(translation_map[letter] for letter in word)
    
    # Return the translated word
    return translated

# Read the input
input_word = input().strip()
# Output the translated word
print(translate_word(input_word))