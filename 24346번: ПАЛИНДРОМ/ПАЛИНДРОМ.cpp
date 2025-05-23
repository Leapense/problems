#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    string s;
    cin >> s;

    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    int odd_count = 0;
    for (auto &entry : freq) {
        if (entry.second % 2 != 0) {
            odd_count++;
        }
    }

    int result = max(1, odd_count);

    cout << result << endl;

    return 0;
}