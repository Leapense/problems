def count_border_length(w, h, grid):
    length = 0
    for i in range(h):
        for j in range(w):
            if j+1 < w and grid[i][j] != grid[i][j + 1]:
                length += 1
            if i+1 < h and grid[i][j] != grid[i + 1][j]:
                length += 1
    return length

import sys
input = sys.stdin.read
data = input().splitlines()

w, h = map(int, data[0].split())
grid = data[1:h+1]

result = count_border_length(w, h, grid)
print(result)