def get_board(config):
    if config == 'a':
        return [list("........"),
                list("........"),
                list("........"),
                list("...WB..."),
                list("...BW..."),
                list("........"),
                list("........"),
                list("........")]
    elif config == 'b':
        return [list("........"),
                list("........"),
                list("..BBWW.."),
                list("..BBWW.."),
                list("..WWBB.."),
                list("..WWBB.."),
                list("........"),
                list("........")]
    elif config == 'c':
        return [list("........"),
                list("..BWBWW."),
                list("WWWBWBWB"),
                list("BWBWBWBW"),
                list("WBWBWBWB"),
                list("..BWB..."),
                list("........"),
                list("........")]

def in_bounds(r, c):
    return 0 <= r < 8 and 0 <= c < 8

def simulate(board, moves):
    dirs = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)]
    player = 'B'
    for (r, c) in moves:
        r -= 1
        c -= 1
        board[r][c] = player
        for dr, dc in dirs:
            nr, nc = r+dr, c+dc
            flip = []
            while in_bounds(nr, nc) and board[nr][nc] != '.' and board[nr][nc] != player:
                flip.append((nr, nc))
                nr += dr
                nc += dc
            if in_bounds(nr, nc) and board[nr][nc] == player and flip:
                for fr, fc in flip:
                    board[fr][fc] = player
        player = 'W' if player == 'B' else 'B'
    return board

def count_discs(board):
    b = sum(row.count('B') for row in board)
    w = sum(row.count('W') for row in board)
    return b, w

import sys
data = sys.stdin.read().split()
if not data:
    exit()
config = data[0]
n = int(data[1])
moves = []
for i in range(n):
    moves.append((int(data[2+2*i]), int(data[3+2*i])))
board = get_board(config)
board = simulate(board, moves)
b, w = count_discs(board)
print(b, w)
