def solve():
    board = [list(map(int, input().split())) for _ in range(5)]
    r, c = map(int, input().split())
    directions = [(-1,0),(1,0),(0,-1),(0,1)]
    result = [0]

    def dfs(x, y, moves, apples):
        if apples >= 2:
            result[0] = 1
            return
        if moves == 3:
            return
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < 5 and 0 <= ny < 5 and board[nx][ny] != -1:
                original = board[nx][ny]
                board[x][y] = -1
                new_apples = apples + 1 if original == 1 else apples
                dfs(nx, ny, moves + 1, new_apples)
                board[x][y] = 0
                board[nx][ny] = original
                if result[0] == 1:
                    return
                
    dfs(r, c, 0, 0)
    print(result[0])

if __name__ == "__main__":
    solve()