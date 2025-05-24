import sys

def main():
    order = ['N', 'E', 'S', 'W']
    suit_order = {'C': 0, 'D': 1, 'S': 2, 'H': 3}
    rank_order = {'2': 0, '3': 1, '4': 2, '5': 3, '6': 4, '7': 5, '8': 6, '9': 7, 'T': 8, 'J': 9, 'Q': 10, 'K': 11, 'A': 12}
    players = ['S', 'W', 'N', 'E']
    names = {'S': 'South', 'W': 'West', 'N': 'North', 'E': 'East'}
    lines = sys.stdin.read().splitlines()
    idx = 0
    first = True

    while idx < len(lines):
        dealer = lines[idx].strip()
        if dealer == '#':
            break
        deck = lines[idx + 1].strip() + lines[idx + 2].strip()
        idx += 3
        hands = {p: [] for p in players}
        start = (order.index(dealer) + 1) % 4
        for i in range(52):
            card = deck[2*i:2*i+2]
            suit, rank = card[0], card[1]
            p = order[(start + i) % 4]
            hands[p].append((suit, rank))
        for p in players:
            hands[p].sort(key=lambda c : (suit_order[c[0]], rank_order[c[1]]))
        if not first:
            print()
        first = False
        for p in players:
            print(f"{names[p]} player:")
            border = '+' + '---+' * 13
            print(border)
            top = ''.join(f"|{r} {r}" for _, r in hands[p]) + '|'
            mid = ''.join(f"| {s} " for s, _ in hands[p]) + '|'
            print(top)
            print(mid)
            print(top)
            print(border)

if __name__ == '__main__':
    main()