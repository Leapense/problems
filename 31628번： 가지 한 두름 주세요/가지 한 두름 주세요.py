grid = [input().split() for _ in range(10)]

def check_rows(grid):
    for row in grid:
        if all(color == row[0] for color in row):
            return True
    return False

def check_cols(grid):
    for col in range(10):
        if all(grid[row][col] == grid[0][col] for row in range(10)):
            return True
    return False

if check_rows(grid) or check_cols(grid):
    print(1)
else:
    print(0)