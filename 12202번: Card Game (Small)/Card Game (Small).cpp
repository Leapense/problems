#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // Number of test cases

    for(int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;          // Number of cards and the chosen K
        vector<long long> cards(N);
        for(int i = 0; i < N; i++) {
            cin >> cards[i];
        }

        // Keep discarding triples until no more can be discarded
        bool discarded = true;
        while(discarded) {
            discarded = false;
            // We'll scan from left to right looking for valid triples
            for(int i = 0; i + 2 < (int)cards.size(); i++) {
                long long a = cards[i], b = cards[i + 1], c = cards[i + 2];
                if((b - a == K) && (c - b == K)) {
                    // Erase these three cards
                    cards.erase(cards.begin() + i, cards.begin() + i + 3);
                    discarded = true;
                    break;  // Restart scanning from the left
                }
            }
        }

        // The number of cards left
        cout << "Case #" << t << ": " << cards.size() << "\n";
    }

    return 0;
}