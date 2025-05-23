#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> find_intersections(const string& w1, const string& w2) {
    vector<pair<int, int>> intersections;
    for (int i = 0; i < w1.size(); ++i) {
        for (int j = 0; j < w2.size(); ++j) {
            if (w1[i] == w2[j]) {
                intersections.emplace_back(i + 1, j + 1);
            }
        }
    }

    return intersections;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> words(3);
    for (int i = 0; i < 3; ++i) {
        cin >> words[i];
    }

    for (int central = 0; central < 3; ++central) {
        int other1 = (central + 1) % 3;
        int other2 = (central + 2) % 3;

        vector<pair<int, int>> inter1 = find_intersections(words[central], words[other1]);

        for (auto &[i, j] : inter1) {
            vector<pair<int, int>> inter2 = find_intersections(words[central], words[other2]);
            for (auto &[k, l] : inter2) {
                if (k != i) {
                    cout << words[central] << " " << i << " " << words[other1] << " " << j << "\n";
                    cout << words[central] << " " << k << " " << words[other2] << " " << l << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}