def main():
    import sys
    tokens = sys.stdin.read().split()
    idx = 0

    while True:
        N = int(tokens[idx])
        M = int(tokens[idx + 1])
        S = int(tokens[idx + 2])
        idx += 3

        if N == 0 and M == 0 and S == 0:
            break

        grid = []
        for _ in range(N):
            line = tokens[idx]
            grid.append(list(line))
            idx += 1

        instructions = tokens[idx]
        idx += 1

        start_dir_map = {'N':0, 'S':2, 'L':1, 'O':3}
        start_pos = None
        direction = 0
        for r in range(N):
            for c in range(M):
                cell = grid[r][c]
                if cell in start_dir_map:
                    start_pos = (r, c)
                    direction = start_dir_map[cell]
                    break
            if start_pos:
                break

        figurines = set()
        for r in range(N):
            for c in range(M):
                if grid[r][c] == '*':
                    figurines.add((r, c))
        row, col = start_pos
        collected = 0
        directions = [(-1,0), (0,1), (1,0), (0,-1)]

        for instr in instructions:
            if instr == 'D':
                direction = (direction + 1) % 4
            elif instr == 'E':
                direction = (direction - 1) % 4
            elif instr == 'F':
                dr, dc = directions[direction]
                new_row = row + dr
                new_col = col + dc
                if 0 <= new_row < N and 0 <= new_col < M:
                    if grid[new_row][new_col] != '#':
                        row, col = new_row, new_col
                        if (row, col) in figurines:
                            collected += 1
                            figurines.remove((row, col))
        print(collected)

if __name__ == '__main__':
    main()