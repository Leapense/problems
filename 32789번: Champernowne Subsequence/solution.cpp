#include <bits/stdc++.h>
using namespace std;

long long minimal_k(const string &target)
{
    size_t need = target.size(), pos = 0;
    long long k = 0;
    while (pos < need)
    {
        ++k;
        string s = to_string(k);
        for (char c : s)
        {
            if (c == target[pos])
            {
                ++pos;
                if (pos == need)
                    break;
            }
        }
    }

    return k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    string t;
    cin >> t;
    cout << minimal_k(t) << "\n";

    return 0;
}