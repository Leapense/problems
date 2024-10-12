def find_safe_move(board):
    def is_winning_move(board, player, row, col):
        board[row][col] = player
        win = check_win(board, player)
        board[row][col] = '*'
        return win

    def check_win(board, player):
        for i in range(5):
            for j in range(2):
                if all(board[i][j + k] == player for k in range(4)) or all(board[j + k][i] == player for k in range(4)):
                    return True
        for i in range(2):
            for j in range(2):
                if all(board[i + k][j + k] == player for k in range(4)) or all(board[i + 3 - k][j + k] == player for k in range(4)):
                    return True
        return False

    for i in range(5):
        for j in range(5):
            if board[i][j] == '*':
                if not is_winning_move(board, 'O', i, j) and not is_winning_move(board, 'X', i, j):
                    return i * 5 + j + 1

import sys
input = sys.stdin.read

data = input().splitlines()
boards = []
board = []
for line in data:
    if line == "Finished":
        if board:
            boards.append(board)
        break
    elif line == "":
        if board:
            boards.append(board)
        board = []
    else:
        board.append(line.split())

for board in boards:
    print(find_safe_move(board))