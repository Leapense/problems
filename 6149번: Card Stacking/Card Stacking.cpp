#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, P;
    cin >> N >> K >> P;

    vector<int> good_cards;
    queue<int> deck;
    for (int i = 1; i <= K; ++i) {
        deck.push(i);
    }

    int dealt = 0;
    while (good_cards.size() < K / N) {
        int player = dealt % N;
        if (player == N - 1) {
            good_cards.push_back(deck.front());
        }
        deck.pop();
        dealt++;
        for (int i = 0; i < P; ++i) {
            deck.push(deck.front());
            deck.pop();
        }
    }

    sort(good_cards.begin(), good_cards.end());
    for (int card : good_cards) {
        cout << card << "\n";
    }

    return 0;
}