#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, P;
    std::cin >> N >> P;

    int W, L, G;
    std::cin >> W >> L >> G;

    std::unordered_map<std::string, char> player_outcomes;

    for (int i = 0; i < P; ++i) {
        std::string name, outcome;
        std::cin >> name >> outcome;
        player_outcomes[name] = outcome[0];
    }

    std::vector<std::string> game_players(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> game_players[i];
    }

    int score = 0;
    bool escaped = false;

    for (int i = 0; i < N; ++i) {
        std::string current_player = game_players[i];
        if (player_outcomes.find(current_player) != player_outcomes.end()) {
            if (player_outcomes[current_player] == 'W') {
                score += W;
            } else {
                score = std::max(0, score - L);
            }
        } else {
            score = std::max(0, score - L);
        }

        if (score >= G) {
            escaped = true;
            break;
        }
    }

    if (escaped) {
        std::cout << "I AM NOT IRONMAN!!";
    } else {
        std::cout << "I AM IRONMAN!!";
    }

    return 0;
}