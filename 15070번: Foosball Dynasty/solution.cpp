#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <utility>

struct GameState {
    std::string white_offense;
    std::string white_defense;
    std::string black_offense;
    std::string black_defense;

    std::pair<std::string, std::string> white_team;
    std::pair<std::string, std::string> black_team;

    std::deque<std::string> queue;
};

void update_dynasty(int current_length, const std::pair<std::string, std::string>& team, int& max_length, std::vector<std::pair<std::string, std::string>>& longest_teams) {
    if (current_length > max_length) {
        max_length = current_length;
        longest_teams.clear();
        longest_teams.push_back(team);
    } else if (current_length == max_length && max_length > 0) {
        longest_teams.push_back(team);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> players(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> players[i];
    }

    GameState state;
    state.white_offense = players[0];
    state.black_offense = players[1];
    state.white_defense = players[2];
    state.black_defense = players[3];
    
    state.white_team = {players[0], players[2]};
    state.black_team = {players[1], players[3]};

    for (int i = 4; i < n; ++i) {
        state.queue.push_back(players[i]);
    }

    std::string scores;
    std::cin >> scores;

    int max_dynasty_length = 0;
    std::vector<std::pair<std::string, std::string>> longest_dynasty_teams;

    int current_dynasty_length = 0;
    char current_dynasty_scorer = '\0';
    
    std::pair<std::string, std::string> last_winning_team;

    for (char scorer : scores) {
        if (scorer != current_dynasty_scorer && current_dynasty_scorer != '\0') {
            update_dynasty(current_dynasty_length, last_winning_team, max_dynasty_length, longest_dynasty_teams);
            current_dynasty_length = 1;
        } else {
            current_dynasty_length++;
        }
        current_dynasty_scorer = scorer;

        if (scorer == 'W') {
            last_winning_team = state.white_team;
            std::swap(state.white_offense, state.white_defense);

            state.queue.push_back(state.black_defense);
            state.black_defense = state.black_offense;
            state.black_offense = state.queue.front();
            state.queue.pop_front();
            state.black_team = {state.black_defense, state.black_offense};
        } else {
            last_winning_team = state.black_team;
            std::swap(state.black_offense, state.black_defense);

            state.queue.push_back(state.white_defense);
            state.white_defense = state.white_offense;
            state.white_offense = state.queue.front();
            state.queue.pop_front();
            state.white_team = {state.white_defense, state.white_offense};
        }
    }
    
    update_dynasty(current_dynasty_length, last_winning_team, max_dynasty_length, longest_dynasty_teams);

    for (const auto& team : longest_dynasty_teams) {
        std::cout << team.first << " " << team.second << "\n";
    }

    return 0;
}