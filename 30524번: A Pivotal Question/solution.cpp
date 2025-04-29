// solution.cpp
#include <bits/stdc++.h>
using namespace std;

void solve(istream &in, ostream &out)
{
    int n;
    in >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        in >> a[i];
    }

    const int INF = numeric_limits<int>::max();
    vector<int> suffix_min(n + 1, INF);
    for (int i = n - 1; i >= 0; i--)
    {
        suffix_min[i] = min(a[i], suffix_min[i + 1]);
    }

    long long total = 0;  // count _all_ pivots
    vector<int> first100; // store only the first 100
    first100.reserve(100);

    int cur_max = 0;
    for (int i = 0; i < n; i++)
    {
        cur_max = max(cur_max, a[i]);
        if (a[i] == cur_max && suffix_min[i + 1] > a[i])
        {
            total++;
            if ((int)first100.size() < 100)
            {
                first100.push_back(a[i]);
            }
        }
    }

    if (total == 0)
    {
        out << 0 << "\n";
    }
    else
    {
        out << total;
        for (int v : first100)
        {
            out << ' ' << v;
        }
        out << "\n";
    }
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(cin, cout);
    return 0;
}
#endif
