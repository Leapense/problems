from functools import cmp_to_key

def largest_number_cmp(a, b):
    if a + b > b + a:
        return -1
    else:
        return 1
    
def max_card(c1, c2, c3, c4):
    cards = [str(c1), str(c2), str(c3), str(c4)]

    sorted_cards = sorted(cards, key=cmp_to_key(largest_number_cmp))

    return ''.join(sorted_cards)

c1, c2, c3, c4 = map(int, input().split())
print(max_card(c1, c2, c3, c4) + '\n')