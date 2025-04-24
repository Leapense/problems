#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    string s, t;

    cin >> k >> s >> t;

    int n = s.size(), m = t.size();

    if (n < k || m < k) {
        cout << "NO";
        return 0;
    }

    array<int, 26> ft{}, fw{};
    for (char c : t) ft[c - 'a']++;
    for (int i = 0; i < k; i++) fw[s[i] - 'a']++;
    auto ok = [&]() {
        for (int i = 0; i < 26; i++) {
            if (fw[i] > ft[i]) return false;
        }

        return true;
    };

    if (ok()) {
        cout << "YES";
        return 0;
    }

    for (int i = k; i < n; i++) 
    {
        fw[s[i - k] - 'a']--;
        fw[s[i] - 'a']++;
        if (ok()) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
