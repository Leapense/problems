#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    cin >> k;

    string s;
    cin >> s;

    string encrypted_s = "";

    for (int i = 0; i < min((int)s.length(), k); ++i) {
        encrypted_s += s[i];
    }

    for (int i = k; i < s.length(); ++i) {
        vector<int> counts(26,0);

        for (int j = i - k; j < i; ++j) {
            counts[s[j] - 'a']++;
        }

        int max_count = 0;

        char most_frequent = ' ';

        for (int j = 0; j < 26; ++j) {
            if (counts[j] > max_count) {
                max_count = counts[j];
                most_frequent = (char)('a' + j);
            }
        }

        encrypted_s += (char)('a' + (s[i] - 'a' + (most_frequent - 'a' + 1)) % 26);
    }

    cout << encrypted_s << "\n";

    return 0;
}