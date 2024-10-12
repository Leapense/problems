def check_bingo(board, drawn_numbers):
    for i in range(5):
        if all(board[i][j] in drawn_numbers for j in range(5)):
            return True
        if all(board[j][i] in drawn_numbers for j in range(5)):
            return True
    if all(board[i][i] in drawn_numbers for i in range(5)):
        return True
    if all(board[i][4-i] in drawn_numbers for i in range(5)):
        return True
    return False

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    idx = 0
    n = int(data[idx])
    idx += 1

    players = []
    boards = []

    for _ in range(n):
        name = data[idx]
        idx += 1
        board = [list(map(int, data[idx + i].split())) for i in range(5)]
        idx += 5
        players.append(name)
        boards.append(board)

    m = int(data[idx])
    idx += 1
    drawn_numbers = list(map(int, data[idx].split()))

    winners = []
    for i in range(n):
        if check_bingo(boards[i], drawn_numbers):
            winners.append(players[i])

    print(len(winners))
    for winner in winners:
        print(winner)

if __name__ == "__main__":
    main()