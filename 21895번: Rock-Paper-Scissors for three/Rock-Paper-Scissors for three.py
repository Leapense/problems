def determine_dasha_moves(n, robot1_moves, robot2_moves):
    # Output list to collect Dasha's moves
    dasha_moves = []
    
    for i in range(n):
        r1 = robot1_moves[i]
        r2 = robot2_moves[i]
        
        if r1 == r2:
            # If both robots have the same move, Dasha should choose the winning move
            if r1 == 'R':
                dasha_moves.append('P')  # Paper beats Rock
            elif r1 == 'P':
                dasha_moves.append('S')  # Scissors beats Paper
            elif r1 == 'S':
                dasha_moves.append('R')  # Rock beats Scissors
        else:
            # If robots have different moves, find the move that beats both
            if (r1 == 'R' and r2 == 'P') or (r1 == 'P' and r2 == 'R'):
                dasha_moves.append('P')  # Paper beats Rock
            elif (r1 == 'R' and r2 == 'S') or (r1 == 'S' and r2 == 'R'):
                dasha_moves.append('R')  # Rock beats Scissors
            elif (r1 == 'P' and r2 == 'S') or (r1 == 'S' and r2 == 'P'):
                dasha_moves.append('S')  # Scissors beats Paper
    
    return ''.join(dasha_moves)

n = int(input())
robot1_moves = input()
robot2_moves = input()
result = determine_dasha_moves(n, robot1_moves, robot2_moves)
print(result)