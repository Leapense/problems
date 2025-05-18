#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> get_possible_key_lengths(const string& cipher) {
    unordered_map<string, vector<int>> pos_map;
    int n = cipher.size();

    for (int i = 0; i <= n - 3; ++i) {
        string sub = cipher.substr(i, 3);
        pos_map[sub].push_back(i);
    }

    vector<int> distances;

    for (const auto& [triplet, vec] : pos_map) {
        int sz = vec.size();
        if (sz > 1) {
            for (int i = 0; i < sz; ++i) {
                for (int j = i + 1; j < sz; ++j) {
                    distances.push_back(vec[j] - vec[i]);
                }
            }
        }
    }

    if (distances.empty()) return {};

    vector<int> result;
    int total = distances.size();
    for (int k = 4; k <= 20; ++k) {
        int cnt = 0;
        for (int d : distances)
            if (d % k == 0) ++cnt;
        if (cnt * 10 >= 9 * total) {
            result.push_back(k);
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    cin.ignore();
    while (T--) {
        string s;
        getline(cin, s);
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return c == ' '; }), s.end());
        auto ans = get_possible_key_lengths(s);
        if (ans.empty()) {
            cout << "No guesses found.\n";
        } else {
            cout << "Possible key lengths between 4 and 20:";
            for (int k : ans) cout << " " << k;
            cout << "\n";
        }
    }

    return 0;
}