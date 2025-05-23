def find_combinations(cards, target, start, current, result):
    if target == 0:
        result.append(current[:])
        return
    if target < 0:
        return
    for i in range(start, len(cards)):
        current.append(cards[i])
        find_combinations(cards, target - cards[i], i + 1, current, result)
        current.pop()

def main():
    import sys
    input_data = sys.stdin.read().strip().split()
    t = int(input_data[0])
    index = 1
    outputs = []

    for _ in range(t):
        target = int(input_data[index])
        n = int(input_data[index+1])
        cards = list(map(int, input_data[index+2:index+2+n]))
        index += 2+n
        result = []
        find_combinations(cards, target, 0, [], result)
        if not result:
            outputs.append("No move found.")
        else:
            best_move = max(result)
            outputs.append("The best move is: " + " ".join(map(str, best_move)))
    sys.stdout.write("\n".join(outputs))

if __name__ == "__main__":
    main()