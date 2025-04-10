from collections import deque, Counter

def play_game(n, hands):
    players = [deque(sorted(h)) for h in hands]
    discarded = [False] * n
    card_count = [Counter(h) for h in hands]

    for i in range(n):
        if players[i][0] == players[i][1]:
            discarded[i] = True
            players[i].clear()

    turns, draw_count = 0, 0
    cur = 0

    while sum(len(p) for p in players) > 0:
        while not players[cur]:
            cur = (cur + 1) % n

        next_player = (cur + 1) % n
        while not players[next_player]:
            next_player = (next_player + 1) % n

        card = players[cur].popleft()
        players[next_player].append(card)
        players[next_player] = deque(sorted(players[next_player]))
        draw_count += 1

        if len(players[next_player]) >= 2:
            temp = list(players[next_player])
            count = Counter(temp)
            discard_cards = [c for c, cnt in count.items() if cnt == 2]
            if discard_cards:
                players[next_player] = deque(c for c in temp if c not in discard_cards)

        cur = next_player
        turns += 1

    return draw_count

while True:
    n = int(input())
    if n == 0:
        break

    hands = []
    for _ in range(n):
        hands.append(list(map(int, input().split())))

    print(play_game(n, hands))
