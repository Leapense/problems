#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();
    int max_freq = n / 2;
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (int i = 0; i < n; i++) {
        bool need_replace = false;
        if (freq[s[i] - 'a'] > max_freq) {
            need_replace = true;
        }
        if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2]) {
            need_replace = true;
        }

        if (need_replace) {
            for (char d = 'a'; d <= 'z'; d++) {
                if (d != s[i - 1] && (i < 2 || d != s[i - 2]) && freq[d - 'a'] < max_freq) {
                    freq[s[i] - 'a']--;
                    freq[d - 'a']++;
                    s[i] = d;
                    break;
                }
            }
        }
    }

    cout << s << "\n";

    return 0;
}