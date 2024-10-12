#include <bits/stdc++.h>
using namespace std;

int calculateScore(string throw_specifier) {
    if (throw_specifier == "OB") return 25;
    if (throw_specifier == "B") return 50;
    if (throw_specifier == "M") return 0;

    char type = throw_specifier[0];
    int score = stoi(throw_specifier.substr(1));
    
    if (type == 'S') return score;
    if (type == 'D') return 2 * score;
    if (type == 'T') return 3 * score;
    return 0;
}

bool isDouble(string throw_specifier) {
    if (throw_specifier == "B") return true;
    return throw_specifier[0] == 'D';
}

void simulateGame(vector<string> throws) {
    int player_scores[2] = {301, 301};
    bool can_score[2] = {false, false};
    int player = 0; // Player 1 starts
    int start_score, throw_score;
    vector<int> round_scores = {301, 301};

    for (string throw_specifier : throws) {
        start_score = player_scores[player];
        throw_score = calculateScore(throw_specifier);

        if (!can_score[player] && isDouble(throw_specifier)) {
            can_score[player] = true; // Player starts scoring
        }
        
        if (can_score[player]) {
            player_scores[player] -= throw_score;
            
            if (player_scores[player] == 0 && isDouble(throw_specifier)) {
                cout << "   " << round_scores[0] << "   " << round_scores[1] << "\n";
                cout << " Wins" << (player == 0 ? "   " : "") << right << setw(5) << player_scores[1 - player] << "\n";
                return;
            } else if (player_scores[player] < 2) {
                player_scores[player] = start_score; // Reset score for this round
                cout << "   " << round_scores[0] << "   " << round_scores[1] << "\n";
                round_scores[player] = start_score;
                player = 1 - player; // Switch player
                continue;
            }
        }
        
        if (throw_specifier.back() == ',') {
            player = 1 - player; // Switch player after each set of 10 throws
            if (player == 0) {
                cout << "   " << round_scores[0] << "   " << round_scores[1] << "\n";
                round_scores[0] = player_scores[0];
                round_scores[1] = player_scores[1];
            }
        }
    }
}

int main() {
    string line;
    int game_number = 1;
    vector<string> throws;
    
    while (getline(cin, line) && line != "#") {
        if (line.back() == '#') {
            line.pop_back(); // Remove trailing hash
            simulateGame(throws);
            throws.clear();
            cout << "\nGame " << game_number++ << "\n";
            cout << "  301  301\n";
        } else {
            istringstream iss(line);
            string throw_specifier;
            while (getline(iss, throw_specifier, ',')) {
                if (!throw_specifier.empty()) throws.push_back(throw_specifier);
            }
        }
    }
    return 0;
}
