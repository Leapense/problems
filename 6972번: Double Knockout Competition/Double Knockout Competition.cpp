#include <iostream>

using namespace std;

int main() {
    int n; // number of test cases
    cin >> n;
    while (n--) {
        int t;
        cin >> t;

        int round = 0;
        int num_rounds_played = 0; // To count the rounds excluding Round 0
        int num_undefeated = t;
        int num_one_loss = 0;
        int num_eliminated = 0;

        cout << "Round " << round << ": " << num_undefeated << " undefeated, "
             << num_one_loss << " one-loss, " << num_eliminated << " eliminated\n";

        while (num_undefeated + num_one_loss > 1) {
            round++;

            // Special case: one undefeated and one one-loss team remaining
            if (num_undefeated + num_one_loss == 2 && num_undefeated == 1 && num_one_loss == 1) {
                // Undefeated team loses, becomes one-loss
                num_undefeated = 0;
                num_one_loss = 2;
            } else {
                // Simulate matches among undefeated teams
                int num_undefeated_matches = num_undefeated / 2;
                int num_undefeated_byes = num_undefeated % 2;
                int num_undefeated_winners = num_undefeated_byes + num_undefeated_matches;
                int num_undefeated_losers = num_undefeated_matches;

                // Simulate matches among one-loss teams
                int num_one_loss_matches = num_one_loss / 2;
                int num_one_loss_byes = num_one_loss % 2;
                int num_one_loss_winners = num_one_loss_byes + num_one_loss_matches;
                int num_one_loss_losers = num_one_loss_matches;

                num_eliminated += num_one_loss_losers;

                // Update counts
                num_undefeated = num_undefeated_winners;
                num_one_loss = num_one_loss_winners + num_undefeated_losers;
            }

            cout << "Round " << round << ": " << num_undefeated << " undefeated, "
                 << num_one_loss << " one-loss, " << num_eliminated << " eliminated\n";
            num_rounds_played++; // Increment rounds played excluding Round 0
        }

        cout << "There are " << num_rounds_played << " rounds\n";

        if (n) {
            cout << endl; // Separate outputs for different test cases
        }
    }

    return 0;
}
