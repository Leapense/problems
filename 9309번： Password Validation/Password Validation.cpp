#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<string> forbidden = {"password", "virginia", "cavalier", "code"};

    while(N--) {
        string s;
        cin >> s;
        bool valid = true;

        if (s.length() < 9 || s.length() > 20) {valid = false;}
        int lower = 0, upper = 0, digit = 0, special = 0;
        string alphanum = "";
        string special_chars = "!@#$%^&*.,;/?";
        for (char c : s) {
            if (islower(c)) lower++;
            if (isupper(c)) upper++;
            if (isdigit(c)) digit++;
            if (special_chars.find(c) != string::npos) {special++;}
            if (isalnum(c)) alphanum += tolower(c);
        }

        if (lower < 2 || upper < 2 || digit < 1 || special < 2) {valid = false;}
        for (int i = 2; i < s.length(); i++) if (s[i] == s[i - 1] && s[i] == s[i - 2]) {valid = false; break;}
        string reversed_alphanum = alphanum;
        reverse(reversed_alphanum.begin(), reversed_alphanum.end());

        if (alphanum == reversed_alphanum) {valid = false;}
        string al = alphanum;
        string ra = reversed_alphanum;

        for (auto &word : forbidden) {
            if (al.find(word) != string::npos || ra.find(word) != string::npos) {
                valid = false;
                break;
            }
        }
        cout << (valid ? "Valid Password" : "Invalid Password") << "\n";
    }

    return 0;
}