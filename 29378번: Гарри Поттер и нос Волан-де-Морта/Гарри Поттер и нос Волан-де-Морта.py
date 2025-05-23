import sys

def count_nose_positions(n, m, grid):
    count = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.':
                if j + 1 < m and grid[i][j + 1] == '.':
                    count += 1
                if i + 1 < n and grid[i + 1][j] == '.':
                    count += 1
    return count

def main():
    input = sys.stdin.read
    data = input().split()
    n, m = map(int, data[:2])
    grid = data[2:]

    if len(grid) != n:
        grid = []
        idx = 2

        for _ in range(n):
            grid.append(data[idx])
            idx += 1
    result = count_nose_positions(n, m, grid)
    print(result)

if __name__ == '__main__':
    main()