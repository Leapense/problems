def finger_game(a, b):
    """
    Determine the winner of the finger game.

    Args:
        a (int): The number of fingers Junsung has.
        b (int): The number of fingers Ikjun has.

    Returns:
        str: '>' if Junsung wins, '<' if Ikjun wins, '=' if it's a tie.
    """

    # Define the winning conditions for Junsung
    if (a == 0 and b == 2) or (a == 2 and b == 5) or (a == 5 and b == 0):
        return '>'
    # Define the winning conditions for Ikjun
    elif (b == 0 and a == 2) or (b == 2 and a == 5) or (b == 5 and a == 0):
        return '<'
    # If one player has a valid number of fingers and the other doesn't, the player with a valid number of fingers wins
    elif a in [0, 2, 5] and b not in [0, 2, 5]:
        return '>'
    elif b in [0, 2, 5] and a not in [0, 2, 5]:
        return '<'
    # If both players have the same number of fingers, or both have invalid numbers of fingers, it's a tie
    else:
        return '='

# Get the number of fingers from the input
a, b = map(int, input().split())

# Print the result of the game
print(finger_game(a, b))