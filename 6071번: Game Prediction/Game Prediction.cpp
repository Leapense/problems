#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    int caseNumber = 1;

    while (cin >> m >> n) {
        if (m == 0 && n == 0)
            break;

        vector<int> ourCards(n);
        for (int i = 0; i < n; ++i) {
            cin >> ourCards[i];
        }

        // Read the blank line between test cases
        string dummy;
        getline(cin, dummy); // Consume the rest of the line after n cards
        getline(cin, dummy); // Consume the blank line

        int totalCards = n * m;
        vector<int> allCards(totalCards);
        for (int i = 1; i <= totalCards; ++i) {
            allCards[i - 1] = i;
        }

        // Remove our cards from all cards to get opponents' cards
        set<int> opponentsCards(allCards.begin(), allCards.end());
        for (int card : ourCards) {
            opponentsCards.erase(card);
        }

        // Sort our cards in ascending order
        sort(ourCards.begin(), ourCards.end());

        // Initialize wins to n
        int wins = n;

        // For each of our cards from largest to smallest
        for (int i = n - 1; i >= 0; --i) {
            int ourCard = ourCards[i];
            // Find the smallest opponent's card that is higher than ours
            auto it = opponentsCards.upper_bound(ourCard);
            if (it != opponentsCards.end()) {
                // Opponent can beat our card
                opponentsCards.erase(it);
                wins--;
            }
        }

        cout << "Case " << caseNumber << ": " << wins << endl;
        caseNumber++;
    }

    return 0;
}