#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <array>

struct Player {
    int id;
    int card_count = 0;
    int top_card = 0;
};

void solve_game() {
    int n, j;
    if (!(std::cin >> n >> j) || (n == 0 && j == 0)) {
        exit(0);
    }

    std::vector<int> deck(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> deck[i];
    }

    std::vector<Player> players(j);
    for (int i = 0; i < j; ++i) {
        players[i].id = i + 1;
    }

    std::array<bool, 14> discard_area{};
    int current_card_idx = 0;
    int current_player_idx = 0;

    while (current_card_idx < n) {
        bool turn_continues = true;
        while (turn_continues && current_card_idx < n) {
            int card_of_the_turn = deck[current_card_idx++];
            Player& current_player = players[current_player_idx];

            if (discard_area[card_of_the_turn]) {
                discard_area[card_of_the_turn] = false;
                current_player.card_count += 2;
                current_player.top_card = card_of_the_turn;
            } else {
                bool stole = false;
                for (auto& other_player : players) {
                    if (other_player.id != current_player.id && other_player.top_card == card_of_the_turn) {
                        current_player.card_count += other_player.card_count + 1;
                        current_player.top_card = card_of_the_turn;
                        other_player.card_count = 0;
                        other_player.top_card = 0;
                        stole = true;
                        break;
                    }
                }

                if (stole) {

                } else if (current_player.top_card == card_of_the_turn) {
                    current_player.card_count++;
                    current_player.top_card = card_of_the_turn;
                } else {
                    discard_area[card_of_the_turn] = true;
                    turn_continues = false;
                }
            }
        }

        current_player_idx = (current_player_idx + 1) % j;
    }

    int max_cards = 0;
    for (const auto& player : players) {
        max_cards = std::max(max_cards, player.card_count);
    }

    std::cout << max_cards;
    for (const auto& player : players) {
        if (player.card_count == max_cards) {
            std::cout << " " << player.id;
        }
    }

    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    while (true) {
        solve_game();
    }

    return 0;
}