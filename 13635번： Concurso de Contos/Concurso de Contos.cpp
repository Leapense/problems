#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, C;

    while (cin >> N >> L >> C) {
        vector<string> words(N);

        for (auto &s : words) cin >> s;

        int lines = 1;
        int current_line_length = 0;

        for (auto &word : words) {
            if (current_line_length == 0) {
                current_line_length = word.length();
            } else {
                if (current_line_length + 1 + word.length() <= C) {
                    current_line_length += 1 + word.length();
                } else {
                    lines++;
                    current_line_length = word.length();
                }
            }
        }

        int pages = (lines + L - 1) / L;
        cout << pages << "\n";
    }

    return 0;
}