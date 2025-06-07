import sys

def merge_line(line):
    non_zero = [value for value in line if value != 0]
    merged = []
    skip_next = False

    for i in range(len(non_zero)):
        if skip_next:
            skip_next = False
            continue

        current = non_zero[i]
        if (i + 1 < len(non_zero)) and (non_zero[i + 1] == current):
            merged_value = current * 2
            merged.append(merged_value)
            skip_next = True
        else:
            merged.append(current)

    merged.extend([0] * (len(line) - len(merged)))
    return merged

def transpose(grid):
    size = len(grid)
    return [list(row) for row in zip(*grid)]

def process_board(board, direction):
    n = len(board)
    if direction == 'left' or direction == 'right':
        new_board = []
        for row in board:
            line = row[:]
            if direction == 'right':
                line.reverse()
            merged = merge_line(line)
            if direction == 'right':
                merged.reverse()
            new_board.append(merged)
        return new_board
    
    transposed = transpose(board)
    if direction == 'up':
        moved = process_board(transposed, 'left')
    else:
        moved = process_board(transposed, 'right')

    return transpose(moved)

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1

    for case_num in range(1, t + 1):
        n = int(data[index])
        index += 1
        direction = data[index]
        index += 1

        board = []
        for _ in range(n):
            row = list(map(int, data[index:index + n]))
            index += n
            board.append(row)

        result = process_board(board, direction)
        print(f"Case #{case_num}:")
        for row in result:
            print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()