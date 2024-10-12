def yoda_speech_transform(speech):
    # Split input into sentences by periods
    sentences = speech.split('.')
    # Remove empty strings which might appear due to trailing dots
    sentences = [s.strip() for s in sentences if s.strip()]
    
    transformed_sentences = []
    
    for sentence in sentences:
        # Split sentence into words, reverse the list of words
        words = sentence.split()
        words.reverse()
        
        # Join the reversed words and append a dot to end the sentence
        transformed_sentence = ' '.join(words) + '.'
        transformed_sentences.append(transformed_sentence)
    
    # Join all transformed sentences into one string
    yoda_speech = ' '.join(transformed_sentences)
    return yoda_speech

input_speech = input().strip()
print(yoda_speech_transform(input_speech))