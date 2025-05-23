def can_select_three_cards(N, cards):
    card_set = set(cards)

    for card in card_set:
        if (card + 3) in card_set and (card + 6) in card_set:
            return "Yes"
    
    return "No"

N = int(input())
cards = list(map(int, input().split()))

result = can_select_three_cards(N, cards)

print(result)