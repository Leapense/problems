def main():
    import sys
    R, S = map(int, sys.stdin.readline().split())
    grid = [list(sys.stdin.readline().strip()) for _ in range(R)]
    min_dist = R
    for col in range(S):
        meteor_bottom = -1
        ground_top = R

        for row in range(R):
            if grid[row][col] == 'X':
                meteor_bottom = max(meteor_bottom, row)
            elif grid[row][col] == '#' and ground_top == R:
                ground_top = row

        if meteor_bottom != -1:
            dist = ground_top - meteor_bottom - 1
            min_dist = min(min_dist, dist)

    result = [['.' for _ in range(S)] for _ in range(R)]

    for row in range(R):
        for col in range(S):
            if grid[row][col] == '#':
                result[row][col] = '#'

    for row in range(R):
        for col in range(S):
            if grid[row][col] == 'X':
                new_row = row + min_dist
                result[new_row][col] = 'X'

    for row in result:
        print(''.join(row))

if __name__ == '__main__':
    main()