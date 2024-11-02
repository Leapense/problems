def letterle_feedback(target, guesses):
    output = []
    
    for guess in guesses:
        if guess == target:
            output.append("WINNER")
            break
        
        feedback = [''] * 5
        target_counts = {}
        
        # First pass: Mark correct positions and count remaining letters in the target
        for i in range(5):
            if target[i] == guess[i]:
                feedback[i] = 'G'
            else:
                target_counts[target[i]] = target_counts.get(target[i], 0) + 1
        
        # Second pass: Mark incorrect positions with Y or X
        for i in range(5):
            if feedback[i] == '':
                guessed_letter = guess[i]
                if guessed_letter in target_counts and target_counts[guessed_letter] > 0:
                    feedback[i] = 'Y'
                    target_counts[guessed_letter] -= 1
                else:
                    feedback[i] = 'X'
        
        output.append(''.join(feedback))
    
    # If there is no WINNER and all guesses are exhausted, print LOSER on the last guess
    if len(output) == 7 and output[-1] != "WINNER":
        output[-1] = "LOSER"
    
    return output

# Reading the inputs and applying the function
import sys
input = sys.stdin.read
data = input().splitlines()

target_word = data[0]
guesses = data[1:]

results = letterle_feedback(target_word, guesses)
for result in results:
    print(result)