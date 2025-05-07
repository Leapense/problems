#include <bits/stdc++.h>
using namespace std;

bool canTransform(const string &s, const string &t)
{
    size_t n = s.size(), m = t.size();
    if (m > n)
        return false;
    if (m == 1)
        return s.find(t[0]) != string::npos;

    for (int k = 0; (1u << k) <= n; ++k)
    {
        size_t step = 1u << k;
        for (size_t p = 0; p < step && p < n; ++p)
        {
            size_t len = (n - 1 - p) / step + 1;
            if (len != m)
                continue;
            bool ok = true;
            for (size_t j = 0, idx = p; j < m; ++j, idx += step)
                if (s[idx] != t[j])
                {
                    ok = false;
                    break;
                }
            if (ok)
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s, t;
        cin >> s >> t;
        cout << (canTransform(s, t) ? "YES\n" : "NO\n");
    }
    return 0;
}