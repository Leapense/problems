import sys

RANK_MAP = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14}
PLAYER_ORDER = ['N', 'E', 'S', 'W']
PLAYER_TO_IDX = {player: i for i, player in enumerate(PLAYER_ORDER)}
NUM_TRICKS = 13
BASE_TRICKS_FOR_SCORE = 6

def get_card_value(card_str):
    rank_char = card_str[0]
    suit = card_str[1]
    return RANK_MAP[rank_char], suit

def solve_deal(lines):
    trump_suit = lines[0].strip()
    player_cards = {
        PLAYER_TO_IDX['N']: lines[1].strip().split(),
        PLAYER_TO_IDX['E']: lines[2].strip().split(),
        PLAYER_TO_IDX['S']: lines[3].strip().split(),
        PLAYER_TO_IDX['W']: lines[4].strip().split(),
    }

    ns_tricks_won = 0
    ew_tricks_won = 0

    current_leader_idx = PLAYER_TO_IDX['N']

    for i in range(NUM_TRICKS):
        play_order = [(current_leader_idx + j) % 4 for j in range(4)]
        cards_in_trick = []
        for player_idx in play_order:
            card = player_cards[player_idx][i]
            cards_in_trick.append((player_idx, card))

        leader_card = cards_in_trick[0][1]
        led_suit = get_card_value(leader_card)[1]

        winning_player_idx = -1
        highest_trump_rank = -1
        highest_led_suit_rank = -1

        for player_idx, card_str in cards_in_trick:
            rank, suit = get_card_value(card_str)

            if suit == trump_suit:
                if rank > highest_trump_rank:
                    highest_trump_rank = rank
                    winning_player_idx = player_idx
            elif suit == led_suit:
                if rank > highest_led_suit_rank:
                    highest_led_suit_rank = rank
                    if highest_trump_rank == -1:
                        winning_player_idx = player_idx

        if winning_player_idx % 2 == 0:
            ns_tricks_won += 1
        else:
            ew_tricks_won += 1

        current_leader_idx = winning_player_idx

    if ns_tricks_won > ew_tricks_won:
        score = ns_tricks_won - BASE_TRICKS_FOR_SCORE
        print(f"NS {score}")
    else:
        score = ew_tricks_won - BASE_TRICKS_FOR_SCORE
        print(f"EW {score}")

def main():
    lines = []
    for line in sys.stdin:
        line = line.strip()
        if line == '#':
            break
        lines.append(line)
        if len(lines) == 5:
            solve_deal(lines)
            lines = []

if __name__ == "__main__":
    main()