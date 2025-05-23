def calculate_scores(n, events):
    pineapple_score = 0
    blueberry_score = 0
    
    # Store the last spray time for each player
    last_spray_time = {}

    for event in events:
        t, a, b = event
        team = 'pineapple' if 1 <= a <= 4 else 'blueberry'
        opponent_team = 'blueberry' if team == 'pineapple' else 'pineapple'
        
        # Initial 100 points for spraying opponent
        if team == 'pineapple':
            pineapple_score += 100
        else:
            blueberry_score += 100
        
        # Check for double-spray
        if a in last_spray_time and t - last_spray_time[a] <= 10:
            if team == 'pineapple':
                pineapple_score += 50
            else:
                blueberry_score += 50
        
        # Update last spray time
        last_spray_time[a] = t

    return pineapple_score, blueberry_score

n = int(input())
events = [list(map(int, input().split())) for _ in range(n)]
pineapple_score, blueberry_score = calculate_scores(n, events)
print(pineapple_score, blueberry_score)