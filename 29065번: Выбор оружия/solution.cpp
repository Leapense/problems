#include <bits/stdc++.h>
using namespace std;

string Solve(istream &cin)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m))
        return "";
    vector<int> a(n), b(n), idx(n);
    long long base = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        base += b[i];
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](int i, int j)
         { return a[i] - b[i] > a[j] - b[j]; });
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + (a[idx[i]] - b[idx[i]]);
    long long best = LLONG_MIN;
    int bestk = 0;
    for (int k = 0; k <= n; ++k)
        if (abs(2 * k - n) <= m && base + pref[k] > best)
        {
            best = base + pref[k];
            bestk = k;
        }
    vector<int> ans(n, 1);
    for (int i = 0; i < bestk; ++i)
        ans[idx[i]] = 0;
    ostringstream out;
    out << best << '\n';
    for (int i = 0; i < n; ++i)
        out << ans[i] << (i + 1 == n ? '\n' : ' ');
    return out.str();
}

#ifndef UNIT_TEST
int main() { cout << Solve(cin); }
#endif