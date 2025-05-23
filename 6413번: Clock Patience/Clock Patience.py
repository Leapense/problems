def play_clock_patience(deck):
    piles = [[] for _ in range(13)]
    ranks = "A23456789TJQK"
    rank_to_index = {ranks[i]: i for i in range(13)}

    # 카드 배치
    for i in range(52):
        piles[i % 13].append(deck[51 - i])

    exposed_count = 0
    current_pile_index = 12  # 13번째 더미(킹 더미)의 인덱스
    last_card = ''

    while piles[current_pile_index]:
        current_card = piles[current_pile_index].pop()
        exposed_count += 1
        last_card = current_card
        current_pile_index = rank_to_index[current_card[0]]

    return f"{exposed_count:02},{last_card}"

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    
    decks = []
    current_deck = []

    for line in data:
        if line == '#':
            break
        if line:
            current_deck.extend(line.split())
        if len(current_deck) == 52:
            decks.append(current_deck)
            current_deck = []

    results = [play_clock_patience(deck) for deck in decks]
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
