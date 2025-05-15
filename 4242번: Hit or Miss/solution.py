from collections import deque

def hit_or_miss(num_players, deck):
    player_decks = [deque() for _ in range(num_players)]
    player_decks[0] = deque(deck)
    counters = [1] * num_players
    last_discarded = [None] * num_players
    waiting = [False] * num_players
    prev_states = set()
    passes = [[] for _ in range(num_players)]
    total_cards = sum(len(d) for d in player_decks)
    while True:
        state = []
        for d in player_decks:
            state.append(tuple(d))
        state_tuple = (tuple(state), tuple(counters), tuple(waiting))
        if state_tuple in prev_states:
            return "unwinnable"
        prev_states.add(state_tuple)
        for i in range(num_players):
            passes[i] = []

        for i in range(num_players):
            if not player_decks[i]:
                waiting[i] = True
                continue
            card = player_decks[i][0]
            if card == counters[i]:
                player_decks[i].popleft()
                if i == num_players - 1:
                    last_discarded[i] = card
                    total_cards -= 1
                else:
                    passes[i + 1].append(card)
                    last_discarded[i] = card
                counters[i] += 1
                if counters[i] > 13:
                    counters[i] = 1
                if not player_decks[i]:
                    waiting[i] = True
            else:
                c = player_decks[i].popleft()
                player_decks[i].append(c)
                counters[i] += 1
                if counters[i] > 13:
                    counters[i] = 1
        for i in range(1, num_players):
            for card in passes[i]:
                player_decks[i].append(card)
                waiting[i] = False
        if total_cards == 0:
            return " ".join(str(x) for x in last_discarded)
        
def process_input(input_lines):
    n = int(input_lines[0])
    res = []
    for case_num in range(1, n + 1):
        parts = list(map(int, input_lines[case_num].split()))
        num_players = parts[0]
        deck = parts[1:]
        result = hit_or_miss(num_players, deck)
        res.append(f"Case {case_num}: {result}")
    return res

def main():
    import sys
    input_lines = sys.stdin.read().splitlines()
    result = process_input(input_lines)
    for line in result:
        print(line)

if __name__ == "__main__":
    main()