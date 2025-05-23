def calculate_maximum_score(n, balls):
    # Ball values mapped to colors
    ball_values = {
        'red': 1,
        'yellow': 2,
        'green': 3,
        'brown': 4,
        'blue': 5,
        'pink': 6,
        'black': 7
    }
    
    # Count occurrences of each ball
    ball_count = {
        'red': 0,
        'yellow': 0,
        'green': 0,
        'brown': 0,
        'blue': 0,
        'pink': 0,
        'black': 0
    }
    
    # Fill the ball_count dictionary with the input data
    for ball in balls:
        ball_count[ball] += 1
    
    # Number of reds
    reds = ball_count['red']
    
    # Non-red balls sorted by their value (highest first)
    non_reds = sorted(('yellow', 'green', 'brown', 'blue', 'pink', 'black'), key=lambda x: ball_values[x], reverse=True)
    
    # Calculate the maximum possible score
    score = 0
    color_sequence = []  # to track the sequence of colored balls used after reds
    
    # Score with all reds and their following colors
    while reds > 0:
        # Pot a red
        score += ball_values['red']
        reds -= 1
        
        # Find the highest value non-red that is available to follow a red
        for color in non_reds:
            if ball_count[color] > 0:
                score += ball_values[color]
                color_sequence.append(color)
                break  # only one color can follow each red
    
    # Now all reds are potted, decrement counts of used non-reds
    for color in color_sequence:
        ball_count[color] -= 1
    
    # After all reds are potted, pot remaining non-reds in value order
    for color in non_reds:
        if ball_count[color] > 0:
            score += ball_values[color] * ball_count[color]
    
    return score

n = int(input())
balls = []
for i in range(n):
    balls.append(input())

print(calculate_maximum_score(n, balls))