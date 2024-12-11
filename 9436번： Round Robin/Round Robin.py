def round_robin_game():
    import sys
    input = sys.stdin.read
    results = []

    for line in input().splitlines():
        if line.strip() == "0":
            break

        # Parse input
        N, T = map(int, line.split())

        players = list(range(N))  # List of players
        counts = [0] * N  # Turn counts for each player
        current_index = 0

        while len(players) > 1:  # Ensure at least two players remain
            # Simulate T turns
            for _ in range(T):
                counts[players[current_index]] += 1
                current_index = (current_index + 1) % len(players)

            # Eliminate the player who took the last turn
            last_player_index = (current_index - 1) % len(players)
            last_player = players[last_player_index]
            players.pop(last_player_index)

            # Adjust current_index after elimination
            if last_player_index < len(players):
                current_index = last_player_index
            else:
                current_index = 0

            # Check if the game ends
            remaining_counts = [counts[player] for player in players]
            if all(c == remaining_counts[0] for c in remaining_counts):
                results.append(f"{len(players)} {remaining_counts[0]}")
                break

    print("\n".join(results))

# Run the function
round_robin_game()