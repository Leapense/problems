#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    int card_count;
    int top_card;
} Player;

void solve() {
    int n, j;
    if (scanf("%d %d", &n, &j) != 2 || (n == 0 && j == 0)) {
        exit(0);
    }

    int deck[10001];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &deck[i]);
    }

    Player players[21];
    bool discard_area[24];

    memset(players, 0, sizeof(players));
    memset(discard_area, 0, sizeof(discard_area));

    for (int i = 0; i < j; ++i) {
        players[i].id = i + 1;
    }

    int current_card_idx = 0;
    int current_player_idx = 0;

    while (current_card_idx < n) {
        bool turn_continues = true;
        while (turn_continues && current_card_idx < n) {
            int card_of_the_turn = deck[current_card_idx++];

            if (discard_area[card_of_the_turn]) {
                discard_area[card_of_the_turn] = false;
                players[current_player_idx].card_count += 2;
                players[current_player_idx].top_card = card_of_the_turn;
            } else {
                bool stole = false;
                for (int i = 0; i < j; ++i) {
                    if (i != current_player_idx && players[i].top_card == card_of_the_turn) {
                        players[current_player_idx].card_count += players[i].card_count + 1;
                        players[current_player_idx].top_card = card_of_the_turn;
                        players[i].card_count = 0;
                        players[i].top_card = 0;
                        stole = true;
                        break;
                    }
                }

                if (stole) {
                    
                } else if (players[current_player_idx].top_card == card_of_the_turn) {
                    players[current_player_idx].card_count++;
                    players[current_player_idx].top_card = card_of_the_turn;
                } else {
                    discard_area[card_of_the_turn] = true;
                    turn_continues = false;
                }
            }
        }

        current_player_idx = (current_player_idx + 1) % j;
    }

    int max_cards = 0;
    for (int i = 0; i < j; ++i) {
        if (players[i].card_count > max_cards) {
            max_cards = players[i].card_count;
        }
    }

    printf("%d", max_cards);
    for (int i = 0; i < j; ++i) {
        if (players[i].card_count == max_cards) {
            printf(" %d", players[i].id);
        }
    }

    printf("\n");
}

int main() {
    while (1) {
        solve();
    }

    return 0;
}