#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    
    while (cin >> n >> k, n != 0) {
        // Initialize win and loss counts for each player
        vector<int> wins(n + 1, 0);
        vector<int> losses(n + 1, 0);
        string move1, move2;
        int player1, player2;

        // Each player plays k games with every other player
        for (int i = 0; i < k * n * (n - 1) / 2; ++i) {
            cin >> player1 >> move1 >> player2 >> move2;

            // Determine the outcome of the game
            if (move1 == move2) {
                // Draw, do nothing
                continue;
            }

            if ((move1 == "rock" && move2 == "scissors") || 
                (move1 == "scissors" && move2 == "paper") || 
                (move1 == "paper" && move2 == "rock")) {
                // player1 wins
                wins[player1]++;
                losses[player2]++;
            } else {
                // player2 wins
                wins[player2]++;
                losses[player1]++;
            }
        }

        // Calculate and print win averages
        for (int i = 1; i <= n; ++i) {
            int w = wins[i];
            int l = losses[i];
            if (w + l == 0) {
                cout << "-" << endl; // Undefined average
            } else {
                double average = static_cast<double>(w) / (w + l);
                cout << fixed << setprecision(3) << average << endl;
            }
        }
        cout << endl; // Blank line between test cases
    }
    
    return 0;
}
