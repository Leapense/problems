import sys
from collections import deque

def main():
    input_ = sys.stdin.readline
    n, m, r = map(int, input_().split())
    dir_char = input_().strip()
    board = [list(input_().rstrip()) for _ in range(n)]
    moves = input_().split()

    dirs = {'N': 0, 'E': 1, 'S': 2, 'W': 3}
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]

    d = dirs[dir_char]
    snake = deque()
    occupied = set()
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'W':
                snake.append((i, j))
                occupied.add((i, j))
                board[i][j] = '.'
                break
    
    for idx, cmd in enumerate(moves, start=1):
        if cmd == 'L':
            d = (d - 1) % 4
        elif cmd == 'P':
            d = (d + 1) % 4
        
        head_r, head_c = snake[0]
        nr, nc = head_r + dr[d], head_c + dc[d]

        if not (0 <= nr < n and 0 <= nc < m):
            print(idx)
            return
        
        if (nr, nc) in occupied:
            print(idx)
            return
        
        snake.appendleft((nr, nc))
        occupied.add((nr, nc))

        if board[nr][nc] == 'J':
            board[nr][nc] = '.'
        else:
            tail = snake.pop()
            occupied.remove(tail)

    print("OK")

if __name__ == '__main__':
    main()