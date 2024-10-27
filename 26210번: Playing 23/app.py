#=====================================================================
#   26210번:    Playing 23                   
#   @date:   2024-10-27              
#   @link:   https://www.acmicpc.net/problem/26210  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

import sys;

input = sys.stdin.read

def card_point(value):
    if 1 <= value <= 10:
        return value
    elif 11 <= value <= 13:
        return 10
    else:
        return 0
    
def main():
    from collections import defaultdict

    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1

    john_initial = [int(data[idx]), int(data[idx + 1])]
    idx += 2
    mary_initial = [int(data[idx]), int(data[idx + 1])]
    idx += 2

    common_cards = []

    for _ in range(N):
        common_cards.append(int(data[idx]))
        idx += 1

    deck_counts = defaultdict(int)
    for card in range(1, 14):
        deck_counts[card] = 4

    for card in john_initial + mary_initial + common_cards:
        deck_counts[card] -= 1

    john_total = sum(card_point(card) for card in john_initial + common_cards)
    mary_total = sum(card_point(card) for card in mary_initial + common_cards)

    for card in range(1, 14):
        if deck_counts[card] <= 0:
            continue

        new_john_total = john_total + card_point(card)
        new_mary_total = mary_total + card_point(card)

        john_bust = new_john_total > 23
        mary_bust = new_mary_total > 23
        mary_wins = False

        if not mary_bust:
            if new_mary_total == 23:
                mary_wins = True
            elif john_bust:
                mary_wins = True

        if mary_wins:
            print(card)
            return
        
    print(-1)

main()

