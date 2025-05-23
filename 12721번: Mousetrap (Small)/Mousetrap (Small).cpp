#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> buildPerfectDeck(int K) {
    vector<int> deck(K, 0);
    queue<int> q;

    for (int i = 1; i <= K; ++i) {
        q.push(i);
    }

    int count = 1;
    while (!q.empty()) {
        for (int i = 1; i < count; ++i) {
            q.push(q.front());
            q.pop();
        }

        deck[q.front() - 1] = count;
        q.pop();
        count++;
    }

    return deck;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int K;
        cin >> K;

        int n;
        cin >> n;

        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            cin >> indices[i];
        }

        vector<int> deck = buildPerfectDeck(K);

        cout << "Case #" << t << ":";
        for (int i = 0; i < n; ++i) {
            cout << " " << deck[indices[i] - 1];
        }

        cout << endl;
    }

    return 0;
}