def parse_jfen(jfen, W):
    rows = jfen.split('/')
    board = []

    for row in rows:
        parsed_row = []
        i = 0
        while i < len(row):
            if row[i].isdigit():
                num = int(row[i])
                parsed_row.extend(['.'] * num)
            elif row[i] == 'b':
                parsed_row.append('b')
            i += 1
        board.append(parsed_row)
    return board

def board_to_jfen(board):
    jfen = []
    for row in board:
        compressed_row = ""
        empty_count = 0
        for cell in row:
            if cell == '.':
                empty_count += 1
            else:
                if empty_count > 0:
                    compressed_row += str(empty_count)
                    empty_count = 0
                compressed_row += 'b'
        if empty_count > 0:
            compressed_row += str(empty_count)
        jfen.append(compressed_row)
    return '/'.join(jfen)

def process_command(board, a, b, c, d):
    board[a - 1][b - 1] = '.'
    board[c - 1][d - 1] = 'b'
    return board

def main():
    results = []
    while True:
        s = input().strip()
        if s == '#':
            break
        a, b, c, d = map(int, input().strip().split())
        W = max(len(row) for row in s.split('/'))
        board = parse_jfen(s, W)
        board = process_command(board, a, b, c, d)
        results.append(board_to_jfen(board))
    for result in results:
        print(result)

if __name__ == "__main__":
    main()