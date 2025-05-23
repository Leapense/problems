#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int N;
    cin >> N;
    string clues;
    cin >> clues;

    unordered_map<char, int> required = {
        {'R', 1},
        {'A', 2},
        {'K', 1},
        {'T', 1},
        {'S', 1}
    };

    unordered_map<char, int> current;

    for (int i = 0; i < N; i++) {
        char c = clues[i];
        if (required.find(c) != required.end()) {
            current[c]++;
        }

        bool ok = true;

        for (auto &pair : required) {
            if (current[pair.first] < pair.second) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    return 0;
}