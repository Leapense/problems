#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> solve(const vector<long long> &h, const vector<long long> &a)
{
    int n = h.size();
    vector<pair<long long, long long>> v(n);

    for (int i = 0; i < n; i++)
        v[i] = {h[i], a[i]};
    sort(v.begin(), v.end());

    long long total = 0;
    for (auto &p : v)
        total += p.second;

    long long half = (total + 1) / 2;
    long long sum = 0;
    long long H = v[0].first;
    for (auto &p : v)
    {
        sum += p.second;
        if (sum >= half)
        {
            H = p.first;
            break;
        }
    }

    long long cost = 0;
    for (auto &p : v)
        cost += llabs(p.first - H) * p.second;
    return {H, cost};
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    if (!(cin >> n))
        return 0;

    vector<long long> h(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto [H, cost] = solve(h, a);
    cout << H << " " << cost;
    return 0;
}
#endif