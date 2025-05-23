#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;

    vector<int> responses(D);

    string temp;

    for (int i = 0; i < D; ++i) {
        cin >> temp;
        if (temp == "first") responses[i] = 0;
        else if (temp == "second") responses[i] = 1;
        else if (temp == "third") responses[i] = 2;
    }

    vector<int> deck(N);

    for (int i = 0; i < N; ++i) {
        deck[i] = i + 1;
    }

    set<int> possible_numbers;

    for (int i = 1; i <= N; ++i) {
        possible_numbers.insert(i);
    }

    int K = N / 3;
    for (int d = 0; d < D; ++d) {
        vector<vector<int>> table(K, vector<int>(3));
        for (int i = 0; i < N; ++i) {
            int row = i / 3;
            int col = i % 3;
            table[row][col] = deck[i];
        }

        set<int> new_possible_numbers;

        for (int i = 0; i < K; ++i) {
            int card = table[i][responses[d]];
            if (possible_numbers.count(card)) {
                new_possible_numbers.insert(card);
            }
        }

        possible_numbers = new_possible_numbers;

        vector<int> new_deck;

        for (int col = 0; col < 3; ++col) {
            for (int row = 0; row < K; ++row) {
                new_deck.push_back(table[row][col]);
            }
        }
        deck = new_deck;
    }

    for (auto it = possible_numbers.begin(); it != possible_numbers.end(); ++it) {
        if (it != possible_numbers.begin()) cout << " ";
        cout << *it;
    }

    cout << endl;

    return 0;
}