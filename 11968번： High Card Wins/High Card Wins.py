import sys
import bisect

def main():
    input = sys.stdin.read
    data = list(map(int, input().split()))
    N = data[0]
    elsie_cards = data[1:]
    total_cards = set(range(1, 2 * N + 1))
    bessie_cards = sorted(list(total_cards - set(elsie_cards)))
    score = 0

    for card in elsie_cards:
        pos = bisect.bisect_right(bessie_cards, card)
        if pos < len(bessie_cards):
            score += 1
            bessie_cards.pop(pos)
        else:
            bessie_cards.pop(0)
    
    print(score)

if __name__ == "__main__":
    main()