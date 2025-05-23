#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> freq;
    string line;

    while (getline(cin, line)) {
        for (char c : line) {
            if (c != ' ' && c != '\n' && c != '\r') {
                freq[c]++;
            }
        }
    }

    int maxFreq = 0;

    for (const auto& p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
        }
    }

    vector<string> histogram(maxFreq + 1, "");

    for (const auto& p : freq) {
        for (int i = 0; i < maxFreq; i++) {
            if (i < p.second) {
                histogram[i].push_back('#');
            } else {
                histogram[i].push_back(' ');
            }
        }
        histogram[maxFreq].push_back(p.first);
    }

    for (int row = maxFreq - 1; row >= 0; --row) {
        cout << histogram[row] << "\n";
    }
    cout << histogram[maxFreq] << "\n";

    return 0;
}