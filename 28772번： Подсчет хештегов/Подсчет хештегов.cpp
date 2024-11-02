#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    string text;
    getline(cin, text);

    unordered_map<string, int> hashtag_counts;
    string word;
    istringstream iss(text);

    while (iss >> word) {
        if (word.length() >= 2 && word[0] == '#') {
            bool is_hashtag = true;

            for (size_t i = 1; i < word.length(); ++i) {
                if (word[i] == '#') {
                    is_hashtag = false;
                    break;
                }
            }

            if (is_hashtag) {
                ++hashtag_counts[word];
            }
        }
    }

    cout << hashtag_counts.size() << '\n';

    for (const auto& pair : hashtag_counts) {
        cout << pair.first << ' ' << pair.second << '\n';
    }

    return 0;
}