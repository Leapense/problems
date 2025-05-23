def count_names(N, text):
    import re
    
    # Split the text into sentences using punctuation delimiters while keeping them
    sentences = re.split('([.?!])', text)
    # Merge delimiters back to their respective sentences
    sentences = [sentences[i] + sentences[i+1] for i in range(0, len(sentences)-1, 2)]
    
    # This will store results
    results = []
    
    # Process each sentence
    for sentence in sentences:
        words = sentence.split()
        name_count = 0
        
        for word in words:
            # Check if the word is potentially a name
            if word[0].isupper():  # Starts with uppercase
                # Remove punctuation at the end if exists and it's the last word in the sentence
                if word == words[-1] and word[-1] in '.?!':
                    word = word[:-1]
                
                # Check rest of the characters
                if all(c.islower() for c in word[1:]):  # all following characters are lowercase
                    name_count += 1
        
        results.append(name_count)
    
    return results

N = int(input())
text = input()
results = count_names(N, text)

for result in results:
    print(result)