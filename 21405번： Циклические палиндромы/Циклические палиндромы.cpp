#pragma GCC optimize ("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& s) {
    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }

    return true;
}

bool isCyclicPalindrome(const string& s) {
    int n = s.length();
    string doubled = s + s;

    for (int i = 0; i < n; ++i) {
        string cyclicShift = doubled.substr(i, n);

        if (isPalindrome(cyclicShift)) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string s;
    cin >> s;

    cout << (isCyclicPalindrome(s) ? "yes" : "no") << endl;

    return 0;
}