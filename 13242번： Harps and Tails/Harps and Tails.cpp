#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> freq;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        freq[s]++;
    }

    int max_freq = 0;
    for (auto &p : freq) {
        if (p.second > max_freq) {
            max_freq = p.second;
        }
    }

    cout << max_freq << endl;

    return 0;
}