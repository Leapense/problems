#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    int maxFreq = n / 2;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i]) j++;
        int len = j - i + 1;
        for (int k = i + 2; k <= j; k += 3) {
            freq[s[k] - 'a']--;
            char c_new = 'a';
            while ((c_new == s[k - 1] || (k + 1 < n && c_new == s[k + 1])) || freq[c_new - 'a'] >= maxFreq) c_new++;
            s[k] = c_new;
            freq[c_new - 'a']++;
        }
        i = j + 1;
    }
    for (int c = 0; c < 26; ++c) {
        while (freq[c] > maxFreq) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'a' + c) {
                    char prev = (i > 0) ? s[i - 1] : '\0';
                    char next = (i + 1 < n) ? s[i + 1] : '\0';
                    char c_new = 'a';
                    while ((c_new == prev || c_new == next || c_new == s[i]) || freq[c_new - 'a'] >= maxFreq) {
                        c_new++;
                        if (c_new > 'z') break;
                    }
                    if (c_new > 'z') continue;
                    freq[c]--;
                    s[i] = c_new;
                    freq[c_new - 'a']++;
                    break;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}