import sys

def find_winner(board):
    N = 19
    directions = [
        (0, 1),
        (1, 0),
        (1, 1),
        (-1, 1)
    ]
    
    for r in range(N):
        for c in range(N):
            col = board[r][c]
            if col == 0:
                continue
            for dr, dc in directions:
                pr, pc = r - dr, c - dc
                if 0 <= pr < N and 0 <= pc < N and board[pr][pc] == col:
                    continue
                    
                count = 1
                nr, nc = r + dr, c + dc
                while 0 <= nr < N and 0 <= nc < N and board[nr][nc] == col:
                    count += 1
                    if count > 5:
                        break
                    nr += dr
                    nc += dc
                
                if count == 5:
                    if not (0 <= nr < N and 0 <= nc < N and board[nr][nc] == col):
                        return col, r + 1, c + 1
                    
    return 0, None, None

def main():
    data = sys.stdin.read().strip().split()
    board = [list(map(int, data[i*19:(i+1)*19])) for i in range(19)]
    winner, row, col = find_winner(board)
    if winner == 0:
        print(0)
    else:
        print(winner)
        print(row, col)
        
if __name__ == "__main__":
    main()