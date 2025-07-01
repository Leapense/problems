from itertools import combinations
from sys import stdin, stdout

CATEGORY_COUNT = 9

def is_flush(suits):
    return len(set(suits)) == 1

def is_straight(ranks):
    uniq = sorted(set(ranks))
    if len(uniq) != 5:
        return False
    base = uniq[0]
    return all(uniq[i] == base + i for i in range(5))

def classify(hand):
    ranks = [r for r, _ in hand]
    suits = [s for _, s in hand]
    freq = {}
    for r in ranks:
        freq[r] = freq.get(r, 0) + 1
    counts = sorted(freq.values(), reverse=True)
    if is_flush(suits) and is_straight(ranks):
        return 0
    if counts[0] == 4:
        return 1
    if counts[0] == 3 and counts[1] == 2:
        return 2
    if is_flush(suits):
        return 3
    if is_straight(ranks):
        return 4
    if counts[0] == 3:
        return 5
    if counts[0] == 2 and counts[1] == 2:
        return 6
    if counts[0] == 2:
        return 7
    return 8

def main():
    A, B = map(int, stdin.readline().split())
    a1, b1, a2, b2 = map(int, stdin.readline().split())
    full_deck = [(r, s) for r in range(A) for s in range(B)]
    given = {(a1, b1), (a2, b2)}
    remaining = [card for card in full_deck if card not in given]
    results = [0] * CATEGORY_COUNT
    for trio in combinations(remaining, 3):
        hand = [*given, *trio]
        idx = classify(hand)
        results[idx] += 1
    stdout.write(' '.join(map(str, results)) + '\n')

if __name__ == '__main__':
    main()