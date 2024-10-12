def is_valid_board(board):
    # Count the number of knights
    knight_count = sum(row.count('k') for row in board)
    
    # Check if there are exactly nine knights
    if knight_count != 9:
        return False
    
    # Check if any knight can attack another
    for i in range(5):
        for j in range(5):
            if board[i][j] == 'k':
                # Check all possible moves for this knight
                for di, dj in [(1, 2), (2, 1), (1, -2), (2, -1), (-1, 2), (-2, 1), (-1, -2), (-2, -1)]:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < 5 and 0 <= nj < 5 and board[ni][nj] == 'k':
                        return False
    
    return True

# Read input and process each board
try:
    num_cases = int(input())
    for _ in range(num_cases):
        board = [input().strip() for _ in range(5)]
        print("valid" if is_valid_board(board) else "invalid")
        # Consume any remaining newline or EOFError
        try:
            input()
        except EOFError:
            pass
except EOFError:
    pass