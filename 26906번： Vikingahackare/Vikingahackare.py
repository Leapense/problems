def translate_runestone(T, mappings, encoded_string):
    # Create the dictionary for the binary to character mapping
    translation_dict = {}
    for char, binary in mappings:
        translation_dict[binary] = char
    
    # Length of each binary segment
    segment_length = 4
    # Number of segments
    num_segments = len(encoded_string) // segment_length
    
    # Translate the encoded string
    translated_string = []
    for i in range(num_segments):
        segment = encoded_string[i * segment_length:(i + 1) * segment_length]
        if segment in translation_dict:
            translated_string.append(translation_dict[segment])
        else:
            translated_string.append('?')
    
    return ''.join(translated_string)

# Read input
T = int(input().strip())
mappings = [input().strip().split() for _ in range(T)]
encoded_string = input().strip()

# Translate and print the result
result = translate_runestone(T, mappings, encoded_string)
print(result)