def solve():
    import sys
    input = sys.stdin.read
    data = input().split('\n')
    
    # Read number of players
    n = int(data[0].strip())
    
    # Read player names and initialize score dictionary
    players = {}
    for i in range(1, n + 1):
        player_name = data[i].strip()
        players[player_name] = 0
    
    # Read number of records
    m_index = n + 1
    m = int(data[m_index].strip())
    
    # Initialize tracking of scores for current points scoring
    current_scores = [0, 0]
    
    # Process each score record
    for i in range(m_index + 1, m_index + 1 + m):
        record = data[i].strip()
        score_part, player_name = record.rsplit(' ', 1)
        a_i, b_i = map(int, score_part.split(':'))
        
        # Calculate points scored by player in this record
        points_scored = (a_i + b_i) - (current_scores[0] + current_scores[1])
        players[player_name] += points_scored
        
        # Update the current scoreboard
        current_scores = [a_i, b_i]
    
    # Find the player with the maximum points
    max_player = None
    max_points = -1
    for player, points in players.items():
        if points > max_points:
            max_points = points
            max_player = player
    
    # Output the result
    print(f"{max_player} {max_points}")

solve()