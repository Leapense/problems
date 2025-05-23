#pragma GCC optimize("O3")
#define FAST_IO cin.tie(0) -> sync_with_stdio(0); cin.exceptions(ios::badbit | ios::failbit);

#include <bits/stdc++.h>

using namespace std;

int main()
{
    FAST_IO;
    string c, s;
    cin >> c >> s;

    int m = c.length();
    int n = s.length();

    int t_pos = 1;

    for (int s_pos = 0; s_pos < n; ++s_pos) {
        if (s[s_pos] == c[(t_pos - 1) % m]) {
            ++t_pos;
        }
    }

    int total_matched = t_pos - 1;
    int k = total_matched / m;
    cout << k << endl;

    return 0;
}