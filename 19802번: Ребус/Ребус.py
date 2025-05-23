def solve_riddle(riddle):
    # Split the input string into segments using space as a delimiter
    segments = riddle.split()
    
    # This will store the final result after processing all words
    result = []
    
    # Process each segment individually
    for segment in segments:
        # Initialize apostrophe counts
        left_count = 0
        right_count = 0
        
        # Count left apostrophes (from the start until the first letter)
        while left_count < len(segment) and segment[left_count] == "'":
            left_count += 1
        
        # Count right apostrophes (from the end until the first letter from the back)
        while right_count < len(segment) and segment[-(right_count + 1)] == "'":
            right_count += 1
        
        # Extract the word without the apostrophes
        word = segment[left_count:len(segment) - right_count]
        
        # Trim the word by the number of apostrophes from left and right
        trimmed_word = word[max(0, left_count):len(word) - max(0, right_count)]
        
        # Append the processed word to the result list
        result.append(trimmed_word)
    
    # Join all the processed words into a single string
    return ''.join(result)


def main():
    rebus = input()
    print(solve_riddle(rebus))

main()