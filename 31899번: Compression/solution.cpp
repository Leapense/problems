#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;

    string res;
    res.reserve(s.size());
    for (char c : s) {
        res.push_back(c);
        while (true) {
            int n = (int)res.size();
            if (n >= 2 && res[n - 1] == res[n - 2]) {
                res.pop_back();
                continue;
            }
            if (n >= 4 && res[n - 4] == res[n - 2] && res[n - 3] == res[n - 1]) {
                res.pop_back();
                res.pop_back();
                continue;
            }
            break;
        }
    }

    cout << res << '\n';
    return 0;
}