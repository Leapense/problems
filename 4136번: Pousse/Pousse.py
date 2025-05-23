import sys

def insert_marker(board, move, player, N):
    direction = move[0]
    index = int(move[1:]) - 1

    if direction == 'L':
        row = index
        insert_col = 0

        while insert_col < N and board[row][insert_col] != '.':
            insert_col += 1
        if insert_col < N:
            board[row][insert_col] = player
        else:
            for col in range(N - 1, 0, -1):
                board[row][col] = board[row][col - 1]
            board[row][0] = player

    elif direction == 'R':
        row = index
        insert_col = N - 1
        while insert_col >= 0 and board[row][insert_col] != '.':
            insert_col -= 1
        if insert_col >= 0:
            board[row][insert_col] = player
        else:
            for col in range(0, N - 1):
                board[row][col] = board[row][col + 1]
            board[row][N - 1] = player
    
    elif direction == 'T':
        col = index
        insert_row = 0
        while insert_row < N and board[insert_row][col] != '.':
            insert_row += 1
        if insert_row < N:
            board[insert_row][col] = player
        else:
            for row in range(N - 1, 0, -1):
                board[row][col] = board[row - 1][col]
            board[0][col] = player

    elif direction == 'B':
        col = index
        insert_row = N - 1
        while insert_row >= 0 and board[insert_row][col] != '.':
            insert_row -= 1
        if insert_row >= 0:
            board[insert_row][col] = player
        else:
            for row in range(0, N - 1):
                board[row][col] = board[row + 1][col]
            board[N - 1][col] = player

def count_straights(board, N):
    x_straights = 0
    o_straights = 0

    for row in range(N):
        first = board[row][0]
        if first == '.':
            continue
        straight = True
        for col in range(1, N):
            if board[row][col] != first:
                straight = False
                break
        if straight:
            if first == 'X':
                x_straights += 1
            elif first == 'O':
                o_straights += 1

    for col in range(N):
        first = board[0][col]
        if first == '.':
            continue
        straight = True
        for row in range(1, N):
            if board[row][col] != first:
                straight = False
                break
        if straight:
            if first == 'X':
                x_straights += 1
            elif first == 'O':
                o_straights += 1

    return x_straights, o_straights

def main():
    input_lines = sys.stdin.read().splitlines()
    if not input_lines:
        return

    N = int(input_lines[0].strip())
    board = [['.' for _ in range(N)] for _ in range(N)]
    moves = input_lines[1:]
    current_player = 'X'
    winner_declared = False
    
    for move in moves:
        move = move.strip()
        if move == 'QUIT':
            if not winner_declared:
                print("TIE GAME")
            break
        insert_marker(board, move, current_player, N)
        x_straights, o_straights = count_straights(board, N)

        if x_straights > o_straights:
            print("X WINS")
            winner_declared = True
            break
        elif o_straights > x_straights:
            print("O WINS")
            winner_declared = True
            break
        current_player = 'O' if current_player == 'X' else 'X'

    if not winner_declared and (not moves or moves[-1].strip() != "QUIT"):
        print("TIE GAME")

if __name__ == '__main__':
    main()