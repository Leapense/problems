#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    string s;
    cin >> s;
    
    int n = (int)s.size();
    if (k >= n) {
        cout << s << "\n";
        return 0;
    }
    
    int freq[26] = {0};
    for (int i = 0; i < k; i++)
        freq[s[i] - 'a']++;
    
    for (int i = 0; i < k; i++)
        cout << s[i];
    
    for (int i = k; i < n; i++) {
        int maxFreq = -1;
        int shiftChar = 0;
        for (int c = 0; c < 26; c++) {
            if (freq[c] > maxFreq) {
                maxFreq = freq[c];
                shiftChar = c;
            }
        }
        
        int shift = shiftChar + 1;
        int cur = s[i] - 'a';
        cur = (cur + shift) % 26;
        char shifted = (char)(cur + 'a');
        cout << shifted;
        
        freq[s[i - k] - 'a']--;
        freq[s[i] - 'a']++;
    }
    
    cout << "\n";
    return 0;
}